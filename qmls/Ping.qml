import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Ping {
    width: 500
    height: 500

    ShaderEffect
    {
        property real time
          NumberAnimation on time {
            from: 0
            to: 1
            duration: 3000
            loops: Animation.Infinite
            easing: easing.type.OutExpo
          }

        property real alphaOverTime
          NumberAnimation on alphaOverTime {
            from: 0
            to: 1
            duration: 3000
            loops: Animation.Infinite
            easing: easing.type.InExpo
          }

        property real threshold: 0.01

        anchors.fill: parent
        vertexShader: "qrc:/shaders/ping.vert.qsb"
        fragmentShader: "qrc:/shaders/ping.frag.qsb"
    }
}
