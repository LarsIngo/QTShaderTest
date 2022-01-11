import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Ping
{
    id: root
    width: 512
    height: 512

    // Color of the wave.
    property real r: 1
    property real g: 1
    property real b: 1

    // The icon.
    property string icon

    // Shader effect applied to the following image.
    ShaderEffect
    {
        // Time variable going from 0 to 1 over 3 seconds.
        property real time
          NumberAnimation on time
          {
            from: 0
            to: 1
            duration: 3000
          }

        // Width of the wave.
        property real threshold: 0.01

        // Color of the wave from root.
        property real r: root.r
        property real g: root.g
        property real b: root.b

        // Fill parent.
        anchors.fill: parent

        // Load shaders.
        vertexShader: "qrc:/shaders/Ping.vert.qsb"
        fragmentShader: "qrc:/shaders/Ping.frag.qsb"
    }

    Image
    {
        // Fades the opacity of the ping over time.
        NumberAnimation on opacity
        {
            from: 1
            to: 0
            duration: 3000
        }

        // Size and position.
        width: root.width / 8.0;
        height: root.height / 8.0;
        x: root.width * 0.5 - this.width * 0.5
        y: root.height * 0.5 - this.height * 1.0

        // Icon from root.
        source: root.icon
    }
}
