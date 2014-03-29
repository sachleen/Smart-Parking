#include "Sleep_n0m1.h"

Sleep* Sleep::pSleep = 0; 

Sleep::Sleep()
{
	pSleep = this;	//the ptr points to this object
	timeSleep = 0;  // total time due to sleep
	calibv = 1.0; // ratio of real clock with WDT clock
	byte isrcalled = 0;  // WDT vector flag
	sleepCycleCount = 0;
	sleepCycleInterval = 100; 

}

/********************************************************************
*
*	setSleepMode
*
********************************************************************/
void Sleep::setSleepMode(int mode)
{
  sleepMode_ = mode;
}


/********************************************************************
*
*	calibrateTime
*
********************************************************************/
void Sleep::calibrateTime(unsigned long sleepTime, boolean &abortCycle) {
  // timer0 continues to run in idle sleep mode
  set_sleep_mode(SLEEP_MODE_IDLE);
  long tt1=millis();
  sleepWDT(sleepTime,abortCycle);
  long tt2=millis();

  calibv = (float) sleepTime/(tt2-tt1);
  
  //Serial.println(calibv);
}

/********************************************************************
*
*	WDTMillis
*
********************************************************************/
unsigned long Sleep::WDTMillis() {
  return millis()+timeSleep;
}

/********************************************************************
*
*	sleepNow
*
********************************************************************/
void Sleep::sleepInterrupt(int interrupt,int mode) {

	if(mode == FALLING || mode == LOW)
	{
	   int pin = interrupt + 2; //will fail on the mega	
	   pinMode (pin, INPUT);
	   digitalWrite (pin, HIGH);
	}

	set_sleep_mode(sleepMode_);
	sleep_enable();
	attachInterrupt(interrupt,sleepHandler,mode);
	sei(); //make sure interrupts are on!
	sleep_mode();
	 //----------------------------- ZZZZZZ sleeping here----------------------
	sleep_disable(); //disable sleep, awake now
	detachInterrupt(interrupt);
}


/********************************************************************
*
*	sleepDelay
*
********************************************************************/
void Sleep::sleepDelay(unsigned long sleepTime){

	boolean abortCycle = false; 

	sleepDelay(sleepTime,abortCycle);
}

/********************************************************************
*
*	sleepDelay
*
********************************************************************/
void Sleep::sleepDelay(unsigned long sleepTime, boolean &abortCycle) {
  ADCSRA &= ~(1<<ADEN);  // adc off
    //PRR = 0xEF; // modules off
  
  ++sleepCycleCount;
  sleepCycleCount = sleepCycleCount % sleepCycleInterval; //recalibrate every interval cycles
  if(sleepCycleCount == 1)
  {
	calibrateTime(sleepTime,abortCycle);
  }
  else
  {
  	set_sleep_mode(sleepMode_);
  	int trem = sleepWDT(sleepTime*calibv,abortCycle); 
  	timeSleep += (sleepTime-trem);
  }
   //PRR = 0x00; //modules on
 ADCSRA |= (1<<ADEN);  // adc on
}


/********************************************************************
*
*	sleepWDT
*
********************************************************************/
int Sleep::sleepWDT(unsigned long remainTime, boolean &abortCycle) {
  
   #if defined(WDP3)
 	 byte WDTps = 9;  // WDT Prescaler value, 9 = 8192ms
   #else
 	 byte WDTps = 7;  // WDT Prescaler value, 7 = 2048ms
   #endif	

  isrcalled = 0;
  sleep_enable();
  while(remainTime > 0) {
    //work out next prescale unit to use
    while ((0x10<<WDTps) > remainTime && WDTps > 0) {
      WDTps--;
    }
    // send prescaler mask to WDT_On
    WDT_On((WDTps & 0x08 ? (1<<WDP3) : 0x00) | (WDTps & 0x07));
    isrcalled=0;
    while (isrcalled==0 && abortCycle == false) {
	
	  #if defined(__AVR_ATmega328P__)
      // turn bod off
      MCUCR |= (1<<BODS) | (1<<BODSE);
      MCUCR &= ~(1<<BODSE);  // must be done right before sleep
      #endif
      sleep_cpu();  // sleep here
    }
    // calculate remaining time
    remainTime -= (0x10<<WDTps);
	if ((long) remainTime < 0 ) {remainTime = 0;} //check for unsigned underflow, by converting to signed

  }
  sleep_disable();
  return remainTime;
}


/********************************************************************
*
*	WDT_On
*
********************************************************************/
void Sleep::WDT_On(byte psMask)
{
  // prepare timed sequence first
  byte ps = (psMask | (1<<WDIE)) & ~(1<<WDE);
  cli();
  wdt_reset();
  /* Clear WDRF in MCUSR */
  MCUSR &= ~(1<<WDRF);
  // start timed sequence
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // set new watchdog timeout value
  WDTCSR = ps;
  sei();
}

/********************************************************************
*
*	WDT_Off
*
********************************************************************/
void Sleep::WDT_Off() {
  cli();
  wdt_reset();
  /* Clear WDRF in MCUSR */
  MCUSR &= ~(1<<WDRF);
  /* Write logical one to WDCE and WDE */
  /* Keep old prescaler setting to prevent unintentional time-out */
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  /* Turn off WDT */
  WDTCSR = 0x00;
  sei();
}

/********************************************************************
*
*	sleepHandler ISR
*
********************************************************************/
void sleepHandler(void)
{


}

/********************************************************************
*
*	WDT ISR
*
********************************************************************/
ISR(WDT_vect) {
  Sleep::pSleep->WDT_Off();
  Sleep::pSleep->isrcalled=1;
}
