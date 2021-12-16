import QtQuick
import SpellScaper as SpellScaper

SpellScaper.PingController
{
    width: 256
    height: 256

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

        anchors.fill: parent
        vertexShader: "qrc:/shaders/PingController.vert.qsb"
        fragmentShader: "qrc:/shaders/PingController.frag.qsb"
    }
}
