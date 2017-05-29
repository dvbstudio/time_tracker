import QtQuick 2.4
import QtQml 2.2

SiginForm {

    Timer {
        id: timer
        interval: 3000
        repeat: false
        onTriggered: function() {
            mainWindow.showFromQml()
            application.isVisiblePage = false
            application.close()
        }
    }

    forgetPassClicked.onClicked: function(){
        var link = "http://www.google.com"
        console.log("open externally " + link)
        Qt.openUrlExternally(link)
    }

    signin.onClicked: {
        page.state = "connecting"
        /*
        var request = new XMLHttpRequest()
        request.open('POST', 'https://api..com')
        request.onreadystatechange = function() {
            if (request.readyState === XMLHttpRequest.DONE) {
                if (request.status && request.status === 200) {
                    console.log("response", request.responseText)
                    var result = JSON.parse(request.responseText)
                    page.data = result.response
                } else {
                    console.log("HTTP:", request.status, request.statusText)
                }
            }
        }
        request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
        request.send('fields=<p>&uid=%1'.arg(main.userId))
*/
        timer.start()
    }
}
