import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QSystemTrayIcon 1.0

Item {
id: systemTrayControl

    QSystemTrayIcon {
        id: systemTrayIcon

        Component.onCompleted: {
            icon = iconTray
            toolTip = "Tray Program"
            show();
        }

        onActivated: {
            if(reason === 1){
                trayMenu.popup()
            } else {}
        }
    }

    Menu {
        id: trayMenu

        MenuItem {
            id: menuItem1
            text: qsTr("Свернуть окно")
            onTriggered:
                function() {
                    if (!isVisiblePage) {
                        if (mainWindow.isVisible) menuItem1.text = qsTr("Развернуть окно")
                        else menuItem1.text = qsTr("Развернуть окно")
                        mainWindow.hideOrShow()
                    } else {
                        if(application.visibility === Window.Hidden) {
                            menuItem1.text = qsTr("Свернуть окно")
                            application.show()
                        }else{
                            menuItem1.text = qsTr("Развернуть окно")
                            application.hide()
                        }
                    }
                }
        }

        MenuItem {
            text: qsTr("Exit")
            onTriggered: {
                systemTrayIcon.hide()
                Qt.quit()
            }
        }
    }
}
