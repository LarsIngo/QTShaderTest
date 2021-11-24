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

    ImageFX {
        anchors.fill: parent
        source: "qrc:/images/spellscaper.png"
        vertexShader: "qrc:/shaders/wiggleblender.vert.qsb"
        fragmentShader: "qrc:/shaders/wiggleblender.frag.qsb"
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1920}
}
##^##*/
