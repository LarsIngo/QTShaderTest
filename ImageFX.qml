import QtQuick 2.0

Image {
    property string vertexShader
    property string fragmentShader

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

        property variant src: parent
        width: parent.width;
        height: parent.height
        vertexShader: parent.vertexShader
        fragmentShader: parent.fragmentShader
    }
}
