import QtQuick 2.0

Rectangle
{
    width: 200; height: 100
    Row
    {
        Image { id: img;
            visible: false
            source: "qrc:/images/spellscaper.png"
        }
        ShaderEffect
        {
            property variant src: img
            width: img.width; height: img.height
            vertexShader: "qrc:/shaders/wiggleblender.vert.qsb"
            fragmentShader: "qrc:/shaders/wiggleblender.frag.qsb"
        }
    }
}
