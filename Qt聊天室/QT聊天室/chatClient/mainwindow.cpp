#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QJsonValue>
#include<QMessageBox>
#include "logindialog.h"
#include "form.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Socket=new QTcpSocket;
    connect(Socket,SIGNAL(connected()),this,
            SLOT(ConnectSlot()));
    connect(Socket,SIGNAL(readyRead()),this,
            SLOT(ReadyReadSlot()));
    connect(Socket,SIGNAL(disconnected()),this,
            SLOT(DisConnectSlot()));



}
//发送数据函数
void MainWindow::sendData(QByteArray data)
{
    if(Socket->isOpen()){
        Socket->write(data);
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}
//链接按钮槽函数
void MainWindow::on_btn_Connect_clicked()
{
    QString userName=ui->leUserName->text();
    if(userName=="")return;
    Socket->connectToHost(ui->leIP->text(),
                          ui->lePort->text().toInt());
}
//群发按钮槽函数
void MainWindow::on_btn_SendAll_clicked()
{
    QString data=ui->sendData->text();

    QJsonObject obj;
    obj.insert("type","allinfo");
    obj.insert("from",ui->leUserName->text());
    obj.insert("date",QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]"));
    obj.insert("info",data);
    sendData(QJsonDocument(obj).toJson());
}
//私发按钮槽函数
void MainWindow::on_btn_SendPer_clicked()
{
    QString data=ui->sendData_2->text();

    QJsonObject obj;
    obj.insert("type","oneinfo");
    obj.insert("from",ui->leUserName->text());
    obj.insert("to",ui->sendName->text());
    obj.insert("date",QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]"));
    obj.insert("info",data);
    QByteArray  json=QJsonDocument(obj).toJson();
    sendData(json);
    showOneData(json);
}
//网络链接槽函数
void MainWindow::ConnectSlot()
{

    //发送信息
    ui->leIP->setEnabled(false);
        ui->lePort->setEnabled(false);
        ui->leUserName->setEnabled(false);
        ui->btn_Connect->setEnabled(false);
        QJsonObject obj;
        obj.insert("type","logininfo");
        obj.insert("from",ui->leUserName->text());
        sendData(QJsonDocument(obj).toJson());

}
//准备接收数据槽函数
void MainWindow::ReadyReadSlot()
{
    QByteArray data;
    data.append(Socket->readAll());
    handelData(data);
}
//断开链接槽函数
void MainWindow::DisConnectSlot()
{

    ui->leIP->setEnabled(true);
        ui->lePort->setEnabled(true);
        ui->btn_Connect->setEnabled(true);
        ui->leUserName->setEnabled(true);
}
//
void MainWindow::handelData(QByteArray data)
{
    QJsonObject obj =QJsonDocument::fromJson(data).object();
    QJsonValue type=obj.value("type");
    if(type.isUndefined())return;
    if(!type.isString()) return;
    if(type=="allinfo")
        showAllUserData(data);
    if(type=="oneinfo")
        showOneData(data);
    if(type=="XITONG"){

        showMessage(data);
    }
    if(type =="userlist"){
        showUserList(data);
    }

}
//群发消息函数
void MainWindow::showAllUserData(QByteArray data)
{
    QJsonObject obj=QJsonDocument::fromJson(data).object();
    QString str;
    QString from=obj.value("from").toString();
    QString date=obj.value("date").toString();
    QString info=obj.value("info").toString();
    str =tr("%1 %2 send to all \n%3").arg(date).arg(from).arg(info);
    ui->allText->append(str);

}
//单发槽函数
void MainWindow::showOneData(QByteArray data)
{
    QJsonObject obj=QJsonDocument::fromJson(data).object();
    QString str;
    QString from=obj.value("from").toString();
    QString to =obj.value("to").toString();
    QString date=obj.value("date").toString();
    QString info=obj.value("info").toString();
    str =tr("%1 %2 send to %3 \n%4").arg(date).arg(from).arg(to).arg(info);
    ui->oneText->append(str);
}

void MainWindow::showMessage(QByteArray data)
{
    QJsonObject obj=QJsonDocument::fromJson(data).object();
    int message=obj.value("message").toInt();
    switch(message){
    case 0:
        QMessageBox::information(this,"提示","登录失败");
        Socket->disconnectFromHost();
        break;
    case 1:
        QMessageBox::information(this,"提示","登录成功");
        break;
    case 2:
        QMessageBox::information(this,"提示","发送失败");
    }
}

void MainWindow::showUserList(QByteArray data)
{
    QJsonObject obj=QJsonDocument::fromJson(data).object();
    QString list= obj.value("namelist").toString();
    ui->userlist->setText(list);
}

void MainWindow::on_pushButton_clicked()
{
    ui->allText->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->oneText->setText("");
}


