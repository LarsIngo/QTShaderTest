import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Radar
{
    width: 500
    height: 500

    // The image (noise texture used to create radar effect).
    Image
    {
        id: radarNoise
        source: "qrc:/images/RadarNoise.png"
        visible: false
    }

    // Shader which creates the radar effect.
    ShaderEffect
    {
        // Loops time variable from 0 to 1 every 3 seconds.
        property real time
        NumberAnimation on time
        {
            from: 0
            to: 1
            duration: 3000
            loops: Animation.Infinite
        }

        // Animates radar noise strength over time. First fading it in over 6 seconds, then fading out in 1.3 seconds.
        property real strength: 10
        SequentialAnimation on strength
        {
            loops: Animation.Infinite

            NumberAnimation
            {
                from: 0
                to: 10
                duration: 6000
            }

            NumberAnimation
            {
                from: 10
                to: 0
                duration: 1300
            }
        }

        // The radar noise texture from root.
        property variant noiseTex: radarNoise

        // Fills the parent.
        anchors.fill: parent

        // Loads the shaders.
        vertexShader: "qrc:/shaders/Radar.vert.qsb"
        fragmentShader: "qrc:/shaders/Radar.frag.qsb"
    }
}

