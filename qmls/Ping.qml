import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Ping
{
    id: root
    width: 500
    height: 500

    property real r: 0.7
    property real g: 0.2
    property real b: 0.2

    ShaderEffect
    {
        property real time
          NumberAnimation on time
          {
            from: 0
            to: 1
            duration: 3000
          }

        property real threshold: 0.01
        property real r: root.r
        property real g: root.g
        property real b: root.b

        anchors.fill: parent
        vertexShader: "qrc:/shaders/Ping.vert.qsb"
        fragmentShader: "qrc:/shaders/Ping.frag.qsb"
    }
}
