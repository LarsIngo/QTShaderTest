import QtQuick 2.0
import QtQuick.Window

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hello World")

    /*Rectangle {
        anchors.fill: parent
        color: "green"
    }*/

    Image {
        anchors.fill: parent
        source: "images/map.png"
    }

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

        width: 100;
        height: 100
        vertexShader: "qrc:/shaders/ping.vert.qsb"
        fragmentShader: "qrc:/shaders/ping.frag.qsb"
    }

    ImageFX {
        anchors.centerIn: parent
        //anchors.fill: parent
        source: "qrc:/images/triangle.png"
        vertexShader: "qrc:/shaders/ping.vert.qsb"
        fragmentShader: "qrc:/shaders/ping.frag.qsb"

        /*
        RotationAnimator on rotation {
            from: 0;
            to: 360;
            duration: 1000
            loops: Animation.Infinite
        }

        ScaleAnimator on scale {
            from: 0;
            to: 1;
            duration: 1000
            loops: Animation.Infinite
        }
        */
    }
}

/*##^##
Designer {
    D{i:0;height:1080;width:1920}
}
##^##*/
