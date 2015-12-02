﻿
import QtQuick 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Rectangle{

    width : 512; height: 512;


    ColumnLayout {
        anchors.fill: parent
        x: 40
        y: 153
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
