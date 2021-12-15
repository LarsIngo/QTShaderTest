import QtQuick 2.0

Item {
    width: 500
    height: 500

    Image {
        id: radarNoise
        source: "qrc:/images/radarNoise.png"
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
            easing: easing.type.OutExpo
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
                easing: easing.Linear
            }

            NumberAnimation
            {
                from: 10
                to: 0
                duration: 1300
                easing: easing.Linear
            }
        }

        property variant noiseTex: radarNoise

        anchors.fill: parent
        vertexShader: "qrc:/shaders/radar.vert.qsb"
        fragmentShader: "qrc:/shaders/radar.frag.qsb"
    }
}

