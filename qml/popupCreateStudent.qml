import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

ListView {
    id: idListView
    y: 80
    width: 1080
    height: 720 - 80
    clip: true

    Rectangle {
        color: "grey"
        radius: 10
        anchors.fill: parent
        anchors.rightMargin: 0
        opacity: 0.3
    }

    Text {
        id: idNotify
        anchors.centerIn: parent
        text: "No album added"
        font.pixelSize: 42
        color: "white"
        opacity: 0.7
        visible: User.listAlbum.length === 0
    }
    model: User.listAlbum
    delegate:
        Rectangle {
        id: albumRec
        x:0
        width: idListView.width
        height: 80
        radius: 10
        border {
            width: 5
            color: "yellow"
        }

        Text {
            x: 10
            text: modelData.albumName //binding
            font.pixelSize: 32
            color: "blue"
        }
        Text {
            id: idTextDateCreateAlbum
            x: 10
            y: (parent.height)/2.0
            text: modelData.albumDate
            font.pixelSize: 16
            color: "blue"
        }
        Text {
            id: idText1
            y: (parent.height)/2.0
            anchors.left: idTextDateCreateAlbum.right
            anchors.leftMargin: 5
            text: ", "
            font.pixelSize: 16
            color: "blue"
        }
        Text {
            id: idText2
            y: (parent.height)/2.0
            anchors.left: idText1.right
            text: modelData.albumSize //binding
            font.pixelSize: 16
            color: "blue"
        }
        Text {
            id: idText3
            y: (parent.height)/2.0
            anchors.left: idText2.right
            anchors.leftMargin: 5
            text: "items"
            font.pixelSize: 16
            color: "blue"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                User.openAlbumAt(index);
                AppControl.appScreenId = 2;
            }
        }

        Button {
            id: idDelete
            anchors {
                right: albumRec.right
                rightMargin: 5
                verticalCenter: albumRec.verticalCenter
            }
            icon.name: "Delete Album"
            icon.source: "/images/deleteIcon.png"
            icon.width: 50
            icon.height: 50
            icon.color: "transparent"
            onClicked:{
                User.deleteAlbum(index)

            }
        }
        Button  {
            id: idEdit
            anchors {
                right: idDelete.left
                rightMargin: 5
                verticalCenter: idDelete.verticalCenter
                }
            icon.name: "Change Album Name"
            icon.source: "/images/edit.png"
            icon.width: 50
            icon.height: 50
            icon.color: "transparent"
            onClicked:{
                idReName.visible = true
            }
        }

        Rectangle{
            id: idReName
            width: 455
            height: 50
            color:"transparent"
            anchors{
                right: idEdit.left
                rightMargin: 5
                verticalCenter: idEdit.verticalCenter
            }
            visible: false
            Rectangle {
                id: idAddNewName
                width: 300
                height: 50
                border.color: "grey"
                anchors{
                    left: idReName.left
                    verticalCenter: idReName.verticalCenter
                }
                border.width: 5
                radius: 10
                Text {
                    id: idTextBox2
                    anchors.fill: parent; anchors.leftMargin: 8
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    text: "New name ....."
                    color: "gray"
                    font.italic: true
                }
                TextInput {
                    id: idChangeAlbumNameInput
                    anchors.centerIn: parent
                    font.pixelSize: 32
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        idChangeAlbumNameInput.forceActiveFocus()
                    }
                }

            }
            Rectangle{
                id: idOk
                width: 70
                height: 50
                anchors{
                    left:  idAddNewName.right
                    leftMargin: 5
                    verticalCenter: idAddNewName.verticalCenter
                }
                radius: 12
                color: idMouse1.pressed? "blue": "green"
                Text{
                    anchors.centerIn: parent
                    font.pixelSize: 20
                    text: qsTr("Ok")
                    color: "white"
                }

                MouseArea
                {
                    id: idMouse1
                    anchors.fill: parent

                    onClicked:{
                        User.changeAlbumName(index,idChangeAlbumNameInput.text)
                        idMess.text = User.checkMessBox()
                        idtextnf.text = ""
                        idReName.visible=false
                        idChangeAlbumNameInput.text= ""
                        idAddAlbumNameInput.text= ""
                    }
                }
            }

            Rectangle{
                id: idCancel
                width: 70
                height: 50
                anchors{
                    left: idOk.right
                    leftMargin: 5
                    verticalCenter: idOk.verticalCenter
                }
                radius: 12
                color: idMouse2.pressed? "grey": "red"
                Text{
                    anchors.centerIn: parent
                    font.pixelSize: 20
                    text: qsTr("Cancel")
                    color: "white"
                }
                MouseArea
                {
                    id: idMouse2
                    anchors.fill: parent
                    onClicked: idReName.visible = false
                }
            }
            states: State {
                name: "hasText"; when: idChangeAlbumNameInput.text !== ''
                PropertyChanges { target: idTextBox2; opacity: 0 }
                PropertyChanges { target: clear; opacity: 1 }
            }

          }

        }

    }
