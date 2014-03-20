import requests, random, time

CONFIG_BASE_URL = 'http://smartparking.local/API/'
#CONFIG_BASE_URL = 'http://sachleen.com/sachleen/parking/API/'
CONFIG_API_KEY = u'e1d1b85eef174d89121da2407f7bb15b'

nodes = ['AAAAA', 'BBBBB', 'CCCCC', 'DDDDD', 'EEEEE', 'FFFFF'] #for localhost
#nodes = ['TEST1', 'PPPPP', 'CCCCC', 'DDDDD', 'EEEEE', 'FFFFF'] #for server

try:
    while True:
        # Get info for random node
        randNode = nodes[random.randrange(len(nodes))]
        print "Getting node info from server"
        r = requests.get(CONFIG_BASE_URL + "nodes/{0}".format(randNode))
        json = r.json()
        
        available = int(json['available'])
        total = int(json['total'])

        # Add or subtract one from available spots
        if available == 0:
            available = 1
        elif available == total:
            available = available - 1
        else:
            available = available + random.sample([-1,1],1)[0];
        
        print "Node ID: ", randNode
        print "Available spots Before:", json['available']
        print "Available spots After:", available
        
        payload = {
            'id': randNode,
            'available': available,
            'api_key': CONFIG_API_KEY
        }
        
        r = requests.post(CONFIG_BASE_URL + "nodes/save", data = payload)
        
        print "Waiting",
        for x in range(0, 15):
            print ".",
            time.sleep(.5)
        
        print "\n"
except KeyboardInterrupt:
    print "Exiting"