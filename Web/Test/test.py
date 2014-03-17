import requests

CONFIG_BASE_URL = 'http://smartparking.local/API/'
#CONFIG_BASE_URL = 'http://sachleen.com/sachleen/parking/API/'
CONFIG_API_KEY_FULL = u'c51088dad22ea00758e0bdcc2a29bf5c'
CONFIG_API_KEY_HALF = u'e1d1b85eef174d89121da2407f7bb15b'
CONFIG_API_KEY_BAD = u'BADAPIKEYe1d18e0bd7f7bb15bb85eef'
CONFIG_LAT = u'38.57689'
CONFIG_LNG = u'-121.49373'

RESULT_PASS_COUNT = 0
RESULT_FAIL_COUNT = 0

print "Save Node"
print "=============================="

PAYLOAD_SAVE_FULL = {
            'id': u'CCCC1',
            'lat': CONFIG_LAT,
            'lng': CONFIG_LNG,
            'total': u'5',
            'api_key': CONFIG_API_KEY_BAD
          }

PAYLOAD_UPDATE_AVAILABLE = {
            'id': 'CCCC1',
            'available': '2',
            'api_key': CONFIG_API_KEY_BAD
          }

# ######################################## #
print "Save with bad API key"

PAYLOAD_SAVE_FULL['api_key'] = CONFIG_API_KEY_BAD
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_SAVE_FULL)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "API Key Fail":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Save with half API key"

PAYLOAD_SAVE_FULL['api_key'] = CONFIG_API_KEY_HALF
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_SAVE_FULL)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "API Key Fail":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Save with full API key"

PAYLOAD_SAVE_FULL['api_key'] = CONFIG_API_KEY_FULL
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_SAVE_FULL)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update total count"

PAYLOAD_SAVE_FULL['total'] = 10
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_SAVE_FULL)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update position"

PAYLOAD_SAVE_FULL['lat'] = u'38.57690'
PAYLOAD_SAVE_FULL['lng'] = u'-121.49374'
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_SAVE_FULL)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update available count (Bad API Key)"

PAYLOAD_UPDATE_AVAILABLE['available'] = 10
PAYLOAD_UPDATE_AVAILABLE['api_key'] = CONFIG_API_KEY_BAD
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_UPDATE_AVAILABLE)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "API Key Fail":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update available count (Half API Key)"

PAYLOAD_UPDATE_AVAILABLE['available'] = 10
PAYLOAD_UPDATE_AVAILABLE['api_key'] = CONFIG_API_KEY_HALF
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_UPDATE_AVAILABLE)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update available count (Full API Key)"

PAYLOAD_UPDATE_AVAILABLE['available'] = 10
PAYLOAD_UPDATE_AVAILABLE['api_key'] = CONFIG_API_KEY_FULL
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_UPDATE_AVAILABLE)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Update available count (available > total)"

PAYLOAD_UPDATE_AVAILABLE['available'] = 100
PAYLOAD_UPDATE_AVAILABLE['api_key'] = CONFIG_API_KEY_FULL
r = requests.post(CONFIG_BASE_URL + "nodes/save", data = PAYLOAD_UPDATE_AVAILABLE)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "Available spots cannot be more than total spots!":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

print "\nGet Node Info"
print "=============================="

# ######################################## #
print "Get Node Info"
id = PAYLOAD_SAVE_FULL['id']
r = requests.get(CONFIG_BASE_URL + "nodes/{0}".format(id))
json = r.json()

if json['id'] == PAYLOAD_SAVE_FULL['id'].upper() and \
        json['lat'].rstrip('0') == PAYLOAD_SAVE_FULL['lat'].rstrip('0') and \
        json['lng'].rstrip('0') == PAYLOAD_SAVE_FULL['lng'].rstrip('0') and \
        int(json['total']) == PAYLOAD_SAVE_FULL['total'] and \
        int(json['available']) == 10:
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

print "\nGet Nodes Near Position"
print "=============================="

# ######################################## #
print "Get Nodes Near Position (nodes exist nearby)"

lat = PAYLOAD_SAVE_FULL['lat']
lng = PAYLOAD_SAVE_FULL['lng']
distance = 1

r = requests.get(CONFIG_BASE_URL + "nodes/{0}/{1}/{2}".format(lat, lng, distance))
json = r.json()

if len(json) == 1:
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Get Nodes Near Position (no nodes nearby)"

lat = 0
lng = 0
distance = 1

r = requests.get(CONFIG_BASE_URL + "nodes/{0}/{1}/{2}".format(lat, lng, distance))
json = r.json()

if len(json) == 0:
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

print "\nDelete Node"
print "=============================="

PAYLOAD_DELETE = {
            'id': u'CCCC1',
            'api_key': CONFIG_API_KEY_BAD
          }

# ######################################## #
print "Delete with bad API key"

PAYLOAD_DELETE['api_key'] = CONFIG_API_KEY_BAD
r = requests.post(CONFIG_BASE_URL + "nodes/delete", data = PAYLOAD_DELETE)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "API Key Fail":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Delete with half API key"

PAYLOAD_DELETE['api_key'] = CONFIG_API_KEY_HALF
r = requests.post(CONFIG_BASE_URL + "nodes/delete", data = PAYLOAD_DELETE)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "API Key Fail":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Delete with full API key"

PAYLOAD_DELETE['api_key'] = CONFIG_API_KEY_FULL
r = requests.post(CONFIG_BASE_URL + "nodes/delete", data = PAYLOAD_DELETE)
json = r.json()

if json['success'] == "TRUE":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

# ######################################## #
print "Delete node that doesn't exist"

PAYLOAD_DELETE['api_key'] = CONFIG_API_KEY_FULL
r = requests.post(CONFIG_BASE_URL + "nodes/delete", data = PAYLOAD_DELETE)
json = r.json()

if json['success'] == "FALSE" and json['error_message'] == "Node not found!":
    print "PASS"
    RESULT_PASS_COUNT += 1
else:
    print "FAIL\n", r.json()
    RESULT_FAIL_COUNT += 1
# ######################################## #

print "\n"
print "Results"
print "=============================="
print "Total tests: ", RESULT_PASS_COUNT+RESULT_FAIL_COUNT
print "Tests passed:", RESULT_PASS_COUNT
print "Tests failed:", RESULT_FAIL_COUNT
