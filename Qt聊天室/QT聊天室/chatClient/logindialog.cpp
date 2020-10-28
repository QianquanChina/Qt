#include "logindialog.h"
#include "ui_logindialog.h"
#include<QDebug>
#include "form.h"
#include<QMessageBox>
#include<QtSql/QSqlTableModel>
#include<QtSql/QSqlQuery>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_buttonBox_accepted()
{
    QString uname = ui->lineEdit->text();
    QString  upasswd = ui->lineEdit_2->text();
  //查询数据库验证
    QString s = QString("select  * from  lidong  where name =='%1'  and  passwd =='%2'  ").arg(uname).arg(upasswd);
    QSqlQuery  query;
    query.exec(s);
    if(query.first())
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("Waring"),tr("pleaer register"),QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
    }
}

void loginDialog::on_buttonBox_rejected()
{
    QString uname=ui->lineEdit->text();
    QString upasswd=ui->lineEdit_2->text();
    QString s=QString("insert into lidong  values ('%1' ,'%2') ").arg(uname).arg(upasswd);
    QSqlQuery query;
    bool d=query.exec(s);
    QMessageBox box;
    if(d)
    {
        box.setText("register success");
        box.exec();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
        reject();
    }
}


void loginDialog::on_Register_clicked()
{
    //this->hide();
    qDebug() << "99999";
    emit ShowRegister();
}
