#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QList>
#include<QJsonObject>
#include<QJsonDocument>
#include <QJsonValue>
#include <QTimer>
#include <QDialog>

namespace Ui {
class Dialog;
}


typedef struct serverinfo{
    QString UserName;
    QTcpSocket *Socket;
}SocketInfo;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    static Dialog* getObject();
    bool startNetwork(quint16 port);
    void closeNetwork();
    bool sendDataTo( QString userName,QByteArray data);
    bool sendDataAll(QByteArray data);
    void logIn(QByteArray data,QTcpSocket *Socket);
    void sendXTMessage(QTcpSocket *Socket,int message);
protected slots:
    void ServerNewConnectSlot();
    void ServeReadyReadSlot();
    void SocketDisConnetSlot();
    void TimerSendUserListSlot();
protected:
    QList<SocketInfo*> userList;
    QTcpServer * Server;
    QTimer *time;


private slots:
    void on_pushButton999_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
