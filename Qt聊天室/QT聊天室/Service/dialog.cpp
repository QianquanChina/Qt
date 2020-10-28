#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Server=new QTcpServer;
    time=new QTimer;
    startNetwork(10086);
    connect(Server,SIGNAL(newConnection()),this,
            SLOT(ServerNewConnectSlot()));

    connect(time,SIGNAL(timeout()),this,
            SLOT(TimerSendUserListSlot()));

    time->start(1000);
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

Dialog * Dialog::getObject(){
    static    Dialog cs;
    return  &cs;
}

//链接网络
bool Dialog::startNetwork(quint16 port)
{
    closeNetwork();
    return Server->listen(QHostAddress::Any,10086);
}
//断开网络
void Dialog::closeNetwork()
{
    for(int i=0;i<userList.length();i++){
        disconnect(userList.at(i)->Socket,0,0,0);
        delete userList.at(i);
    }
    userList.clear();
    Server->close();
}

bool Dialog::sendDataTo(QString userName, QByteArray data)
{//发送数据到个人
    for(int i=0;i<userList.length();i++){
        if(userList.at(i)->UserName==userName){
            if(userList.at(i)->Socket->write(data)!=-1)
                return true;
            return false;
        }
    }
    return false;
}

bool Dialog::sendDataAll(QByteArray data)
{
    //发送数据到全部
    for(int i=0;i<userList.length();i++)
        userList.at(i)->Socket->write(data);
    return true;
}

void Dialog::logIn(QByteArray data, QTcpSocket *Socket)
{
    QJsonObject obj=QJsonDocument::fromJson(data).object();
    QString from=obj.value("from").toString();
    for(int i=0;i<userList.length();i++){
        if(userList.at(i)->UserName==from){

            sendXTMessage(Socket,0);
            for(int j=0;j<userList.length();j++){
                if(userList.at(j)->Socket==Socket)
                    userList.removeAt(j);
            }
           // delete Socket;
            return ;       //登录失败，昵称重复,主动断开连接。
        }
    }
    for(int i=0;i<userList.length();i++){
        if(userList.at(i)->Socket==Socket){
            userList.at(i)->UserName=from;
            qDebug()<<from;
            sendXTMessage(Socket,1);
            return ;       //登录成功
        }
    }
}
void Dialog::sendXTMessage(QTcpSocket *Socket, int message)
{
    QJsonObject obj;
    obj.insert("type","XITONG");
    obj.insert("message",message);
    Socket->write(QJsonDocument(obj).toJson());
}
//处理客户端连接的槽函数
void Dialog::ServerNewConnectSlot()
{
    QTcpSocket *Socket =Server->nextPendingConnection();

    SocketInfo * info=new SocketInfo;
    info->Socket=Socket;
    info->UserName="";
    userList.append(info);
    connect(Socket,SIGNAL(readyRead()),this,
            SLOT(ServeReadyReadSlot()));


    connect(Socket,SIGNAL(disconnected()),this,
            SLOT(SocketDisConnetSlot()));
}

void Dialog::ServeReadyReadSlot()
{
   QTcpSocket *s=(QTcpSocket *)  sender();

   QByteArray data;
   data.append(s->readAll());
   QJsonObject obj =QJsonDocument::fromJson(data).object();
   QString type=obj.value("type").toString();

   QString str;
   QString from=obj.value("from").toString();
   QString date=obj.value("date").toString();
   QString info=obj.value("info").toString();
   str =tr("%1 %2 send to all \n%3").arg(date).arg(from).arg(info);
   qDebug() << str;
   ui->allText1->append(str);
   if(type=="allinfo")
   {
       sendDataAll(data);
   }

   else if(type=="oneinfo")
   {
       QString userName=obj.value("to").toString();
        qDebug() << userName;
       if(!sendDataTo(userName,data))
           sendXTMessage(s,2);//信息发送失败。

   }
   else if(type=="logininfo"){
       logIn(data,s);
   }

}
void Dialog::SocketDisConnetSlot()
{
    QTcpSocket * s=(QTcpSocket*) sender();

    for(int i=0;i<userList.length();i++){
        if(userList.at(i)->Socket==s)
           { delete userList.at(i);
            userList.removeAt(i);
            }
    }

}

void Dialog::TimerSendUserListSlot()
{
    QString nameList="";
    for(int i=0;i<userList.length();i++){
        nameList.append(userList.at(i)->UserName).append("\n");
    }
       QJsonObject obj;
       obj.insert("type","userlist");
       obj.insert("namelist",nameList);
       QByteArray data=QJsonDocument(obj).toJson();
       for(int i=0;i<userList.length();i++)
       {
       userList.at(i)->Socket->write(data);
    }
}

void Dialog::on_pushButton999_clicked()
{
    QMessageBox box;
    box.setText("服务器创建成功!!");
    box.exec();
}

