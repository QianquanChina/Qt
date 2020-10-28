#include "form.h"
#include "ui_form.h"
#include<QtSql/QSqlTableModel>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QMessageBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
Form::~Form()
{
    delete ui;
}

void Form::ReceiverRegister()
{
    qDebug() << "888888";
    this->show();
}

void Form::on_pushButton_clicked()
{
    QString uname=ui->user->text();
    QString upasswd=ui->password->text();
    QString s=QString("insert into lidong  values ('%1' ,'%2') ").arg(uname).arg(upasswd);
    QSqlQuery query;
    bool d=query.exec(s);
    QMessageBox box;
    if(d)
    {
        box.setText("register success");
        box.exec();
        ui->user->clear();
        ui->password->clear();
        ui->user->setFocus();
        this->hide();
    }
}
