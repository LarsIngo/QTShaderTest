import QtQuick
import SpellScaper as SpellScaper

SpellScaper.PingController
{
    id: root
    width: 256
    height: 256
    property int pingType

    Image
    {
        id: colorTex
        visible: false
        source: "qrc:/images/PingControllerColor.png"
    }

    Image
    {
        id: maskTex
        visible: false
        source: "qrc:/images/PingControllerMask.png"
    }

    ShaderEffect
    {
        property variant colorTex: colorTex
        property variant maskTex: maskTex
        property int pingType: root.pingType

        anchors.fill: parent
        vertexShader: "qrc:/shaders/PingController.vert.qsb"
        fragmentShader: "qrc:/shaders/PingController.frag.qsb"
    }
}
