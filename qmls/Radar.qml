import QtQuick
import SpellScaper as SpellScaper

SpellScaper.Radar
{
    width: 500
    height: 500

    Image
    {
        id: radarNoise
        source: "qrc:/images/RadarNoise.png"
        visible: false
    }
    ShaderEffect
    {
        id: fx
        property real time
        NumberAnimation on time
        {
            from: 0
            to: 1
            duration: 3000
            loops: Animation.Infinite
        }

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

        property variant noiseTex: radarNoise

        anchors.fill: parent
        vertexShader: "qrc:/shaders/Radar.vert.qsb"
        fragmentShader: "qrc:/shaders/Radar.frag.qsb"
    }
}

