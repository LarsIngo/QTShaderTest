import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Ping
{
    id: root
    width: 512
    height: 512

    property real r: 1
    property real g: 1
    property real b: 1

    property variant icon

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

    Image
    {
        NumberAnimation on opacity
        {
            from: 1
            to: 0
            duration: 3000
        }

        width: root.width / 8.0;
        height: root.height / 8.0;
        anchors.centerIn: parent
        source: root.icon
    }
}
