#include "mainwindow.h"
#include "logindialog.h"
#include "form.h"
#include <QApplication>
#include <logindialog.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QDebug>

int main(int argc, char *argv[])
{

     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//创建数据库

     //设置数据库名
     db.setDatabaseName("jc.db");
     //打开数据库
     if(db.open())
     {
         qDebug()<<"open database  successful";
     }
     else
     {
         qDebug()<<"open database  failed";
     }

     //创建一个存储用户密码的数据库表
     QString s =QString("create  table lidong(name varchar(64)  primary key, passwd varchar(64))");
     QSqlQuery  query;
     if(query.exec(s))
     {
         qDebug()<<"exec successful";
     }
     QApplication a(argc, argv);
     loginDialog  login;
     login.show();
     Form form;
     QObject::connect(&login,SIGNAL( ShowRegister() ), &form , SLOT(ReceiverRegister()));

    if(login.exec() == QDialog::Accepted)
    {
       MainWindow w;
       w.show();

    return a.exec();
    }
}
