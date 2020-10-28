#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void sendData(QByteArray data);

    ~MainWindow();

private slots:
    //链接按钮槽函数
    void on_btn_Connect_clicked();
    //群发按钮槽函数
    void on_btn_SendAll_clicked();
    //私发按钮槽函数
    void on_btn_SendPer_clicked();
    //网络链接槽函数
    void ConnectSlot();
    //准备接收槽函数
    void ReadyReadSlot();
    //断开链接槽函数
    void DisConnectSlot();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    void handelData(QByteArray data);
    //群发消息
    void showAllUserData(QByteArray data);
    //私发消息
    void showOneData(QByteArray data);
    void showMessage(QByteArray data);
    void showUserList(QByteArray data);
    Ui::MainWindow *ui;
    QTcpSocket * Socket;


};

#endif // MAINWINDOW_H
