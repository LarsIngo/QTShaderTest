import QtQuick 2.0

Image {
    id: img;
    property string vertexShader
    property string fragmentShader

    ShaderEffect
    {
        property real time
          NumberAnimation on time {
            from: 0
            to: 1
            duration: 1000
            loops: Animation.Infinite
          }

        property variant src: img
        width: img.width; height: img.height
        vertexShader: img.vertexShader
        fragmentShader: img.fragmentShader
    }
}
