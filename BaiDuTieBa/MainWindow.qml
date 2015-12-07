
import QtQuick 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Rectangle{

    id : root
    objectName: "MainWindowRoot"
    width : 512; height: 512;

    signal signData(  );
    signal postFloorData( string tid,string pid ,string tlocal,string tdata  )
    signal postData( string tid ,string tlocal,string tdata  )
    signal sendData( string ttname ,string ttitle ,string tlocal,string tdata  )
    function setContent( cvar_ ){ tcontentID.text = cvar_ }
    function sendFinished( isok,whynotok ){
        tSendDataID.enabled = true
        if( isok ){ tErrorStringID.text =qsTr("发帖成功 : ")+whynotok /*tid*/ ; }
        else{ tErrorStringID.text = whynotok; }
    }

    BaiDuTieBaVertifyCode{
        id : vcCodeID
        objectName: "VertifyCodeDialog"
        z: 100
        anchors.centerIn: parent
        visible: false
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        RowLayout {
            spacing: 0

            Text {
                id: ttnameLabel
                horizontalAlignment :Qt.AlignRight
                text: qsTr("贴吧名:")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.maximumWidth: 64
                Layout.minimumWidth: 64
                font.pixelSize: 12
            }

            TextField {
                id: ttnameID
                Layout.fillWidth: true
                placeholderText: ""
            }
        }

        RowLayout {
            spacing: 0

            Text {
                id: ttitleLabel
                horizontalAlignment :Qt.AlignRight
                text: qsTr("标题:")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.maximumWidth: 64
                Layout.minimumWidth: 64
                Layout.preferredWidth: 64
                font.pixelSize: 12
            }

            TextField {
                id: ttitleID
                Layout.fillWidth: true
                placeholderText: ""
            }

            Text {
                id: tidLabel
                horizontalAlignment :Qt.AlignRight
                text: qsTr("tid:")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.maximumWidth: 64
                Layout.minimumWidth: 64
                Layout.preferredWidth: 32
                font.pixelSize: 12
            }

            TextField {
                id: tidID
                Layout.fillWidth: true
                placeholderText: "0"
            }

            Text {
                id: pidLabel
                horizontalAlignment :Qt.AlignRight
                text: qsTr("pid:")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.maximumWidth: 64
                Layout.minimumWidth: 64
                Layout.preferredWidth: 32
                font.pixelSize: 12
            }

            TextField {
                id: pidID
                Layout.fillWidth: true
                placeholderText: "0"
            }

        }

        RowLayout {
            spacing: 0

            Text {
                id: tlocalDirLabel
                horizontalAlignment :Qt.AlignRight
                text: qsTr("本地目录:")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.maximumWidth: 64
                Layout.minimumWidth: 64
                Layout.preferredWidth: 64
                font.pixelSize: 12
            }

            TextField {
                id: tlocalDirID
                Layout.fillWidth: true
                placeholderText: ""
            }
        }

        TextArea {
            id: tcontentID
            objectName: "tcontentID"
            font.pointSize: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            textFormat: TextEdit.PlainText
            style: TextAreaStyle {
                textColor: Qt.rgba(0,0,0,1)
                selectionColor: "steelblue"
                selectedTextColor: "#eee"
                backgroundColor: Qt.rgba(0.1,0.1,0.6,0)
            }
        }

        RowLayout {
            spacing: 0
            Button{
                id :tSendDataID
                text: qsTr("发帖")
                Layout.preferredHeight: 24; Layout.preferredWidth: 64
                onClicked: {
                    tidID.text = tidID.text.trim()
                    if( (tidID.text.length  !== 0 ) && ( tidID.text != "0" ) ){
                        tSendDataID.enabled = false
                        vcCodeID.visible = false
                        if( (pidID.text.length  !== 0 ) && ( pidID.text != "0" ) ){
                            root.postFloorData( tidID.text,pidID.text ,tlocalDirID.text,tcontentID.text )
                        }
                        else{
                            root.postData( tidID.text,tlocalDirID.text,tcontentID.text )
                        }
                    }else{
                        tSendDataID.enabled = false
                        vcCodeID.visible = false
                        root.sendData( ttnameID.text,ttitleID.text,tlocalDirID.text,tcontentID.text )
                    }
                }
            }

            Button{
                id :tSignID
                text: qsTr("签到")
                Layout.preferredHeight: 24; Layout.preferredWidth: 64
                onClicked: { root.signData(  ) ; }
            }

            TextField {
                id: tErrorStringID
                text: qsTr("")
                Layout.fillWidth: true
                font.pixelSize: 22
                readOnly : true
            }
        }
    }

}

/*

*/
