﻿
import QtQuick 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Rectangle{

    id : root
    objectName: "MainWindowRoot"
    width : 512; height: 512;

    signal sendData( string ttname ,string ttitle ,string tlocal,string tdata  )
    function setContent( cvar_ ){ tcontentID.text = cvar_ }
    function sendFinished( isok,whynotok ){
        tSendDataID.enabled = true
        if( isok ){ tErrorStringID.text =qsTr("发帖成功"); }
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
            Layout.fillHeight: true
            Layout.fillWidth: true

        }

        RowLayout {
            spacing: 0
            Button{
                id :tSendDataID
                text: qsTr("发帖")
                Layout.preferredHeight: 24; Layout.preferredWidth: 128
                onClicked: {
                    tSendDataID.enabled = false
                    vcCodeID.visible = false
                    console.log("aaaa")
                    root.sendData( ttnameID.text,ttitleID.text,tlocalDirID.text,tcontentID.text )
                }
            }

            Text {
                id: tErrorStringID
                text: qsTr("")
                Layout.fillWidth: true
                font.pixelSize: 22
            }
        }
    }

}

/*

*/
