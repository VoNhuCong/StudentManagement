import QtQuick 2.5
import QtQuick.Window 2.5
import QtQuick.Controls 2.5

Window {
    width: 1080
    height: 600
    visible: true
    title: qsTr("StudentManagement")

    Login{
        id: idLogin
        visible: AppControl.appScreenId === 0
    }

    StudentList{
        id: idStudentList
        visible: AppControl.appScreenId === 1
    }
}
