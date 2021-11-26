import QtQuick 2.0
import QtQuick.Window

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hello World")

    Image {
        anchors.fill: parent
        source: "qrc:/images/map.png"
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1920}
}
##^##*/
