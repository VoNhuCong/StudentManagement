import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Item {
    id: idStudentList
    width: 1080
    height: 600

    ToolBar {
        id: toolBarTop
        width: parent.width
            RowLayout {
                anchors.fill: parent
                width: parent.width
                ToolButton {
                    text: qsTr("Back")
                    //onClicked: stack.pop()
                }
                Label {
                    text: "Students List"
                    elide: Label.ElideRight
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                }
                ToolButton {
                    text: qsTr("Exit")
                    onClicked: Qt.quit()
                }
            }
    }

    ToolBar {
        id: toolBarBottom
        width: parent.width
        y: parent.height - 30
            RowLayout {
                anchors.fill: parent
                width: parent.width
                ToolButton {
                    id: ddd
                    text: qsTr("New Student")
                    onClicked: popupCreateStudent.open()
                }
                Label {
                    text: ""
                    elide: Label.ElideRight
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                }
                ToolButton {
                    text: qsTr("Clear All")
                    onClicked: Qt.quit()
                }
        }
    }

    Rectangle {
        id: studentsInforLabel
        x: 0
        y: toolBarTop.height
        width: parent.width
        height: 60
        Text {
            x: 10
            text: "Id"
            font.pixelSize: 32
        }
        Text {
            x: parent.width/4 - 100
            text: "Name"
            font.pixelSize: 32
        }
        Text {
            x: parent.width/2
            text: "Date"
            font.pixelSize: 32
        }
        Text {
            x: parent.width*3/4
            text: "Graduate"
            font.pixelSize: 32
        }
    }

    ListView {
        id: idListView
        y: toolBarTop.height + 50
        width: 1080
        height: 600 - toolBarTop.height - toolBarBottom.height
        clip: true

        Rectangle {
            color: "white"
            radius: 10
            anchors.fill: parent
            anchors.rightMargin: 0
            opacity: 0.3
        }

        Text {
            id: idNotify
            anchors.centerIn: parent
            text: "No Student"
            font.pixelSize: 42
            color: "black"
            opacity: 0.7
            visible: Teacher.studentList.length === 0
        }
        model: Teacher.studentList
        delegate:
            Rectangle {
            id: studentsRec
            x:0
            width: idListView.width
            height: 60
            //radius: 10
            border {
                width: 2
                color: "gray"
            }
            Text {
                id:  idStudentListView
                x: 10
                text: modelData.studentId
                font.pixelSize: 32
                color: "black"
            }
            Text {
                id: nameStudentListView
                x: parent.width/4 - 100
                text: modelData.studentName
                font.pixelSize: 32
                color: "black"
            }
            Text {
                id: dateStudentListView
                x: parent.width/2
                text: modelData.studentDate
                font.pixelSize: 32
                color: "black"
            }
            Text {
                id: graduateStudentListView
                x: parent.width*3/4
                text: modelData.studentGraduate
                font.pixelSize: 32
                color: "black"
            }

        }
    }
    // -----------------------POPUP CREATE STUDENT-----------------------//
    Popup {
        id: popupCreateStudent
        anchors.centerIn: parent
        x: parent.width/2
        y: parent.height/2
        width: 600
        height: 400
        modal: true
        focus: true
        closePolicy: popupCreateStudent.CloseOnEscape | popupCreateStudent.CloseOnPressOutsideParent


        RowLayout {
            x: parent.width/2 - 50
            y: parent.height - 30
            Button {
                text: "Create Student"
                onClicked: {
                    console.log("CreateStudent with Id", indexStudentBoxInput.text, ", Name: ", nameStudentInput.text)
                    Teacher.createNewStudent(indexStudentBoxInput.text, nameStudentInput.text , dateStudentInput.text, graduateStudentInput.text);
                }
            }
            Button {
                text: "Cancel"
                onClicked: popupCreateStudent.close()
            }
        }

        // name box of pupup
        Text {
            id: indexStudent
            width: 100
            height: 50
            x: popupCreateStudent.width*0.4 - 200
            y: popupCreateStudent.height*0.1
            font.pixelSize: 32
            text: "Index: "
        }

        Rectangle {
            id: indexStudentBox
            width: 300
            height: 50
            x: popupCreateStudent.width*0.4
            y: popupCreateStudent.height*0.1
            border.color: "grey"
            border.width: 5
            TextInput {
                id: indexStudentBoxInput
                text: ""
                anchors.centerIn: parent
                font.pixelSize: 32
            }

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: -22
                anchors.bottomMargin: -7
                anchors.leftMargin: 22
                anchors.topMargin: 8
                onClicked: {
                    indexStudentBoxInput.forceActiveFocus()
                }
            }
        }

        // input name box of popup
        Text {
            id: nameStudentLabel
            width: 100
            height: 50
            x: popupCreateStudent.width*0.4 - 200
            y: popupCreateStudent.height*0.1 + 60
            font.pixelSize: 32
            text: "Name: "
        }

        Rectangle {
            id: nameStudent
            width: 300
            height: 50
            x: popupCreateStudent.width*0.4
            y: popupCreateStudent.height*0.1 + 60
            border.color: "grey"
            border.width: 5
            TextInput {
                id: nameStudentInput
                text: ""
                anchors.centerIn: parent
                font.pixelSize: 32
            }

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: -22
                anchors.bottomMargin: -7
                anchors.leftMargin: 22
                anchors.topMargin: 8
                onClicked: {
                    nameStudentInput.forceActiveFocus()
                }
            }
        }

        // input date box of popup
        Text {
            id: dateStudentLabel
            width: 100
            height: 50
            x: popupCreateStudent.width*0.4 - 200
            y: popupCreateStudent.height*0.1 + 120
            font.pixelSize: 32
            text: "Date: "
        }

        Rectangle {
            id: dateStudent
            width: 300
            height: 50
            x: popupCreateStudent.width*0.4
            y: popupCreateStudent.height*0.1 + 120
            border.color: "grey"
            border.width: 5
            TextInput {
                id: dateStudentInput
                text: ""
                anchors.centerIn: parent
                font.pixelSize: 32
            }

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: -22
                anchors.bottomMargin: -7
                anchors.leftMargin: 22
                anchors.topMargin: 8
                onClicked: {
                    dateStudentInput.forceActiveFocus()
                }
            }
        }

        // graduate box of popup
        Text {
            id: graduateStudentLabel
            width: 100
            height: 50
            x: popupCreateStudent.width*0.4 - 200
            y: popupCreateStudent.height*0.1 + 180
            font.pixelSize: 32
            text: "Graduate: "
        }

        Rectangle {
            id: graduateStudent
            width: 300
            height: 50
            x: popupCreateStudent.width*0.4
            y: popupCreateStudent.height*0.1 + 180
            border.color: "grey"
            border.width: 5
            TextInput {
                id: graduateStudentInput
                text: ""
                anchors.centerIn: parent
                font.pixelSize: 32
            }

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: -22
                anchors.bottomMargin: -7
                anchors.leftMargin: 22
                anchors.topMargin: 8
                onClicked: {
                    graduateStudentInput.forceActiveFocus()
                }
            }
        }
        // message of popup
        Item
        {
            id: messPopupBox
            x: graduateStudentLabel.x
            y: popupCreateStudent.height*0.1 + 180 + 60
            Text {
                id: idMess
                font.pixelSize: 32
                text: qsTr("Message: ")
            }
            Rectangle
            {
                id: contentMessPopupBox
                Text {
                    id: contentTextMessPopupBox
                    font.pixelSize: 32
                    x: 200
                    text: ""
                }
            }

        }

    }
}

