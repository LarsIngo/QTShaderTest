import QtQuick 2.0
import QtQuick.Window

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hello World")

    /*Rectangle {
        anchors.fill: parent
        color: "green"
    }*/

   /* Image {
        id: img
        anchors.fill: parent
        source: "images/spellscaper.png"
    }*/

    MyShaderEffect {
        anchors.fill: parent
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1920}
}
##^##*/
