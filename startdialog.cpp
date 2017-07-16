#include "startdialog.h"
#include "ui_startdialog.h"
#include "processdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
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
