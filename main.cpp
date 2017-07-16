#include "startdialog.h"
#include <QApplication>
#include <QString>

const QString UPDATE_JSON = QString("https://raw.githubusercontent.com");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog w;
    w.show();

    return a.exec();
}
