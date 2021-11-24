import QtQuick 2.0

Image {
    id: img;
    property string vertexShader
    property string fragmentShader

    ShaderEffect
    {
        property variant src: img
        width: img.width; height: img.height
        vertexShader: img.vertexShader
        fragmentShader: img.fragmentShader
    }
}
