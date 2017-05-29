import QtQuick 2.0

Item {
    id: login_frag
    x: 0
    y: header.height
    width: parent.width
    height: parent.height - header.height

    TextEdit {
        id: login_edit
        x: 42
        y: 42
        width: 200
        height: 40
        text: qsTr("Login")
        font.pixelSize: 12
    }

    TextEdit {
        id: pass_edit
        x: 42
        y: 89
        width: 200
        height: 40
        text: qsTr("Password")
        font.pixelSize: 12
    }

    Button {
        id: sigin_btn
        x: 42
        y: 162
        width: 200
        height: 40
        text: qsTr("Sig-in")
        onClicked: body.hidden()
    }

    CheckBox {
        id: rectangle2
        x: 42
        y: 214
        width: 17
        height: 19
    }

    Text {
        id: text1
        x: 82
        y: 214
        width: 160
        height: 19
        text: qsTr("Saved it")
        font.pixelSize: 12
    }

    function hidden() {
        body.height = 0
    }
}
