#include <QJsonDocument>
#include <QJsonObject>
#include "startdialog.h"
#include "ui_startdialog.h"
#include "processdialog.h"

QJsonDocument document;

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    connect(&webController, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloaded(QNetworkReply*)));
    QNetworkRequest request(UPDATE_JSON);
    webController.get(request);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    ProcessDialog* processdialog = new ProcessDialog();
    processdialog->show();
    this->hide();
}

void StartDialog::downloaded(QNetworkReply *reply)
{
    document.fromBinaryData(reply->readAll());
    ui->labelSize->setText(document.object()["size"].toString());
    ui->textDescription->setText(ui->labelSize->setText(document.object()["fileName"].toString()));
    reply->deleteLater();
}
