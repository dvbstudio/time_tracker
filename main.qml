import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import "systemTray"

ApplicationWindow {
    id: application
    visible: true
    flags: "FramelessWindowHint"
    width: 320
    height: 480

    property alias application: application
    property int headerHeight: 32
    property int buttonSize: 30
    property int x_0: 0
    property int y_0: 0
    property bool isVisiblePage: true

    Sigin {
        id: page
        anchors.fill: parent
    }

    ToolBar{
        id: customHeader
        x: 0
        y: 0
        width: parent.width
        height: headerHeight
        MouseArea {
            id: headerControl
            anchors.fill: parent

            onPressed: {
                x_0 = mouse.x
                y_0 = mouse.y
            }

            onPositionChanged: {
                application.x += mouse.x - x_0
                application.y += mouse.y - y_0
            }
        }


        ToolButton {
            id: toTrayButton
            anchors.right: closeBatton.left
            anchors.margins: 1
            width: buttonSize
            height: buttonSize
            iconSource: "icons/to_tray.png"

            onClicked: {
                close.accepted = false
                application.hide()
            }
        }

        ToolButton {
            id: closeBatton
            anchors.right: parent.right
            anchors.margins: 1
            width: buttonSize
            height: buttonSize
            iconSource: "icons/close.png"

            onClicked: {
                application.close()
                Qt.quit()
            }
        }

    }

    SystemTrayControl {}

}
