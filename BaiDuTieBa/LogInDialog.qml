
import QtQuick 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

MouseArea {

    width: 1024
    height: 1024
    id : mouseAreaID

    property point clickPos: "0,0"
    onPressed: {
        clickPos = Qt.point(mouse.x,mouse.y)
    }

    onPositionChanged: {
        //鼠标偏移量
        var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
        thisDialog.setX(thisDialog.x+delta.x)
        thisDialog.setY(thisDialog.y+delta.y)
    }

    Rectangle{

        id: root
        objectName: "root"

        width : parent.width - 16
        height: parent.height - 16
        anchors.centerIn:  mouseAreaID
        color : Qt.rgba( 0.5,0.5,0.5,0.75 )
        radius: 8

        RectangularGlow {
            id: effect
            anchors.fill: root
            glowRadius: 4
            spread: 0.2
            color: root.color
            cached: false
            cornerRadius: root.radius + glowRadius
        }

        property int rowWidth: width/2.5+50

        /* 接口 */
        signal logIn( string userNameValue,string passWordValue,string verifyCodeValue)
        signal quitLogIn()
        function showVerifyCodeValue( verifyCodeValueUrl ){
            verifyCodeImage.source = verifyCodeValueUrl
            verifyCodeDialogID.visible = true
        }
        function showErrorText( error_text ){
            loginButton.enabled  = true
            errorTextID.text = error_text
            errorTextID.visible = true
        }

        ColumnLayout {
            anchors.centerIn:  parent
            spacing :2

            RowLayout {

                Layout.alignment :Qt.AlignVCenter
                Layout.preferredWidth: root.rowWidth
                Text {
                    id: userName
                    text: qsTr("用户名 :")
                    font.bold: true
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignRight
                    Layout.preferredWidth : 32

                }

                TextField {
                    id: userNameInput
                    text: qsTr("")
                    font.pixelSize: 12
                    Layout.preferredWidth : root.width/2.5
                }

            }

            RowLayout {

                Layout.alignment :Qt.AlignVCenter
                Layout.preferredWidth: root.rowWidth
                Text {
                    id: passWord
                    text: qsTr("密码 :")
                    font.bold : userName.font.bold
                    font.pixelSize : userName.font.pixelSize
                    horizontalAlignment : userName.horizontalAlignment
                    Layout.preferredWidth : 32

                }

                TextField {
                    id: passWordInput;
                    text: qsTr("");
                    font.pixelSize: 12;
                    Layout.preferredWidth : root.width/2.5;
                    echoMode : TextInput.Password;
                }
            }

            ColumnLayout{
                id : verifyCodeDialogID
                spacing: 2
                visible: false
                RowLayout {

                    Layout.preferredWidth: root.rowWidth
                    Layout.alignment :Qt.AlignVCenter
                    Text {
                        id: verifyCode
                        text: qsTr("验证码 :")
                        font.bold : userName.font.bold
                        font.pixelSize : 0
                        horizontalAlignment : userName.horizontalAlignment
                        Layout.preferredWidth : 32
                    }

                    TextField {
                        id: verifyCodeInput
                        placeholderText: qsTr("")
                        font.pixelSize : userName.font.pixelSize
                        Layout.preferredWidth : root.width/2.5
                    }
                }
                Image {
                    id: verifyCodeImage
                    Layout.fillWidth: false
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    source: ""

                }
            }

            RowLayout {

                Layout.alignment :Qt.AlignVCenter
                Layout.preferredWidth: root.rowWidth

                Button {
                    Layout.fillWidth :true
                    id: loginButton
                    text: qsTr("登录")
                    onClicked: {
                        loginButton.enabled = false
                        errorTextID.visible = false
                        errorTextID.text=""
                        root.logIn( userNameInput.text ,passWordInput.text,verifyCodeInput.text )
                    }
                }

                Button {
                    Layout.fillWidth :true
                    id: quitButton
                    text: qsTr("退出")
                    onClicked: {
                        root.quitLogIn()
                    }
                }

            }

            TextArea {
                id: errorTextID
                width: root.rowWidth
                height: 32
                text:  ""
                Layout.preferredHeight: errorTextID.contentHeight
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                clip: true
                Layout.maximumHeight: 128
                font.pointSize: 15
                frameVisible: false
                Layout.fillWidth: true
                backgroundVisible :false
                readOnly : true
                textMargin :2
                menu : null
                selectByMouse :true
                selectByKeyboard : true
                wrapMode : TextEdit.WordWrap
                visible: false
                horizontalScrollBarPolicy : Qt.ScrollBarAlwaysOff
                verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff
            }
        }


    }

}
