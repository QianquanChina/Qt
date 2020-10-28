#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_Register_clicked();

private:
    Ui::loginDialog *ui;
signals:
    void ShowRegister();

};

#endif // LOGINDIALOG_H
