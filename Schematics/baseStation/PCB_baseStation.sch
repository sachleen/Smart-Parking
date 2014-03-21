<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="yes" active="yes"/>
<layer number="103" name="tMap" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="16" fill="1" visible="yes" active="yes"/>
<layer number="105" name="tPlate" color="7" fill="1" visible="yes" active="yes"/>
<layer number="106" name="bPlate" color="7" fill="1" visible="yes" active="yes"/>
<layer number="107" name="Crop" color="7" fill="1" visible="yes" active="yes"/>
<layer number="108" name="tplace-old" color="10" fill="1" visible="yes" active="yes"/>
<layer number="109" name="ref-old" color="11" fill="1" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="199" name="Contour" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="yes" active="yes"/>
<layer number="201" name="201bmp" color="2" fill="10" visible="yes" active="yes"/>
<layer number="202" name="202bmp" color="3" fill="10" visible="yes" active="yes"/>
<layer number="203" name="203bmp" color="4" fill="10" visible="yes" active="yes"/>
<layer number="204" name="204bmp" color="5" fill="10" visible="yes" active="yes"/>
<layer number="205" name="205bmp" color="6" fill="10" visible="yes" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="10" visible="yes" active="yes"/>
<layer number="207" name="207bmp" color="8" fill="10" visible="yes" active="yes"/>
<layer number="208" name="208bmp" color="9" fill="10" visible="yes" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="217" name="217bmp" color="18" fill="1" visible="no" active="no"/>
<layer number="218" name="218bmp" color="19" fill="1" visible="no" active="no"/>
<layer number="219" name="219bmp" color="20" fill="1" visible="no" active="no"/>
<layer number="220" name="220bmp" color="21" fill="1" visible="no" active="no"/>
<layer number="221" name="221bmp" color="22" fill="1" visible="no" active="no"/>
<layer number="222" name="222bmp" color="23" fill="1" visible="no" active="no"/>
<layer number="223" name="223bmp" color="24" fill="1" visible="no" active="no"/>
<layer number="224" name="224bmp" color="25" fill="1" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SparkFun-DigitalIC">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find all manner of digital ICs- microcontrollers, memory chips, logic chips, FPGAs, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; CC v3.0 Share-Alike You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="TQFP32-08">
<description>&lt;B&gt;Thin Plasic Quad Flat Package&lt;/B&gt; Grid 0.8 mm</description>
<wire x1="3.505" y1="3.505" x2="3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="3.505" y1="-3.505" x2="-3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="-3.505" y1="-3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="3.505" y2="3.505" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<circle x="-2.7432" y="2.7432" radius="0.3592" width="0.1524" layer="21"/>
<smd name="1" x="-4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="2" x="-4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="3" x="-4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="4" x="-4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="5" x="-4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="6" x="-4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="7" x="-4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="8" x="-4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="9" x="-2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="10" x="-2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="11" x="-1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="12" x="-0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="13" x="0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="14" x="1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="15" x="2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="16" x="2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="17" x="4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="18" x="4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="19" x="4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="20" x="4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="21" x="4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="22" x="4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="23" x="4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="24" x="4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="25" x="2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="26" x="2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="27" x="1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="28" x="0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="29" x="-0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="30" x="-1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="31" x="-2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="32" x="-2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<text x="-3.175" y="5.08" size="0.4064" layer="25">&gt;NAME</text>
<text x="-2.54" y="-6.35" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-4.5466" y1="2.5714" x2="-3.556" y2="3.0286" layer="51"/>
<rectangle x1="-4.5466" y1="1.7714" x2="-3.556" y2="2.2286" layer="51"/>
<rectangle x1="-4.5466" y1="0.9714" x2="-3.556" y2="1.4286" layer="51"/>
<rectangle x1="-4.5466" y1="0.1714" x2="-3.556" y2="0.6286" layer="51"/>
<rectangle x1="-4.5466" y1="-0.6286" x2="-3.556" y2="-0.1714" layer="51"/>
<rectangle x1="-4.5466" y1="-1.4286" x2="-3.556" y2="-0.9714" layer="51"/>
<rectangle x1="-4.5466" y1="-2.2286" x2="-3.556" y2="-1.7714" layer="51"/>
<rectangle x1="-4.5466" y1="-3.0286" x2="-3.556" y2="-2.5714" layer="51"/>
<rectangle x1="-3.0286" y1="-4.5466" x2="-2.5714" y2="-3.556" layer="51"/>
<rectangle x1="-2.2286" y1="-4.5466" x2="-1.7714" y2="-3.556" layer="51"/>
<rectangle x1="-1.4286" y1="-4.5466" x2="-0.9714" y2="-3.556" layer="51"/>
<rectangle x1="-0.6286" y1="-4.5466" x2="-0.1714" y2="-3.556" layer="51"/>
<rectangle x1="0.1714" y1="-4.5466" x2="0.6286" y2="-3.556" layer="51"/>
<rectangle x1="0.9714" y1="-4.5466" x2="1.4286" y2="-3.556" layer="51"/>
<rectangle x1="1.7714" y1="-4.5466" x2="2.2286" y2="-3.556" layer="51"/>
<rectangle x1="2.5714" y1="-4.5466" x2="3.0286" y2="-3.556" layer="51"/>
<rectangle x1="3.556" y1="-3.0286" x2="4.5466" y2="-2.5714" layer="51"/>
<rectangle x1="3.556" y1="-2.2286" x2="4.5466" y2="-1.7714" layer="51"/>
<rectangle x1="3.556" y1="-1.4286" x2="4.5466" y2="-0.9714" layer="51"/>
<rectangle x1="3.556" y1="-0.6286" x2="4.5466" y2="-0.1714" layer="51"/>
<rectangle x1="3.556" y1="0.1714" x2="4.5466" y2="0.6286" layer="51"/>
<rectangle x1="3.556" y1="0.9714" x2="4.5466" y2="1.4286" layer="51"/>
<rectangle x1="3.556" y1="1.7714" x2="4.5466" y2="2.2286" layer="51"/>
<rectangle x1="3.556" y1="2.5714" x2="4.5466" y2="3.0286" layer="51"/>
<rectangle x1="2.5714" y1="3.556" x2="3.0286" y2="4.5466" layer="51"/>
<rectangle x1="1.7714" y1="3.556" x2="2.2286" y2="4.5466" layer="51"/>
<rectangle x1="0.9714" y1="3.556" x2="1.4286" y2="4.5466" layer="51"/>
<rectangle x1="0.1714" y1="3.556" x2="0.6286" y2="4.5466" layer="51"/>
<rectangle x1="-0.6286" y1="3.556" x2="-0.1714" y2="4.5466" layer="51"/>
<rectangle x1="-1.4286" y1="3.556" x2="-0.9714" y2="4.5466" layer="51"/>
<rectangle x1="-2.2286" y1="3.556" x2="-1.7714" y2="4.5466" layer="51"/>
<rectangle x1="-3.0286" y1="3.556" x2="-2.5714" y2="4.5466" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGAXX8-32PIN">
<description>Symbol for Atmega328/168/88/48 chips, 32-pin version</description>
<wire x1="-17.78" y1="27.94" x2="20.32" y2="27.94" width="0.254" layer="94"/>
<wire x1="20.32" y1="27.94" x2="20.32" y2="-35.56" width="0.254" layer="94"/>
<wire x1="20.32" y1="-35.56" x2="-17.78" y2="-35.56" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-35.56" x2="-17.78" y2="27.94" width="0.254" layer="94"/>
<text x="-17.78" y="-38.1" size="1.778" layer="95">&gt;NAME</text>
<text x="-17.78" y="28.448" size="1.778" layer="96">&gt;VALUE</text>
<pin name="PB5(SCK)" x="25.4" y="-33.02" length="middle" rot="R180"/>
<pin name="PB7(XTAL2/TOSC2)" x="-22.86" y="-5.08" length="middle"/>
<pin name="PB6(XTAL1/TOSC1)" x="-22.86" y="0" length="middle"/>
<pin name="GND@1" x="-22.86" y="-27.94" length="middle"/>
<pin name="GND@2" x="-22.86" y="-30.48" length="middle"/>
<pin name="VCC@1" x="-22.86" y="17.78" length="middle"/>
<pin name="VCC@2" x="-22.86" y="15.24" length="middle"/>
<pin name="AGND" x="-22.86" y="-25.4" length="middle"/>
<pin name="AREF" x="-22.86" y="10.16" length="middle"/>
<pin name="AVCC" x="-22.86" y="20.32" length="middle"/>
<pin name="PB4(MISO)" x="25.4" y="-30.48" length="middle" rot="R180"/>
<pin name="PB3(MOSI/OC2)" x="25.4" y="-27.94" length="middle" rot="R180"/>
<pin name="PB2(SS/OC1B)" x="25.4" y="-25.4" length="middle" rot="R180"/>
<pin name="PB1(OC1A)" x="25.4" y="-22.86" length="middle" rot="R180"/>
<pin name="PB0(ICP)" x="25.4" y="-20.32" length="middle" rot="R180"/>
<pin name="PD7(AIN1)" x="25.4" y="-15.24" length="middle" rot="R180"/>
<pin name="PD6(AIN0)" x="25.4" y="-12.7" length="middle" rot="R180"/>
<pin name="PD5(T1)" x="25.4" y="-10.16" length="middle" rot="R180"/>
<pin name="PD4(XCK/T0)" x="25.4" y="-7.62" length="middle" rot="R180"/>
<pin name="PD3(INT1)" x="25.4" y="-5.08" length="middle" rot="R180"/>
<pin name="PD2(INT0)" x="25.4" y="-2.54" length="middle" rot="R180"/>
<pin name="PD1(TXD)" x="25.4" y="0" length="middle" rot="R180"/>
<pin name="PD0(RXD)" x="25.4" y="2.54" length="middle" rot="R180"/>
<pin name="ADC7" x="25.4" y="7.62" length="middle" rot="R180"/>
<pin name="ADC6" x="25.4" y="10.16" length="middle" rot="R180"/>
<pin name="PC5(ADC5/SCL)" x="25.4" y="12.7" length="middle" rot="R180"/>
<pin name="PC4(ADC4/SDA)" x="25.4" y="15.24" length="middle" rot="R180"/>
<pin name="PC3(ADC3)" x="25.4" y="17.78" length="middle" rot="R180"/>
<pin name="PC2(ADC2)" x="25.4" y="20.32" length="middle" rot="R180"/>
<pin name="PC1(ADC1)" x="25.4" y="22.86" length="middle" rot="R180"/>
<pin name="PC0(ADC0)" x="25.4" y="25.4" length="middle" rot="R180"/>
<pin name="PC6(/RESET)" x="-22.86" y="25.4" length="middle" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA328_SMT" prefix="U" uservalue="yes">
<description>32-Pin Atmega328 part&lt;BR&gt;
Commonly used on Arduino compatible boards&lt;br&gt;
Available in QFP and QFN packages&lt;br&gt;
TQFP is IC-09069
QFN is non-stock</description>
<gates>
<gate name="G$1" symbol="ATMEGAXX8-32PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TQFP32-08">
<connects>
<connect gate="G$1" pin="ADC6" pad="19"/>
<connect gate="G$1" pin="ADC7" pad="22"/>
<connect gate="G$1" pin="AGND" pad="21"/>
<connect gate="G$1" pin="AREF" pad="20"/>
<connect gate="G$1" pin="AVCC" pad="18"/>
<connect gate="G$1" pin="GND@1" pad="3"/>
<connect gate="G$1" pin="GND@2" pad="5"/>
<connect gate="G$1" pin="PB0(ICP)" pad="12"/>
<connect gate="G$1" pin="PB1(OC1A)" pad="13"/>
<connect gate="G$1" pin="PB2(SS/OC1B)" pad="14"/>
<connect gate="G$1" pin="PB3(MOSI/OC2)" pad="15"/>
<connect gate="G$1" pin="PB4(MISO)" pad="16"/>
<connect gate="G$1" pin="PB5(SCK)" pad="17"/>
<connect gate="G$1" pin="PB6(XTAL1/TOSC1)" pad="7"/>
<connect gate="G$1" pin="PB7(XTAL2/TOSC2)" pad="8"/>
<connect gate="G$1" pin="PC0(ADC0)" pad="23"/>
<connect gate="G$1" pin="PC1(ADC1)" pad="24"/>
<connect gate="G$1" pin="PC2(ADC2)" pad="25"/>
<connect gate="G$1" pin="PC3(ADC3)" pad="26"/>
<connect gate="G$1" pin="PC4(ADC4/SDA)" pad="27"/>
<connect gate="G$1" pin="PC5(ADC5/SCL)" pad="28"/>
<connect gate="G$1" pin="PC6(/RESET)" pad="29"/>
<connect gate="G$1" pin="PD0(RXD)" pad="30"/>
<connect gate="G$1" pin="PD1(TXD)" pad="31"/>
<connect gate="G$1" pin="PD2(INT0)" pad="32"/>
<connect gate="G$1" pin="PD3(INT1)" pad="1"/>
<connect gate="G$1" pin="PD4(XCK/T0)" pad="2"/>
<connect gate="G$1" pin="PD5(T1)" pad="9"/>
<connect gate="G$1" pin="PD6(AIN0)" pad="10"/>
<connect gate="G$1" pin="PD7(AIN1)" pad="11"/>
<connect gate="G$1" pin="VCC@1" pad="4"/>
<connect gate="G$1" pin="VCC@2" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="IC-09069" constant="no"/>
<attribute name="VALUE" value="ATMEGA328P" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-RF">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find things that send or receive RF- GPS, cellular modules, Bluetooth, WiFi, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; CC v3.0 Share-Alike You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="XBEE-1">
<wire x1="-5" y1="27.6" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="21.25" x2="-5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="12.25" y1="21.25" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="9.75" y1="21.25" x2="12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="12.25" y1="21.25" x2="12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="9.75" y1="21.25" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="21.25" x2="-12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="12.25" y1="0.75" x2="12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="12.25" y1="0" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="-12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="-6.25" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<pad name="10" x="-11" y="2" drill="0.8" diameter="1.524"/>
<pad name="9" x="-11" y="4" drill="0.8" diameter="1.524"/>
<pad name="8" x="-11" y="6" drill="0.8" diameter="1.524"/>
<pad name="7" x="-11" y="8" drill="0.8" diameter="1.524"/>
<pad name="6" x="-11" y="10" drill="0.8" diameter="1.524"/>
<pad name="5" x="-11" y="12" drill="0.8" diameter="1.524"/>
<pad name="4" x="-11" y="14" drill="0.8" diameter="1.524"/>
<pad name="3" x="-11" y="16" drill="0.8" diameter="1.524"/>
<pad name="2" x="-11" y="18" drill="0.8" diameter="1.524"/>
<pad name="1" x="-11" y="20" drill="0.8" diameter="1.524"/>
<pad name="11" x="11" y="2" drill="0.8" diameter="1.524"/>
<pad name="12" x="11" y="4" drill="0.8" diameter="1.524"/>
<pad name="13" x="11" y="6" drill="0.8" diameter="1.524"/>
<pad name="14" x="11" y="8" drill="0.8" diameter="1.524"/>
<pad name="15" x="11" y="10" drill="0.8" diameter="1.524"/>
<pad name="16" x="11" y="12" drill="0.8" diameter="1.524"/>
<pad name="17" x="11" y="14" drill="0.8" diameter="1.524"/>
<pad name="18" x="11" y="16" drill="0.8" diameter="1.524"/>
<pad name="19" x="11" y="18" drill="0.8" diameter="1.524"/>
<pad name="20" x="11" y="20" drill="0.8" diameter="1.524"/>
<text x="-8.89" y="2.54" size="0.4064" layer="25">&gt;Name</text>
<text x="-8.89" y="1.27" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="XBEE-SILK">
<wire x1="-5" y1="27.6" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="21.25" x2="-5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="12.25" y1="21.25" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="9.75" y1="21.25" x2="12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="12.25" y1="21.25" x2="12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="9.75" y1="21.25" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="21.25" x2="-12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0" x2="12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="-12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="-6.25" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-5" y1="27.6" x2="-5.7" y2="27" width="0.2032" layer="21"/>
<wire x1="-5" y1="27.6" x2="5" y2="27.6" width="0.2032" layer="21"/>
<wire x1="5" y1="27.6" x2="5.7" y2="27" width="0.2032" layer="21"/>
<pad name="10" x="-11" y="2" drill="0.8" diameter="1.524"/>
<pad name="9" x="-11" y="4" drill="0.8" diameter="1.524"/>
<pad name="8" x="-11" y="6" drill="0.8" diameter="1.524"/>
<pad name="7" x="-11" y="8" drill="0.8" diameter="1.524"/>
<pad name="6" x="-11" y="10" drill="0.8" diameter="1.524"/>
<pad name="5" x="-11" y="12" drill="0.8" diameter="1.524"/>
<pad name="4" x="-11" y="14" drill="0.8" diameter="1.524"/>
<pad name="3" x="-11" y="16" drill="0.8" diameter="1.524"/>
<pad name="2" x="-11" y="18" drill="0.8" diameter="1.524"/>
<pad name="1" x="-11" y="20" drill="0.8" diameter="1.524"/>
<pad name="11" x="11" y="2" drill="0.8" diameter="1.524"/>
<pad name="12" x="11" y="4" drill="0.8" diameter="1.524"/>
<pad name="13" x="11" y="6" drill="0.8" diameter="1.524"/>
<pad name="14" x="11" y="8" drill="0.8" diameter="1.524"/>
<pad name="15" x="11" y="10" drill="0.8" diameter="1.524"/>
<pad name="16" x="11" y="12" drill="0.8" diameter="1.524"/>
<pad name="17" x="11" y="14" drill="0.8" diameter="1.524"/>
<pad name="18" x="11" y="16" drill="0.8" diameter="1.524"/>
<pad name="19" x="11" y="18" drill="0.8" diameter="1.524"/>
<pad name="20" x="11" y="20" drill="0.8" diameter="1.524"/>
<text x="-8.89" y="2.54" size="0.4064" layer="25">&gt;Name</text>
<text x="-8.89" y="1.27" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="XBEE-SMD">
<wire x1="-5" y1="27.6" x2="5" y2="27.6" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="21.25" x2="-5" y2="27.6" width="0.2032" layer="21"/>
<wire x1="12.25" y1="21.25" x2="5" y2="27.6" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0" x2="12.25" y2="0" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="-12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="-6.25" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="21.25" width="0.2032" layer="51"/>
<wire x1="-9.75" y1="21.25" x2="-9.75" y2="0.75" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0.75" x2="-9.75" y2="0.75" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="21.25" x2="-9.75" y2="21.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="1.3" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="0.75" x2="-9.75" y2="1.3" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="20.6" x2="-9.75" y2="21.25" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="21.25" x2="-12.25" y2="20.6" width="0.2032" layer="21"/>
<wire x1="9.75" y1="0.75" x2="9.75" y2="21.25" width="0.2032" layer="51"/>
<wire x1="12.25" y1="21.25" x2="12.25" y2="0.75" width="0.2032" layer="51"/>
<wire x1="9.75" y1="0.75" x2="12.25" y2="0.75" width="0.2032" layer="51"/>
<wire x1="9.75" y1="21.25" x2="12.25" y2="21.25" width="0.2032" layer="51"/>
<wire x1="9.75" y1="0.75" x2="9.75" y2="1.3" width="0.2032" layer="21"/>
<wire x1="9.75" y1="0.75" x2="12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="12.25" y2="1.3" width="0.2032" layer="21"/>
<wire x1="12.25" y1="20.6" x2="12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="12.25" y1="21.25" x2="9.75" y2="21.25" width="0.2032" layer="21"/>
<wire x1="9.75" y1="21.25" x2="9.75" y2="20.6" width="0.2032" layer="21"/>
<smd name="10" x="-9.5" y="2" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="9" x="-12.5" y="4" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="8" x="-9.5" y="6" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="7" x="-12.5" y="8" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="6" x="-9.5" y="10" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="5" x="-12.5" y="12" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="4" x="-9.5" y="14" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="3" x="-12.5" y="16" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="2" x="-9.5" y="18" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="1" x="-12.5" y="20" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="11" x="12.5" y="2" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="12" x="9.5" y="4" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="13" x="12.5" y="6" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="14" x="9.5" y="8" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="15" x="12.5" y="10" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="16" x="9.5" y="12" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="17" x="12.5" y="14" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="18" x="9.5" y="16" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="19" x="12.5" y="18" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<smd name="20" x="9.5" y="20" dx="0.85" dy="1.7" layer="1" rot="R90"/>
<text x="-8.89" y="2.54" size="0.4064" layer="25">&gt;Name</text>
<text x="-8.89" y="1.27" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="XBEE-1_LOCK">
<wire x1="-5" y1="27.6" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="21.25" x2="-5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="12.25" y1="21.25" x2="5" y2="27.6" width="0.2032" layer="51"/>
<wire x1="9.75" y1="21.25" x2="12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="12.25" y1="21.25" x2="12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="12.25" y1="0.75" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="9.75" y1="21.25" x2="9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-12.25" y2="21.25" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="21.25" x2="-12.25" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-9.75" y1="21.25" x2="-9.75" y2="0.75" width="0.2032" layer="21"/>
<wire x1="-12.25" y1="0.75" x2="-12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="12.25" y1="0.75" x2="12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="12.25" y2="0" width="0.2032" layer="51"/>
<wire x1="12.25" y1="0" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="0" x2="-12.25" y2="-6.25" width="0.2032" layer="51"/>
<wire x1="-12.25" y1="-6.25" x2="12.25" y2="-6.25" width="0.2032" layer="51"/>
<pad name="10" x="-10.8222" y="2" drill="0.7366" diameter="1.524"/>
<pad name="9" x="-11.1778" y="4" drill="0.7366" diameter="1.524"/>
<pad name="8" x="-10.8222" y="6" drill="0.7366" diameter="1.524"/>
<pad name="7" x="-11.1778" y="8" drill="0.7366" diameter="1.524"/>
<pad name="6" x="-10.8222" y="10" drill="0.7366" diameter="1.524"/>
<pad name="5" x="-11.1778" y="12" drill="0.7366" diameter="1.524"/>
<pad name="4" x="-10.8222" y="14" drill="0.7366" diameter="1.524"/>
<pad name="3" x="-11.1778" y="16" drill="0.7366" diameter="1.524"/>
<pad name="2" x="-10.8222" y="18" drill="0.7366" diameter="1.524"/>
<pad name="1" x="-11.1778" y="20" drill="0.7366" diameter="1.524"/>
<pad name="11" x="11.1778" y="2" drill="0.7366" diameter="1.524"/>
<pad name="12" x="10.8222" y="4" drill="0.7366" diameter="1.524"/>
<pad name="13" x="11.1778" y="6" drill="0.7366" diameter="1.524"/>
<pad name="14" x="10.8222" y="8" drill="0.7366" diameter="1.524"/>
<pad name="15" x="11.1778" y="10" drill="0.7366" diameter="1.524"/>
<pad name="16" x="10.8222" y="12" drill="0.7366" diameter="1.524"/>
<pad name="17" x="11.1778" y="14" drill="0.7366" diameter="1.524"/>
<pad name="18" x="10.8222" y="16" drill="0.7366" diameter="1.524"/>
<pad name="19" x="11.1778" y="18" drill="0.7366" diameter="1.524"/>
<pad name="20" x="10.8222" y="20" drill="0.7366" diameter="1.524"/>
<text x="-8.89" y="2.54" size="0.4064" layer="25">&gt;Name</text>
<text x="-8.89" y="1.27" size="0.4064" layer="27">&gt;Value</text>
<rectangle x1="-11.0998" y1="1.7272" x2="-10.8966" y2="2.2352" layer="51"/>
<rectangle x1="-11.0998" y1="3.7338" x2="-10.8966" y2="4.2418" layer="51"/>
<rectangle x1="-11.0998" y1="5.715" x2="-10.8966" y2="6.223" layer="51"/>
<rectangle x1="-11.0998" y1="7.7216" x2="-10.8966" y2="8.2296" layer="51"/>
<rectangle x1="-11.0998" y1="9.7282" x2="-10.8966" y2="10.2362" layer="51"/>
<rectangle x1="-11.0998" y1="11.7602" x2="-10.8966" y2="12.2682" layer="51"/>
<rectangle x1="-11.0998" y1="13.7414" x2="-10.8966" y2="14.2494" layer="51"/>
<rectangle x1="-11.0998" y1="15.7226" x2="-10.8966" y2="16.2306" layer="51"/>
<rectangle x1="-11.0998" y1="17.7292" x2="-10.8966" y2="18.2372" layer="51"/>
<rectangle x1="-11.0998" y1="19.7358" x2="-10.8966" y2="20.2438" layer="51"/>
<rectangle x1="10.8966" y1="1.7272" x2="11.0998" y2="2.2352" layer="51"/>
<rectangle x1="10.8966" y1="3.7338" x2="11.0998" y2="4.2418" layer="51"/>
<rectangle x1="10.8966" y1="5.715" x2="11.0998" y2="6.223" layer="51"/>
<rectangle x1="10.8966" y1="7.7216" x2="11.0998" y2="8.2296" layer="51"/>
<rectangle x1="10.8966" y1="9.7282" x2="11.0998" y2="10.2362" layer="51"/>
<rectangle x1="10.8966" y1="11.7602" x2="11.0998" y2="12.2682" layer="51"/>
<rectangle x1="10.8966" y1="13.7414" x2="11.0998" y2="14.2494" layer="51"/>
<rectangle x1="10.8966" y1="15.7226" x2="11.0998" y2="16.2306" layer="51"/>
<rectangle x1="10.8966" y1="17.7292" x2="11.0998" y2="18.2372" layer="51"/>
<rectangle x1="10.8966" y1="19.7358" x2="11.0998" y2="20.2438" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="XBEE-1">
<wire x1="-15.24" y1="12.7" x2="15.24" y2="12.7" width="0.254" layer="94"/>
<wire x1="15.24" y1="12.7" x2="15.24" y2="-15.24" width="0.254" layer="94"/>
<wire x1="15.24" y1="-15.24" x2="-15.24" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-15.24" x2="-15.24" y2="12.7" width="0.254" layer="94"/>
<text x="-15.24" y="13.462" size="1.6764" layer="95">&gt;Name</text>
<text x="-15.24" y="-17.78" size="1.6764" layer="96">&gt;Value</text>
<pin name="VDD" x="-20.32" y="10.16" length="middle" direction="pwr"/>
<pin name="DOUT" x="-20.32" y="7.62" length="middle" direction="out"/>
<pin name="DIN" x="-20.32" y="5.08" length="middle" direction="in"/>
<pin name="DIO12" x="-20.32" y="2.54" length="middle"/>
<pin name="RESET" x="-20.32" y="0" length="middle" direction="in" function="dot"/>
<pin name="RSSI" x="-20.32" y="-2.54" length="middle"/>
<pin name="DIO11" x="-20.32" y="-5.08" length="middle"/>
<pin name="RES@8" x="-20.32" y="-7.62" length="middle"/>
<pin name="DTR" x="-20.32" y="-10.16" length="middle" function="dot"/>
<pin name="GND" x="-20.32" y="-12.7" length="middle" direction="pwr"/>
<pin name="DIO4" x="20.32" y="-12.7" length="middle" rot="R180"/>
<pin name="CTS" x="20.32" y="-10.16" length="middle" direction="out" function="dot" rot="R180"/>
<pin name="DIO9" x="20.32" y="-7.62" length="middle" rot="R180"/>
<pin name="RES@14" x="20.32" y="-5.08" length="middle" rot="R180"/>
<pin name="DIO5" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="RTS" x="20.32" y="0" length="middle" direction="in" function="dot" rot="R180"/>
<pin name="DIO3" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="DIO2" x="20.32" y="5.08" length="middle" rot="R180"/>
<pin name="DIO1" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="DIO0" x="20.32" y="10.16" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="XBEE-1">
<description>Xbee module footprints&lt;br&gt;
SMT header is CONN-09042.</description>
<gates>
<gate name="G$1" symbol="XBEE-1" x="0" y="0"/>
</gates>
<devices>
<device name="B1" package="XBEE-1">
<connects>
<connect gate="G$1" pin="CTS" pad="12"/>
<connect gate="G$1" pin="DIN" pad="3"/>
<connect gate="G$1" pin="DIO0" pad="20"/>
<connect gate="G$1" pin="DIO1" pad="19"/>
<connect gate="G$1" pin="DIO11" pad="7"/>
<connect gate="G$1" pin="DIO12" pad="4"/>
<connect gate="G$1" pin="DIO2" pad="18"/>
<connect gate="G$1" pin="DIO3" pad="17"/>
<connect gate="G$1" pin="DIO4" pad="11"/>
<connect gate="G$1" pin="DIO5" pad="15"/>
<connect gate="G$1" pin="DIO9" pad="13"/>
<connect gate="G$1" pin="DOUT" pad="2"/>
<connect gate="G$1" pin="DTR" pad="9"/>
<connect gate="G$1" pin="GND" pad="10"/>
<connect gate="G$1" pin="RES@14" pad="14"/>
<connect gate="G$1" pin="RES@8" pad="8"/>
<connect gate="G$1" pin="RESET" pad="5"/>
<connect gate="G$1" pin="RSSI" pad="6"/>
<connect gate="G$1" pin="RTS" pad="16"/>
<connect gate="G$1" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="B2" package="XBEE-SILK">
<connects>
<connect gate="G$1" pin="CTS" pad="12"/>
<connect gate="G$1" pin="DIN" pad="3"/>
<connect gate="G$1" pin="DIO0" pad="20"/>
<connect gate="G$1" pin="DIO1" pad="19"/>
<connect gate="G$1" pin="DIO11" pad="7"/>
<connect gate="G$1" pin="DIO12" pad="4"/>
<connect gate="G$1" pin="DIO2" pad="18"/>
<connect gate="G$1" pin="DIO3" pad="17"/>
<connect gate="G$1" pin="DIO4" pad="11"/>
<connect gate="G$1" pin="DIO5" pad="15"/>
<connect gate="G$1" pin="DIO9" pad="13"/>
<connect gate="G$1" pin="DOUT" pad="2"/>
<connect gate="G$1" pin="DTR" pad="9"/>
<connect gate="G$1" pin="GND" pad="10"/>
<connect gate="G$1" pin="RES@14" pad="14"/>
<connect gate="G$1" pin="RES@8" pad="8"/>
<connect gate="G$1" pin="RESET" pad="5"/>
<connect gate="G$1" pin="RSSI" pad="6"/>
<connect gate="G$1" pin="RTS" pad="16"/>
<connect gate="G$1" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="B3" package="XBEE-SMD">
<connects>
<connect gate="G$1" pin="CTS" pad="12"/>
<connect gate="G$1" pin="DIN" pad="3"/>
<connect gate="G$1" pin="DIO0" pad="20"/>
<connect gate="G$1" pin="DIO1" pad="19"/>
<connect gate="G$1" pin="DIO11" pad="7"/>
<connect gate="G$1" pin="DIO12" pad="4"/>
<connect gate="G$1" pin="DIO2" pad="18"/>
<connect gate="G$1" pin="DIO3" pad="17"/>
<connect gate="G$1" pin="DIO4" pad="11"/>
<connect gate="G$1" pin="DIO5" pad="15"/>
<connect gate="G$1" pin="DIO9" pad="13"/>
<connect gate="G$1" pin="DOUT" pad="2"/>
<connect gate="G$1" pin="DTR" pad="9"/>
<connect gate="G$1" pin="GND" pad="10"/>
<connect gate="G$1" pin="RES@14" pad="14"/>
<connect gate="G$1" pin="RES@8" pad="8"/>
<connect gate="G$1" pin="RESET" pad="5"/>
<connect gate="G$1" pin="RSSI" pad="6"/>
<connect gate="G$1" pin="RTS" pad="16"/>
<connect gate="G$1" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="CONN-09042"/>
</technology>
</technologies>
</device>
<device name="XBEE-1_LOCK" package="XBEE-1_LOCK">
<connects>
<connect gate="G$1" pin="CTS" pad="12"/>
<connect gate="G$1" pin="DIN" pad="3"/>
<connect gate="G$1" pin="DIO0" pad="20"/>
<connect gate="G$1" pin="DIO1" pad="19"/>
<connect gate="G$1" pin="DIO11" pad="7"/>
<connect gate="G$1" pin="DIO12" pad="4"/>
<connect gate="G$1" pin="DIO2" pad="18"/>
<connect gate="G$1" pin="DIO3" pad="17"/>
<connect gate="G$1" pin="DIO4" pad="11"/>
<connect gate="G$1" pin="DIO5" pad="15"/>
<connect gate="G$1" pin="DIO9" pad="13"/>
<connect gate="G$1" pin="DOUT" pad="2"/>
<connect gate="G$1" pin="DTR" pad="9"/>
<connect gate="G$1" pin="GND" pad="10"/>
<connect gate="G$1" pin="RES@14" pad="14"/>
<connect gate="G$1" pin="RES@8" pad="8"/>
<connect gate="G$1" pin="RESET" pad="5"/>
<connect gate="G$1" pin="RSSI" pad="6"/>
<connect gate="G$1" pin="RTS" pad="16"/>
<connect gate="G$1" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-FreqCtrl">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find crystals and oscillators and other things that go "tick".&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; CC v3.0 Share-Alike You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="RESONATOR-SMD">
<wire x1="1.8" y1="0.65" x2="1.8" y2="-0.65" width="0.2032" layer="21"/>
<wire x1="-1.8" y1="-0.65" x2="-1.8" y2="0.65" width="0.2032" layer="21"/>
<wire x1="-1.6" y1="0.65" x2="1.6" y2="0.65" width="0.127" layer="51"/>
<wire x1="1.6" y1="0.65" x2="1.6" y2="-0.65" width="0.127" layer="51"/>
<wire x1="1.6" y1="-0.65" x2="-1.6" y2="-0.65" width="0.127" layer="51"/>
<wire x1="-1.6" y1="-0.65" x2="-1.6" y2="0.65" width="0.127" layer="51"/>
<smd name="1" x="-1.2" y="0" dx="0.7" dy="1.7" layer="1"/>
<smd name="2" x="0" y="0" dx="0.7" dy="1.7" layer="1"/>
<smd name="3" x="1.2" y="0" dx="0.7" dy="1.7" layer="1"/>
<text x="-0.889" y="1.27" size="0.4064" layer="25">&gt;Name</text>
<text x="-0.889" y="-1.524" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="RESONATOR-PTH">
<wire x1="-2.286" y1="1.778" x2="-2.286" y2="-1.778" width="0.2032" layer="21" curve="162.403081"/>
<wire x1="2.286" y1="-1.778" x2="2.286" y2="1.778" width="0.2032" layer="21" curve="162.403081"/>
<wire x1="-2.286" y1="-1.778" x2="2.286" y2="-1.778" width="0.2032" layer="21" curve="12.71932"/>
<wire x1="2.286" y1="1.778" x2="-2.286" y2="1.778" width="0.2032" layer="21" curve="12.758496"/>
<pad name="2" x="0" y="0" drill="0.8" diameter="1.8796"/>
<pad name="1" x="-2.54" y="0" drill="0.8" diameter="1.8796"/>
<pad name="3" x="2.54" y="0" drill="0.8" diameter="1.8796"/>
</package>
</packages>
<symbols>
<symbol name="RESONATOR">
<wire x1="1.016" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.016" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="1.524" x2="-0.381" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-1.524" x2="0.381" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-1.524" x2="0.381" y2="1.524" width="0.1524" layer="94"/>
<wire x1="0.381" y1="1.524" x2="-0.381" y2="1.524" width="0.1524" layer="94"/>
<wire x1="1.016" y1="1.778" x2="1.016" y2="0" width="0.1524" layer="94"/>
<wire x1="1.016" y1="0" x2="1.016" y2="-1.778" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="1.778" x2="-1.016" y2="0" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="0" x2="-1.016" y2="-1.778" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="3.302" y1="-2.032" x2="2.54" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.032" x2="1.778" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="3.302" y1="-3.048" x2="2.54" y2="-3.048" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-3.048" x2="1.778" y2="-3.048" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-3.048" x2="2.54" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="-1.778" y1="-3.048" x2="-2.54" y2="-3.048" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-3.048" x2="-3.302" y2="-3.048" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-3.048" x2="-2.54" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="-1.778" y1="-2.032" x2="-2.54" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-2.032" x2="-3.302" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-2.032" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="0" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="0" y1="-5.08" x2="-2.54" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="0" y1="-5.08" x2="0" y2="-7.62" width="0.1524" layer="94"/>
<text x="2.54" y="1.016" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<pin name="3" x="2.54" y="0" visible="off" length="point" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-2.54" y="0" visible="off" length="point" direction="pas" swaplevel="1"/>
<pin name="2" x="0" y="-7.62" visible="off" length="point" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RESONATOR" prefix="Y" uservalue="yes">
<description>&lt;b&gt;Resonator&lt;/b&gt;&lt;br&gt;
Small SMD resonator.&lt;br&gt;
Used, eg, on the Arduino Pro/ Pro Mini boards.&lt;br&gt;
8MHz- XTAL-08895&lt;br&gt;
16MHz- XTAL-08900</description>
<gates>
<gate name="G$1" symbol="RESONATOR" x="0" y="0"/>
</gates>
<devices>
<device name="8MHZ" package="RESONATOR-SMD">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="XTAL-08895"/>
<attribute name="VALUE" value="8MHZ" constant="no"/>
</technology>
</technologies>
</device>
<device name="PTH" package="RESONATOR-PTH">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="16MHZ" package="RESONATOR-SMD">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="XTAL-08900"/>
<attribute name="VALUE" value="16MHz"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-Resistors">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find resistors, capacitors, inductors, test points, jumper pads, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; CC v3.0 Share-Alike You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="0603-RES">
<wire x1="-1.473" y1="0.983" x2="1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="0.983" x2="1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="-0.983" x2="-1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.473" y1="-0.983" x2="-1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="-0.356" y1="0.432" x2="0.356" y2="0.432" width="0.1016" layer="51"/>
<wire x1="-0.356" y1="-0.419" x2="0.356" y2="-0.419" width="0.1016" layer="51"/>
<smd name="1" x="-0.85" y="0" dx="1.1" dy="1" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.1" dy="1" layer="1"/>
<text x="-0.889" y="0.762" size="0.4064" layer="25" font="vector">&gt;NAME</text>
<text x="-1.016" y="-1.143" size="0.4064" layer="27" font="vector">&gt;VALUE</text>
<rectangle x1="-0.8382" y1="-0.4699" x2="-0.3381" y2="0.4801" layer="51"/>
<rectangle x1="0.3302" y1="-0.4699" x2="0.8303" y2="0.4801" layer="51"/>
<rectangle x1="-0.1999" y1="-0.3" x2="0.1999" y2="0.3" layer="35"/>
<rectangle x1="-0.2286" y1="-0.381" x2="0.2286" y2="0.381" layer="21"/>
</package>
<package name="1206">
<wire x1="-2.473" y1="0.983" x2="2.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="-0.983" x2="-2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-2.473" y1="-0.983" x2="-2.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="0.983" x2="2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-0.965" y1="0.787" x2="0.965" y2="0.787" width="0.1016" layer="51"/>
<wire x1="-0.965" y1="-0.787" x2="0.965" y2="-0.787" width="0.1016" layer="51"/>
<smd name="1" x="-1.4" y="0" dx="1.6" dy="1.8" layer="1"/>
<smd name="2" x="1.4" y="0" dx="1.6" dy="1.8" layer="1"/>
<text x="-1.27" y="1.143" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.397" y="-1.524" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-1.7018" y1="-0.8509" x2="-0.9517" y2="0.8491" layer="51"/>
<rectangle x1="0.9517" y1="-0.8491" x2="1.7018" y2="0.8509" layer="51"/>
<rectangle x1="-0.1999" y1="-0.4001" x2="0.1999" y2="0.4001" layer="35"/>
</package>
<package name="AXIAL-0.3">
<wire x1="-2.54" y1="0.762" x2="2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0.762" x2="2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-0.762" x2="-2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="-0.762" x2="-2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.794" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.794" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="-3.81" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="3.81" y="0" drill="0.9" diameter="1.8796"/>
<text x="-2.54" y="1.27" size="0.4064" layer="25" font="vector">&gt;Name</text>
<text x="-2.032" y="-0.381" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="R2010">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;&lt;p&gt;
chip</description>
<wire x1="-1.662" y1="1.245" x2="1.662" y2="1.245" width="0.1524" layer="51"/>
<wire x1="-1.637" y1="-1.245" x2="1.687" y2="-1.245" width="0.1524" layer="51"/>
<wire x1="-3.473" y1="1.483" x2="3.473" y2="1.483" width="0.0508" layer="39"/>
<wire x1="3.473" y1="1.483" x2="3.473" y2="-1.483" width="0.0508" layer="39"/>
<wire x1="3.473" y1="-1.483" x2="-3.473" y2="-1.483" width="0.0508" layer="39"/>
<wire x1="-3.473" y1="-1.483" x2="-3.473" y2="1.483" width="0.0508" layer="39"/>
<wire x1="-1.027" y1="1.245" x2="1.027" y2="1.245" width="0.1524" layer="21"/>
<wire x1="-1.002" y1="-1.245" x2="1.016" y2="-1.245" width="0.1524" layer="21"/>
<smd name="1" x="-2.2" y="0" dx="1.8" dy="2.7" layer="1"/>
<smd name="2" x="2.2" y="0" dx="1.8" dy="2.7" layer="1"/>
<text x="-2.54" y="1.5875" size="0.4064" layer="25">&gt;NAME</text>
<text x="-2.54" y="-2.032" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-2.4892" y1="-1.3208" x2="-1.6393" y2="1.3292" layer="51"/>
<rectangle x1="1.651" y1="-1.3208" x2="2.5009" y2="1.3292" layer="51"/>
</package>
<package name="0805">
<wire x1="-0.3" y1="0.6" x2="0.3" y2="0.6" width="0.1524" layer="21"/>
<wire x1="-0.3" y1="-0.6" x2="0.3" y2="-0.6" width="0.1524" layer="21"/>
<smd name="1" x="-0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<smd name="2" x="0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<text x="-0.762" y="0.8255" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.397" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="1/6W-RES">
<description>1/6W Thru-hole Resistor - *UNPROVEN*</description>
<wire x1="-1.55" y1="0.85" x2="-1.55" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="-1.55" y1="-0.85" x2="1.55" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="1.55" y1="-0.85" x2="1.55" y2="0.85" width="0.2032" layer="21"/>
<wire x1="1.55" y1="0.85" x2="-1.55" y2="0.85" width="0.2032" layer="21"/>
<pad name="1" x="-2.5" y="0" drill="0.762" diameter="1.6764"/>
<pad name="2" x="2.5" y="0" drill="0.762" diameter="1.6764"/>
<text x="-1.2662" y="0.9552" size="0.6096" layer="25">&gt;NAME</text>
<text x="-1.423" y="-0.4286" size="0.8128" layer="21" ratio="15">&gt;VALUE</text>
</package>
<package name="R2512">
<wire x1="-2.362" y1="1.473" x2="2.387" y2="1.473" width="0.1524" layer="51"/>
<wire x1="-2.362" y1="-1.473" x2="2.387" y2="-1.473" width="0.1524" layer="51"/>
<smd name="1" x="-2.8" y="0" dx="1.8" dy="3.2" layer="1"/>
<smd name="2" x="2.8" y="0" dx="1.8" dy="3.2" layer="1"/>
<text x="-2.54" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-3.2004" y1="-1.5494" x2="-2.3505" y2="1.5507" layer="51"/>
<rectangle x1="2.3622" y1="-1.5494" x2="3.2121" y2="1.5507" layer="51"/>
</package>
<package name="AXIAL-0.4">
<description>1/4W Resistor, 0.4" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-3.15" y1="-1.2" x2="-3.15" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.15" y1="1.2" x2="3.15" y2="1.2" width="0.2032" layer="21"/>
<wire x1="3.15" y1="1.2" x2="3.15" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.15" y1="-1.2" x2="-3.15" y2="-1.2" width="0.2032" layer="21"/>
<pad name="P$1" x="-5.08" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="5.08" y="0" drill="0.9" diameter="1.8796"/>
<text x="-3.175" y="1.905" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="-2.286" y="-0.381" size="0.8128" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.5">
<description>1/2W Resistor, 0.5" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-4.5" y1="-1.65" x2="-4.5" y2="1.65" width="0.2032" layer="21"/>
<wire x1="-4.5" y1="1.65" x2="4.5" y2="1.65" width="0.2032" layer="21"/>
<wire x1="4.5" y1="1.65" x2="4.5" y2="-1.65" width="0.2032" layer="21"/>
<wire x1="4.5" y1="-1.65" x2="-4.5" y2="-1.65" width="0.2032" layer="21"/>
<pad name="P$1" x="-6.35" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="6.35" y="0" drill="0.9" diameter="1.8796"/>
<text x="-4.445" y="2.54" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="-3.429" y="-0.381" size="0.8128" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.6">
<description>1W Resistor, 0.6" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-5.75" y1="-2.25" x2="-5.75" y2="2.25" width="0.2032" layer="21"/>
<wire x1="-5.75" y1="2.25" x2="5.75" y2="2.25" width="0.2032" layer="21"/>
<wire x1="5.75" y1="2.25" x2="5.75" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="5.75" y1="-2.25" x2="-5.75" y2="-2.25" width="0.2032" layer="21"/>
<pad name="P$1" x="-7.62" y="0" drill="1.2" diameter="1.8796"/>
<pad name="P$2" x="7.62" y="0" drill="1.2" diameter="1.8796"/>
<text x="-5.715" y="3.175" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="-4.064" y="-0.381" size="0.8128" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.8">
<description>2W Resistor, 0.8" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-7.75" y1="-2.5" x2="-7.75" y2="2.5" width="0.2032" layer="21"/>
<wire x1="-7.75" y1="2.5" x2="7.75" y2="2.5" width="0.2032" layer="21"/>
<wire x1="7.75" y1="2.5" x2="7.75" y2="-2.5" width="0.2032" layer="21"/>
<wire x1="7.75" y1="-2.5" x2="-7.75" y2="-2.5" width="0.2032" layer="21"/>
<pad name="P$1" x="-10.16" y="0" drill="1.2" diameter="1.8796"/>
<pad name="P$2" x="10.16" y="0" drill="1.2" diameter="1.8796"/>
<text x="-7.62" y="3.175" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="-5.969" y="-0.381" size="0.8128" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.3-KIT">
<description>&lt;h3&gt;AXIAL-0.3-KIT&lt;/h3&gt;

