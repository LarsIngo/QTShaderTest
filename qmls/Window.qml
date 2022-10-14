import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Window
{
    width: 1920
    height: 1080
    visible: true
    title: "SpellScaper UI Project Demo"

    Map
    {
    }

    ShaderEffect
    {
        anchors.top: parent.top
        anchors.left: parent.left
        width: 1280 * 0.25;
        height: 939 * 0.25;

        property variant srcTex: ShaderEffectSource
        {
            sourceItem : Image { source: "qrc:/images/Qt_logo.png" }
            hideSource: true
        }

        // Loads the shaders.
        vertexShader: "qrc:/shaders/Qt_logo.vert.qsb"
        fragmentShader: "qrc:/shaders/Qt_logo.frag.qsb"
    }
}
