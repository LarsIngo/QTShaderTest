import QtQuick 2.0

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

    anchors.centerIn: parent
    width: 500
    height: 500
    vertexShader: "qrc:/shaders/ping.vert.qsb"
    fragmentShader: "qrc:/shaders/ping.frag.qsb"
}
