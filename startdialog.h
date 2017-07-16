#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "stdafx.h"

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void downloaded(QNetworkReply *reply);

private:
    Ui::StartDialog *ui;
    QNetworkAccessManager webController;
};

#endif // STARTDIALOG_H
