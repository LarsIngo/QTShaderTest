import QtQuick
import SpellScaper as SpellScaper

SpellScaper.PingController
{
    id: root
    width: 256
    height: 256

    // Type of ping.
    property int pingType

    // The ping controller image.
    Image
    {
        id: colorTex
        visible: false
        source: "qrc:/images/PingControllerColor.png"
    }

    // The mask of the ping controller (used to highlight specific areas of the colorTex).
    Image
    {
        id: maskTex
        visible: false
        source: "qrc:/images/PingControllerMask.png"
    }

    // The shader highlighting specific areas based on ping type.
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
