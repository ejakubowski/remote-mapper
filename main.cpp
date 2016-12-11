#include "mainwindow.h"
#include "shortcuts.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <QMessageBox>

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        //QApplication a(argc, argv);
        QString name = QString(argv[1]);
        //QMessageBox::information(NULL, "info", "running shortcut " + name);
        //std::cout << "test" << std::end;
        //qDebug() << "running shortcut " << name;
        Shortcuts::RunShortcut(name);
        //a.exit();
        return 0;
    }
    else
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
