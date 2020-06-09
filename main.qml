import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window
{
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    TableView
    {
       id: filesTable
       //model: checkpointsModel
       width: parent.width
       height: parent.height
       horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
       style: TableViewStyle
       {
          transientScrollBars: true
          scrollToClickedPosition: true
          itemDelegate: Rectangle
          {
             Text
             {
                anchors.fill: parent
                elide: Text.ElideRight
                text: styleData.value
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
             }
          }
          headerDelegate: Rectangle
          {
             height: 15
             width: filesTable.width / filesTable.columnCount
             border.color: "red"
             radius:4
             Text
             {
                id: filesTableHeaderText
                anchors.fill: parent
                elide: Text.ElideRight
                text: styleData.value
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
             }
          }
          rowDelegate: Rectangle
          {
             width: item.width
             height: item.height
             color:
             {
                var isSelectedRow = filesTable.currentRow === styleData.row;
                var isWhiteRow = styleData.row % 2;
                isSelectedRow ? "lightblue" :
                isWhiteRow ? "white" : "#e0e0e0"
             }
          }
       }
       TableViewColumn
       {
           id: fileName
           title: "Name"
           role: "FileName"
           width: filesTable.width / filesTable.columnCount
       }
       TableViewColumn
       {
           id: fileDate
           title: "Time"
           role: "FileTime"
           width: filesTable.width / filesTable.columnCount
       }
    }
}

