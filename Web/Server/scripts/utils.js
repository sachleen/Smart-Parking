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

/*
    Alerts the user of the server's response after an API call
    Parameter       Description
    response        JSON response returned from server
    successMessage  Message to show if response was a "success"
*/
function parseResponse(response, successMessage) {
    parsed = JSON.parse(response);

    if (parsed.success == "TRUE") {
        showMessage("success", successMessage);
    } else {
        showMessage("error", parsed.error_message);
    }
}

/*
    Displays a message to the user using slide down animation
*/
function showMessage(type, message) {
    var div = $("<div>");
    div.addClass(type);
    div.text(message);
    div.hide();
    $("body").append(div);
    div.slideDown(500);
    
    
    setTimeout(function() {
        div.slideUp(500, function() {
            div.remove();
        });
    }, 3000);
}