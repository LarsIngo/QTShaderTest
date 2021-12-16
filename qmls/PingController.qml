import QtQuick
import SpellScaper as SpellScaper

SpellScaper.PingController
{
    id: root
    width: 256
    height: 256
    property point targetPos
    property point target

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
        //property color color: Qt.color(0,1,0)
        property point rootPos: Qt.point(root.x + root.width * 0.5, root.y + root.height * 0.5)
        property point targetPos: root.targetPos
        property point target: root.target

        anchors.fill: parent
        vertexShader: "qrc:/shaders/PingController.vert.qsb"
        fragmentShader: "qrc:/shaders/PingController.frag.qsb"
    }
}
