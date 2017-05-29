import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Rectangle {
    id: page
    width: 320
    height: 480
    color: "#eae3e3"
    property alias signin: signin
    property alias page: page
    property alias forgetPass: forgetPass
    property alias forgetPassClicked: forgetPassClicked

    signal start()

    Image {
        id: toTray
        x: 74
        y: 76
        width: 178
        height: 96
        //        source: "icons/navigation_close.svg"
    }

    Button {
        id: signin
        x: 40
        y: 307
        width: 241
        height: 40
        Layout.fillWidth: true
        text: qsTr("Login")
    }

    DropShadow {
        id: dropShadowSignin
        anchors.fill: signin
        horizontalOffset: 5
        verticalOffset: 5
        radius: 10.0
        samples: 17
        color: "#80000000"
        source: signin
    }

    TextField {
        id: password
        x: 40
        y: 252
        width: 241
        height: 38
        Layout.fillWidth: true
        placeholderText: qsTr("password")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Times New Roman"
        font.pixelSize: 14
        echoMode: TextInput.Password
        style: TextFieldStyle {
            textColor: "black"
            background: Rectangle { color: "white" }
        }
    }

    DropShadow {
        id: dropShadowPassword
        anchors.fill: password
        horizontalOffset: 5
        verticalOffset: 5
        radius: 10.0
        samples: 17
        color: "#80000000"
        source: password
    }

    TextField {
        id: username
        x: 40
        y: 191
        width: 241
        height: 40
        placeholderText: "username or email"
        horizontalAlignment: Text.AlignHCenter
        Layout.fillWidth: true
        font.family: "Times New Roman"
        font.pixelSize: 14
        style: TextFieldStyle {
            textColor: "black"
            background: Rectangle { color: "white" }
        }
    }

    DropShadow {
        id: dropShadowUsername
        anchors.fill: username
        horizontalOffset: 5
        verticalOffset: 5
        radius: 10.0
        samples: 17
        color: "#80000000"
        source: username
    }

    BusyIndicator {
        id: busyIndicator
        x: 130
        y: 279
        opacity: 0
    }

    Text {
        id: forgetPass
        x: 107
        y: 368
        width: 112
        height: 14
        text: qsTr("Forget passwords?")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
        wrapMode: Text.WrapAnywhere

        MouseArea {
            id: forgetPassClicked
            anchors.fill: parent
            cursorShape: forgetPass.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
        }

    }

    states: [
        State {
            name: "connecting"

            PropertyChanges {
                target: username
                visible: false
            }

            PropertyChanges {
                target: password
                visible: false
            }

            PropertyChanges {
                target: signin
                visible: false
            }

            PropertyChanges {
                target: busyIndicator
                x: 109
                y: 271
                width: 103
                height: 98
                opacity: 1
            }

            PropertyChanges {
                target: page
                transformOrigin: Item.Right
            }

            PropertyChanges {
                target: forgetPassClicked
                visible: false
            }

            PropertyChanges {
                target: forgetPass
                visible: false
            }

            PropertyChanges {
                target: dropShadowUsername
                visible: false
            }

            PropertyChanges {
                target: dropShadowPassword
                visible: false
            }

            PropertyChanges {
                target: dropShadowSignin
                visible: false
            }
        }
    ]





}
