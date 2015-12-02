
import QtQuick 2.5
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Rectangle{
    /*http://tieba.baidu.com/cgi-bin/genimg?captchaservice*/
    id : vcCodeRoot

    width : 240; height: 380;
    color : Qt.rgba(0.1,0.1,0.1,0.3)
    border.width: 0

    signal addItem( int itemID );
    signal removeItem(  ) ;
    function setItem( itemID,imageSource ){
        if( vcCodeRoot.visible === false ){ vcCodeRoot.visible = true; }
        switch(itemID){
            case 0:image_0.source = imageSource ;break;
            case 1:image_1.source = imageSource ;break;
            case 2:image_2.source = imageSource ;break;
            case 3:image_3.source = imageSource ;break;
            case 4:vcodeID.source = imageSource ;break;
        }
    }

    ColumnLayout {
        spacing: 0
        RowLayout {
            spacing: 0

            Image {
                id: image_0
                Layout.maximumHeight: 60;
                Layout.maximumWidth: 60;
                Layout.preferredHeight: 60;
                Layout.preferredWidth: 60;
                source: ""
                cache : false
            }

            Image {
                id: image_1
                Layout.maximumHeight: 60;
                Layout.maximumWidth: 60;
                Layout.preferredHeight: 60;
                Layout.preferredWidth: 60;
                source: ""
                cache : false
            }

            Image {
                id: image_2
                Layout.maximumHeight: 60;
                Layout.maximumWidth: 60;
                Layout.preferredHeight: 60;
                Layout.preferredWidth: 60;
                source: ""
                cache : false
            }

            Image {
                id: image_3
                Layout.maximumHeight: 60;
                Layout.maximumWidth: 60;
                Layout.preferredHeight: 60;
                Layout.preferredWidth: 60;
                source: ""
                cache : false
            }
        }


        Image{
            id : vcodeID /*验证码*/
            width:  240
            height: 320
            source: ""
            cache : false
            Layout.maximumHeight: 320;
            Layout.maximumWidth: 240;
            Layout.preferredHeight: 320;
            Layout.preferredWidth: 240;

            MouseArea{
                id : vc_show_ID
                anchors.top: parent.top
                anchors.left: parent.left
                width: parent.width
                height:(parent.height - parent.width)
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.removeItem(  ) ;   }
            }
            MouseArea{
                id : vc_0_ID
                anchors.top:vc_show_ID.bottom ; anchors.left: vc_show_ID.left
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 0 );   }
            }
            MouseArea{
                id : vc_3_ID
                anchors.top:vc_0_ID.bottom ; anchors.left: vc_show_ID.left
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 3 );   }
            }
            MouseArea{
                id : vc_6_ID
                anchors.top:vc_3_ID.bottom ; anchors.left: vc_show_ID.left
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 6 );   }
            }

            MouseArea{
                id : vc_1_ID
                anchors.top:vc_show_ID.bottom ; anchors.left: vc_0_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 1 );   }
            }
            MouseArea{
                id : vc_4_ID
                anchors.top:vc_0_ID.bottom ; anchors.left: vc_3_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 4 );   }
            }
            MouseArea{
                id : vc_7_ID
                anchors.top:vc_3_ID.bottom ; anchors.left: vc_6_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 7 );   }
            }

            MouseArea{
                id : vc_2_ID
                anchors.top:vc_show_ID.bottom ; anchors.left: vc_1_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 2 );   }
            }
            MouseArea{
                id : vc_5_ID
                anchors.top:vc_0_ID.bottom ; anchors.left: vc_4_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 5 );   }
            }
            MouseArea{
                id : vc_8_ID
                anchors.top:vc_3_ID.bottom ; anchors.left: vc_7_ID.right
                width: parent.width/3;height: parent.width/3;
                acceptedButtons: Qt.LeftButton
                onClicked: { vcCodeRoot.addItem( 8 );   }
            }
        }
    }

}

/*
*/
