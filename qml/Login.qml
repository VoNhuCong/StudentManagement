import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: idFull
        width: 1080
        height: 800
        Rectangle{
            id: idForm
            width: 700
            height: 650
            color: "transparent"
            anchors{
                verticalCenter: idFull.verticalCenter
                horizontalCenter: idFull.horizontalCenter
            }

            Item {
                id: idAcc
                Text {
                    id: idAccGuideText
                    width: 200
                    font.pixelSize: 32
                    text: "Account: "
                }
                Rectangle {
                    width: 500
                    height: 50
                    border.color: "grey"
                    border.width: 5
                    anchors.left: idAccGuideText.right
                    TextInput {
                        id: idAccInput
                        anchors.centerIn: parent
                        font.pixelSize: 32
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            idAccInput.forceActiveFocus()
                        }
                    }
                }
            }

            Item {
                id: idPassword
                anchors {
                    top:idAcc.bottom
                    topMargin: 100
                }

                Text {
                    id: idPassWordGuideText
                    width: 200
                    font.pixelSize: 32

                    text: "Password: "
                }

                Rectangle {
                    id: passwordBox
                    width: 500
                    height: 50
                    border.color: "grey"
                    border.width: 5
                    anchors.left: idPassWordGuideText.right

                    TextInput {
                        id: idPassWordInput
                        text: ""
                        echoMode: TextInput.Password
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
                            idPassWordInput.forceActiveFocus()
                        }
                    }

                    Button {
                        id: idPassShowHide
                        anchors {
                            right: passwordBox.right
                            verticalCenter: passwordBox.verticalCenter
                        }
                        icon.name: "showHidePass"
                        icon.source: "/resource/ShowPassIcon.png"
                        icon.width: 36
                        icon.height: 36
                        icon.color: "transparent"
                        //                enabled: idPassWordInput.text != ""
                        onClicked: {
                            if(icon.source == "/resource/ShowPassIcon.png"){
                                icon.source = "/resource/HidePassIcon.png"
                                idPassWordInput.echoMode = 0
                                idPassWordInput.echoMode = TextInput.Nomal //Show Pass
                            }
                            else{
                                icon.source = "/resource/ShowPassIcon.png"
                                idPassWordInput.echoMode = TextInput.Password //Hide Pass
                            }
                        }
                    }
                    //End Button
                }
            }

            Rectangle {
                id: idLoginButton
                width: 700
                height: 50
                anchors {
                    top:idPassword.bottom
                    topMargin: 200
                }
                color: idLoginButtonMouse.pressed? "blue": "green"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 32
                    color: "white"
                    text: "Login"
                }

                MouseArea {
                    id: idLoginButtonMouse
                    anchors.fill: parent

                    onClicked: {
                        console.log("Login acc: ", idAccInput.text, ", pass: ", idPassWordInput.text)
                        // check login information
                        AppControl.checkLogin(idAccInput.text, idPassWordInput.text)
                        // show login state
                        idMessBox1.text = AppControl.checkMessBox()
                        idPassWordInput.text = ""
                    }
                }
            }

            Rectangle {
                id: idCreateAccButton
                width: 700
                height: 50
                anchors {
                    top:idLoginButton.bottom
                    topMargin: 30
                }
                color: idCreateAccButtonMouse.pressed? "blue": "green"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 32
                    color: "white"
                    text: "Register"
                }

                MouseArea {
                    id: idCreateAccButtonMouse
                    anchors.fill: parent
                    onClicked: {
                        console.log("Register acc: ", idAccInput.text, ", pass: ", idPassWordInput.text)
                        AppControl.checkCreateAccout(idAccInput.text, idPassWordInput.text)
                        idMessBox1.text = AppControl.checkMessBox()
                    }
                }
            }

            Item
            {
                id: messBox
                width: 200
                x: idPassword.x
                y: 200
                Text {
                    id: idMess
                    font.pixelSize: 32
                    text: qsTr("Message: ")
                }
                Rectangle
                {
                    id: idMessBox
                    Text {
                        id: idMessBox1
                        font.pixelSize: 32
                        x: 200
                        text: "Ready"
                    }
                }

            }
        }
}
