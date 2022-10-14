import QtQuick
import SpellScaper as SpellScaper
import QtMultimedia

// [Source]
// https://doc.qt.io/qt-5/qtmultimedia-multimedia-video-qmlvideofx-example.html

Rectangle
{
    anchors.fill: parent

    MediaPlayer {
        id: mediaPlayer
        source: "qrc:/media/PingVideo.mp4"
        audioOutput: AudioOutput {}
        videoOutput: videoOutput
    }

    VideoOutput {
        id: videoOutput
    }

    MouseArea {
        anchors.fill: parent
        onPressed: mediaPlayer.play();
    }

    // Shader which creates the radar effect.
    ShaderEffect
    {
        // The noise texture.
        property variant noiseTex: Image { source: "qrc:/images/RadarNoise.png" }

        property variant videoTex:  ShaderEffectSource { sourceItem: videoOutput; hideSource: true }

        property real time: 0
        SequentialAnimation on time
        {
            loops: Animation.Infinite

            NumberAnimation
            {
                from: 0
                to: 1
                duration: 1000
            }

            NumberAnimation
            {
                from: 1
                to: 0
                duration: 1000
            }
        }
        anchors.fill: videoOutput

        // Loads the shaders.
        vertexShader: "qrc:/shaders/vfx.vert.qsb"
        fragmentShader: "qrc:/shaders/vfx.frag.qsb"
    }
}
