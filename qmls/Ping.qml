import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Ping
{
    width: 500
    height: 500

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

        anchors.fill: parent
        vertexShader: "qrc:/shaders/Ping.vert.qsb"
        fragmentShader: "qrc:/shaders/Ping.frag.qsb"
    }
}
