$(function() {
    jQuery.ajaxSetup({async:false});

    getNodes(38.5605020, -121.4211, 50, 13);
    getNodes(38.5605020, -121.4211, 5, 11);
    getNodes(38.5605020, -121.4211, 1, 9);
    getNodes(38.5605020, -121.4211, .1, 5);
    getNodes(30.56, 21.4211, 0, 0);

    //var regex = new RegExp(/this is the response/g);
    //var result = regex.test(allNodes) ? "PASS" : "FAIL"
});
/*
    Test Cases
    ==========
*/

/*
    Get Nodes Near Position
    GET: /nodes/:lat/:lng/:distance
    
    Compares number of nodes returned to expectedCount
    
    parameter       description
    lat             Latitude position    
    lng             Longitude position
    radius          Radius in miles
    expectedCount   Expected number of nodes inside this boundary
*/
function getNodes(lat, lng, radius, expectedCount) {
    var response;
    
    $.get(BASE_URL + "/nodes/{0}/{1}/{2}".format(lat,lng,radius), function(response) {
        response = $.parseJSON(response);
        
        result = response.length == expectedCount;
        conditions = "({0}, {1}) {2} mi radius.".format(lat,lng,radius);
        expected = expectedCount;
        actual = response.length;
        
        displayResult("Get Nodes", conditions, expected, actual, result);
    }).fail(function() {
        response = null;
    });
}


/*
    Supporting Functions
    ====================
*/
function displayResult(title, conditions, expected, actual, result) {
    var cardTemplate = $("#testTemplate").html();
    var template = cardTemplate.format(title, conditions, expected, actual, result ? "PASS" : "FAIL", result ? "pass" : "fail");
    
    $("#results").append(template);
    
    
    increment("total");
    increment(result ? "pass" : "fail")
}

function increment(id) {
    el = $("#summary #" + id);
    var num = parseInt(el.text());
    el.text(num+1);
}

/*
    String Format function from http://stackoverflow.com/questions/610406/javascript-equivalent-to-printf-string-format/4673436#4673436
*/
String.prototype.format = function() {
    var args = arguments;
    return this.replace(/{(\d+)}/g, function(match, number) { 
        return typeof args[number] != 'undefined'
            ? args[number]
            : match
        ;
    });
};

function sleep(milliseconds) {
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++) {
    if ((new Date().getTime() - start) > milliseconds){
      break;
    }
  }
}