Commonly used for 1/4W through-hole resistors. 0.3" pitch between holes.&lt;br&gt;
&lt;br&gt;

&lt;b&gt;Warning:&lt;/b&gt; This is the KIT version of the AXIAL-0.3 package. This package has a smaller diameter top stop mask, which doesn't cover the diameter of the pad. This means only the bottom side of the pads' copper will be exposed. You'll only be able to solder to the bottom side.</description>
<wire x1="-2.54" y1="1.27" x2="2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="0" width="0.254" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.27" width="0.254" layer="21"/>
<wire x1="2.54" y1="-1.27" x2="-2.54" y2="-1.27" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-1.27" x2="-2.54" y2="0" width="0.254" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="2.54" y1="0" x2="2.794" y2="0" width="0.254" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.794" y2="0" width="0.254" layer="21"/>
<pad name="P$1" x="-3.81" y="0" drill="1.016" diameter="2.032" stop="no"/>
<pad name="P$2" x="3.81" y="0" drill="1.016" diameter="2.032" stop="no"/>
<text x="-2.54" y="1.27" size="0.4064" layer="25" font="vector">&gt;Name</text>
<text x="-2.159" y="-0.762" size="1.27" layer="21" font="vector" ratio="15">&gt;Value</text>
<polygon width="0.127" layer="30">
<vertex x="3.8201" y="-0.9449" curve="-90"/>
<vertex x="2.8652" y="-0.0152" curve="-90.011749"/>
<vertex x="3.8176" y="0.9602" curve="-90"/>
<vertex x="4.7676" y="-0.0178" curve="-90.024193"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="3.8176" y="-0.4369" curve="-90.012891"/>
<vertex x="3.3731" y="-0.0127" curve="-90"/>
<vertex x="3.8176" y="0.4546" curve="-90"/>
<vertex x="4.2595" y="-0.0025" curve="-90.012967"/>
</polygon>
<polygon width="0.127" layer="30">
<vertex x="-3.8075" y="-0.9525" curve="-90"/>
<vertex x="-4.7624" y="-0.0228" curve="-90.011749"/>
<vertex x="-3.81" y="0.9526" curve="-90"/>
<vertex x="-2.86" y="-0.0254" curve="-90.024193"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-3.81" y="-0.4445" curve="-90.012891"/>
<vertex x="-4.2545" y="-0.0203" curve="-90"/>
<vertex x="-3.81" y="0.447" curve="-90"/>
<vertex x="-3.3681" y="-0.0101" curve="-90.012967"/>
</polygon>
</package>
<package name="AXIAL-0.3EZ">
<description>This is the "EZ" version of the standard .3" spaced resistor package.&lt;br&gt;
It has a reduced top mask to make it harder to install upside-down.</description>
<wire x1="-2.54" y1="0.762" x2="2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0.762" x2="2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-0.762" x2="-2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="-0.762" x2="-2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.794" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.794" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="-3.81" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<pad name="P$2" x="3.81" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<text x="-2.54" y="1.27" size="0.4064" layer="25" font="vector">&gt;Name</text>
<text x="-2.032" y="-0.381" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
<circle x="-3.81" y="0" radius="0.508" width="0" layer="29"/>
<circle x="3.81" y="0" radius="0.523634375" width="0" layer="29"/>
<circle x="-3.81" y="0" radius="1.02390625" width="0" layer="30"/>
<circle x="3.81" y="0" radius="1.04726875" width="0" layer="30"/>
</package>
<package name="AXIAL-0.1EZ">
<wire x1="1.27" y1="-0.762" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.27" y2="0.762" width="0.2032" layer="21"/>
<wire x1="1.524" y1="0" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.016" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="0" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<pad name="P$2" x="2.54" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<text x="0" y="1.27" size="1.016" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0" y="-2.159" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
<circle x="0" y="0" radius="0.4572" width="0" layer="29"/>
<circle x="0" y="0" radius="1.016" width="0" layer="30"/>
<circle x="2.54" y="0" radius="1.016" width="0" layer="30"/>
<circle x="0" y="0" radius="0.4572" width="0" layer="29"/>
<circle x="2.54" y="0" radius="0.4572" width="0" layer="29"/>
</package>
<package name="AXIAL-0.1">
<wire x1="1.27" y1="-0.762" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.27" y2="0.762" width="0.2032" layer="21"/>
<wire x1="1.524" y1="0" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.016" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="0" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="2.54" y="0" drill="0.9" diameter="1.8796"/>
<text x="0" y="1.27" size="1.016" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0" y="-2.159" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
</packages>
<symbols>
<symbol name="RESISTOR">
<wire x1="-2.54" y1="0" x2="-2.159" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-2.159" y1="1.016" x2="-1.524" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-1.524" y1="-1.016" x2="-0.889" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-0.889" y1="1.016" x2="-0.254" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-0.254" y1="-1.016" x2="0.381" y2="1.016" width="0.1524" layer="94"/>
<wire x1="0.381" y1="1.016" x2="1.016" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="1.016" y1="-1.016" x2="1.651" y2="1.016" width="0.1524" layer="94"/>
<wire x1="1.651" y1="1.016" x2="2.286" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="2.286" y1="-1.016" x2="2.54" y2="0" width="0.1524" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1.8KOHM1/10W1%(0603)" prefix="R" uservalue="yes">
<description>RES-09119</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0603-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-09119"/>
<attribute name="VALUE" value="1.8k"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="3.3KOHM1/10W1%(0603)" prefix="R" uservalue="yes">
<description>RES-07851</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0603-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-07851" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RESISTOR" prefix="R" uservalue="yes">
<description>&lt;b&gt;Resistor&lt;/b&gt;
Basic schematic elements and footprints for 0603, 1206, and PTH resistors.</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="1206" package="1206">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="AXIAL-0.3" package="AXIAL-0.3">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="2010" package="R2010">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805-RES" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0603-RES" package="0603-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0603" package="0603-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1/6W" package="1/6W-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="2512" package="R2512">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1/4W" package="AXIAL-0.4">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1/2W" package="AXIAL-0.5">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1W" package="AXIAL-0.6">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-2W" package="AXIAL-0.8">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="KIT" package="AXIAL-0.3-KIT">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="EZ" package="AXIAL-0.3EZ">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1/4W-VERT-KIT" package="AXIAL-0.1EZ">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH-1/4W-VERT" package="AXIAL-0.1">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="100OHM1/10W1%(0603)" prefix="R" uservalue="yes">
<description>RES-07863</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="0603-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-07863" constant="no"/>
<attribute name="VALUE" value="100" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Microchip_By_element14_Batch_1">
<description>Developed by element14 :&lt;br&gt;
element14 CAD Library consolidation.ulp
at 30/07/2012 11:22:31</description>
<packages>
<package name="SOT230P700X180-4N">
<smd name="1" x="-3.2004" y="2.3114" dx="1.6256" dy="0.889" layer="1"/>
<smd name="2" x="-3.2004" y="0" dx="1.6256" dy="0.889" layer="1"/>
<smd name="3" x="-3.2004" y="-2.3114" dx="1.6256" dy="0.889" layer="1"/>
<smd name="4" x="3.2004" y="0" dx="1.6256" dy="3.175" layer="1"/>
<wire x1="-1.8542" y1="1.8796" x2="-1.8542" y2="2.7432" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="2.7432" x2="-3.6576" y2="2.7432" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="2.7432" x2="-3.6576" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="1.8796" x2="-1.8542" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-0.4318" x2="-1.8542" y2="0.4318" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="0.4318" x2="-3.6576" y2="0.4318" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="0.4318" x2="-3.6576" y2="-0.4318" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-0.4318" x2="-1.8542" y2="-0.4318" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-2.7432" x2="-1.8542" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-1.8796" x2="-3.6576" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-1.8796" x2="-3.6576" y2="-2.7432" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-2.7432" x2="-1.8542" y2="-2.7432" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="1.5748" x2="1.8542" y2="-1.5748" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="-1.5748" x2="3.6576" y2="-1.5748" width="0.1524" layer="51"/>
<wire x1="3.6576" y1="-1.5748" x2="3.6576" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="3.6576" y1="1.6002" x2="1.8542" y2="1.5748" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-3.3528" x2="1.8542" y2="-3.3528" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="-3.3528" x2="1.8542" y2="3.3528" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="3.3528" x2="-1.8542" y2="3.3528" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="3.3528" x2="-1.8542" y2="-3.3528" width="0.1524" layer="51"/>
<text x="-4.0132" y="2.3876" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.8542" y1="-3.3528" x2="1.8542" y2="-3.3528" width="0.1524" layer="21"/>
<wire x1="1.8542" y1="-3.3528" x2="1.8542" y2="3.3528" width="0.1524" layer="21"/>
<wire x1="1.8542" y1="3.3528" x2="-1.8542" y2="3.3528" width="0.1524" layer="21"/>
<wire x1="-1.8542" y1="3.3528" x2="-1.8542" y2="-3.3528" width="0.1524" layer="21"/>
<text x="-4.0132" y="2.3876" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-4.8006" y="3.556" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.715" y="-5.8674" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="MCP1824ST-3302E/DB">
<pin name="VIN" x="-22.86" y="0" length="middle" direction="in"/>
<pin name="GND_(TAB)" x="-22.86" y="-5.08" length="middle" direction="pas"/>
<pin name="GND_(TAB)_2" x="-22.86" y="-7.62" length="middle" direction="pas"/>
<pin name="VOUT" x="22.86" y="-5.08" length="middle" direction="out" rot="R180"/>
<wire x1="-17.78" y1="5.08" x2="-17.78" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="-17.78" y1="-12.7" x2="17.78" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="17.78" y1="-12.7" x2="17.78" y2="5.08" width="0.4064" layer="94"/>
<wire x1="17.78" y1="5.08" x2="-17.78" y2="5.08" width="0.4064" layer="94"/>
<text x="-4.5974" y="6.2992" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.588" y="-15.3416" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MCP1824ST-3302E/DB" prefix="U">
<description>IC, LDO VOLT REG, 3.3V, 0.3A,</description>
<gates>
<gate name="A" symbol="MCP1824ST-3302E/DB" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT230P700X180-4N">
<connects>
<connect gate="A" pin="GND_(TAB)" pad="2"/>
<connect gate="A" pin="GND_(TAB)_2" pad="4"/>
<connect gate="A" pin="VIN" pad="1"/>
<connect gate="A" pin="VOUT" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="MCP1824ST-3302E/DB" constant="no"/>
<attribute name="OC_FARNELL" value="1578379" constant="no"/>
<attribute name="OC_NEWARK" value="05N1293" constant="no"/>
<attribute name="PACKAGE" value="SOT-223-3" constant="no"/>
<attribute name="SUPPLIER" value="Microchip" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-Aesthetics">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find non-functional items- supply symbols, logos, notations, frame blocks, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; CC v3.0 Share-Alike You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
</packages>
<symbols>
<symbol name="DGND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VCC">
<wire x1="0.762" y1="1.27" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="-0.762" y2="1.27" width="0.254" layer="94"/>
<text x="-1.016" y="3.556" size="1.778" layer="96">&gt;VALUE</text>
<pin name="VCC" x="0" y="0" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="DGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VCC" prefix="SUPPLY">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-amp-quick">
<description>&lt;b&gt;AMP Connectors, Type QUICK&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="02P">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<wire x1="-2.286" y1="2.54" x2="-2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-0.381" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.381" y1="1.778" x2="-0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.651" x2="0" y2="1.397" width="0.1524" layer="21"/>
<wire x1="0" y1="1.397" x2="0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.651" x2="0.381" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.159" x2="-0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.286" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="-0.254" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.286" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.381" y1="1.778" x2="2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.778" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.778" x2="-1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.778" x2="2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.778" x2="1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="0.635" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.524" x2="2.286" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.524" x2="-2.286" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.54" x2="-1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.54" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.667" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.016" y1="2.54" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.667" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="-0.254" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.413" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.54" x2="-1.016" y2="2.54" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<text x="-0.762" y="0.9398" size="0.9906" layer="21" ratio="12" rot="R90">1</text>
<text x="-2.286" y="2.9464" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.286" y="-3.8354" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-1.6002" y1="-0.3302" x2="-0.9398" y2="0.3302" layer="51"/>
<rectangle x1="0.9398" y1="-0.3302" x2="1.6002" y2="0.3302" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="M02">
<wire x1="3.81" y1="-2.54" x2="-2.54" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-2.54" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="M02" prefix="SL" uservalue="yes">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="M02" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="02P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="SparkFun-DigitalIC" deviceset="ATMEGA328_SMT" device="" value="ATMEGA328P"/>
<part name="U$1" library="SparkFun-RF" deviceset="XBEE-1" device="B1"/>
<part name="Y1" library="SparkFun-FreqCtrl" deviceset="RESONATOR" device="PTH"/>
<part name="R1" library="SparkFun-Resistors" deviceset="1.8KOHM1/10W1%(0603)" device="" value="1.8k"/>
<part name="R2" library="SparkFun-Resistors" deviceset="3.3KOHM1/10W1%(0603)" device="" value="3.3k"/>
<part name="R3" library="SparkFun-Resistors" deviceset="RESISTOR" device="1206" value="10k"/>
<part name="R4" library="SparkFun-Resistors" deviceset="100OHM1/10W1%(0603)" device="" value="100"/>
<part name="U2" library="Microchip_By_element14_Batch_1" deviceset="MCP1824ST-3302E/DB" device=""/>
<part name="GND1" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="GND2" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="GND3" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="SUPPLY1" library="SparkFun-Aesthetics" deviceset="VCC" device=""/>
<part name="SUPPLY2" library="SparkFun-Aesthetics" deviceset="VCC" device=""/>
<part name="SUPPLY3" library="SparkFun-Aesthetics" deviceset="VCC" device=""/>
<part name="SL1" library="con-amp-quick" deviceset="M02" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U1" gate="G$1" x="5.08" y="48.26"/>
<instance part="U$1" gate="G$1" x="104.14" y="78.74"/>
<instance part="Y1" gate="G$1" x="-25.4" y="45.72" rot="R270"/>
<instance part="R1" gate="G$1" x="48.26" y="66.04"/>
<instance part="R2" gate="G$1" x="71.12" y="66.04"/>
<instance part="R3" gate="G$1" x="-22.86" y="81.28" rot="R90"/>
<instance part="R4" gate="G$1" x="68.58" y="86.36"/>
<instance part="U2" gate="A" x="106.68" y="43.18"/>
<instance part="GND1" gate="1" x="55.88" y="53.34" rot="R270"/>
<instance part="GND2" gate="1" x="-40.64" y="43.18"/>
<instance part="GND3" gate="1" x="-22.86" y="10.16"/>
<instance part="SUPPLY1" gate="G$1" x="-22.86" y="88.9"/>
<instance part="SUPPLY2" gate="G$1" x="-33.02" y="66.04"/>
<instance part="SUPPLY3" gate="G$1" x="58.42" y="35.56" rot="R90"/>
<instance part="SL1" gate="G$1" x="45.72" y="43.18"/>
</instances>
<busses>
</busses>
<nets>
<net name="RST" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PC6(/RESET)"/>
<wire x1="-17.78" y1="73.66" x2="-22.86" y2="73.66" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="1"/>
<wire x1="-22.86" y1="73.66" x2="-33.02" y2="73.66" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="76.2" x2="-22.86" y2="73.66" width="0.1524" layer="91"/>
<junction x="-22.86" y="73.66"/>
<label x="-33.02" y="73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="66.04" y1="66.04" x2="58.42" y2="66.04" width="0.1524" layer="91"/>
<wire x1="58.42" y1="66.04" x2="53.34" y2="66.04" width="0.1524" layer="91"/>
<wire x1="58.42" y1="66.04" x2="58.42" y2="83.82" width="0.1524" layer="91"/>
<junction x="58.42" y="66.04"/>
<pinref part="U$1" gate="G$1" pin="DIN"/>
<wire x1="58.42" y1="83.82" x2="83.82" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="2"/>
<pinref part="U$1" gate="G$1" pin="DOUT"/>
<wire x1="73.66" y1="86.36" x2="83.82" y2="86.36" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="1"/>
<wire x1="63.5" y1="86.36" x2="35.56" y2="86.36" width="0.1524" layer="91"/>
<label x="35.56" y="86.36" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="43.18" y1="66.04" x2="35.56" y2="66.04" width="0.1524" layer="91"/>
<label x="35.56" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="Y1" gate="G$1" pin="1"/>
<pinref part="U1" gate="G$1" pin="PB6(XTAL1/TOSC1)"/>
<wire x1="-25.4" y1="48.26" x2="-17.78" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="Y1" gate="G$1" pin="3"/>
<pinref part="U1" gate="G$1" pin="PB7(XTAL2/TOSC2)"/>
<wire x1="-25.4" y1="43.18" x2="-17.78" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U2" gate="A" pin="GND_(TAB)_2"/>
<wire x1="83.82" y1="35.56" x2="78.74" y2="35.56" width="0.1524" layer="91"/>
<wire x1="78.74" y1="35.56" x2="78.74" y2="38.1" width="0.1524" layer="91"/>
<pinref part="U2" gate="A" pin="GND_(TAB)"/>
<wire x1="78.74" y1="38.1" x2="78.74" y2="53.34" width="0.1524" layer="91"/>
<wire x1="83.82" y1="38.1" x2="78.74" y2="38.1" width="0.1524" layer="91"/>
<junction x="78.74" y="38.1"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U2" gate="A" pin="VOUT"/>
<wire x1="129.54" y1="38.1" x2="132.08" y2="38.1" width="0.1524" layer="91"/>
<wire x1="132.08" y1="38.1" x2="132.08" y2="99.06" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="VDD"/>
<wire x1="132.08" y1="99.06" x2="83.82" y2="99.06" width="0.1524" layer="91"/>
<wire x1="83.82" y1="99.06" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="AGND"/>
<wire x1="-17.78" y1="22.86" x2="-22.86" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="22.86" x2="-22.86" y2="20.32" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="GND@2"/>
<wire x1="-22.86" y1="20.32" x2="-22.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="17.78" x2="-22.86" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="17.78" x2="-22.86" y2="17.78" width="0.1524" layer="91"/>
<junction x="-22.86" y="17.78"/>
<pinref part="U1" gate="G$1" pin="GND@1"/>
<wire x1="-17.78" y1="20.32" x2="-22.86" y2="20.32" width="0.1524" layer="91"/>
<junction x="-22.86" y="20.32"/>
<pinref part="GND3" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="R2" gate="G$1" pin="2"/>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="76.2" y1="66.04" x2="83.82" y2="66.04" width="0.1524" layer="91"/>
<wire x1="83.82" y1="66.04" x2="83.82" y2="53.34" width="0.1524" layer="91"/>
<junction x="83.82" y="66.04"/>
<wire x1="83.82" y1="53.34" x2="60.96" y2="53.34" width="0.1524" layer="91"/>
<wire x1="60.96" y1="53.34" x2="58.42" y2="53.34" width="0.1524" layer="91"/>
<wire x1="60.96" y1="53.34" x2="60.96" y2="45.72" width="0.1524" layer="91"/>
<junction x="60.96" y="53.34"/>
<wire x1="60.96" y1="45.72" x2="53.34" y2="45.72" width="0.1524" layer="91"/>
<pinref part="SL1" gate="G$1" pin="2"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="Y1" gate="G$1" pin="2"/>
<wire x1="-33.02" y1="45.72" x2="-40.64" y2="45.72" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="U2" gate="A" pin="VIN"/>
<wire x1="83.82" y1="43.18" x2="73.66" y2="43.18" width="0.1524" layer="91"/>
<wire x1="73.66" y1="43.18" x2="73.66" y2="35.56" width="0.1524" layer="91"/>
<wire x1="73.66" y1="35.56" x2="60.96" y2="35.56" width="0.1524" layer="91"/>
<wire x1="60.96" y1="35.56" x2="60.96" y2="43.18" width="0.1524" layer="91"/>
<wire x1="60.96" y1="43.18" x2="53.34" y2="43.18" width="0.1524" layer="91"/>
<pinref part="SL1" gate="G$1" pin="1"/>
<pinref part="SUPPLY3" gate="G$1" pin="VCC"/>
<wire x1="60.96" y1="35.56" x2="58.42" y2="35.56" width="0.1524" layer="91"/>
<junction x="60.96" y="35.56"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="AVCC"/>
<wire x1="-17.78" y1="68.58" x2="-22.86" y2="68.58" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="68.58" x2="-22.86" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="AREF"/>
<wire x1="-22.86" y1="66.04" x2="-22.86" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="63.5" x2="-22.86" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="58.42" x2="-17.78" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="VCC@1"/>
<wire x1="-17.78" y1="66.04" x2="-22.86" y2="66.04" width="0.1524" layer="91"/>
<junction x="-22.86" y="66.04"/>
<pinref part="U1" gate="G$1" pin="VCC@2"/>
<wire x1="-17.78" y1="63.5" x2="-22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="-22.86" y="63.5"/>
<wire x1="-22.86" y1="63.5" x2="-33.02" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="63.5" x2="-33.02" y2="66.04" width="0.1524" layer="91"/>
<pinref part="SUPPLY2" gate="G$1" pin="VCC"/>
</segment>
<segment>
<pinref part="R3" gate="G$1" pin="2"/>
<pinref part="SUPPLY1" gate="G$1" pin="VCC"/>
<wire x1="-22.86" y1="86.36" x2="-22.86" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
