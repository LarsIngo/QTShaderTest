import QtQuick
import QtQuick.Shapes
import SpellScaper as SpellScaper

SpellScaper.Line
{
    width: 500
    height: 500
    anchors.fill: parent

    Shape
    {
         anchors.fill: parent

        ShapePath
        {
            strokeWidth: 4
            strokeColor: "black"
            fillColor: "transparent"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.RoundJoin
            strokeStyle: ShapePath.SolidLine
            dashPattern: [ 1, 4 ]
            startX: 20; startY: 20
            PathLine { x: 180; y: 130 }
            PathLine { x: 20; y: 130 }
            //PathLine { x: 20; y: 20 }
        }
    }
}
