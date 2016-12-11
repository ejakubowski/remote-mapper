#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include "shortcuts.h"
#include <QThread>
#include <QMessageBox>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showkeysFlag = false;
    loadKeyMapping();
    //registerMappings();
    on_showKeysBtn_clicked();
    setFixedSize(this->size());
    showMinimized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadKeyMapping()
{
    //remote's keycode   - button description, target action

    //keycode: 115, 0x73 - red button, closeChromeAndKodi
    //keycode: 116, 0x74 - green button, Netflix
    //keycode: 117, 0x75 - yellow button
    //keycode: 118, 0x76 - blue button, Kodi
    //keycode: 114, 0x72 - search button, guide
    //keycode: 172, 0xac - home button, mediaCenterStart
    //keycode: 93, 0x5d - context button
    //keycode: 113, 0x71 - blocky button - enterKey
    //keycode: 181, 0xb5 - video button - record tv
    //keycode: 180, 0xb4 - mail button - stop

    //QHash<int, QString> keyMapList

    keyMapList.insert(1,"172,mediaCenterStart,home button");
    keyMapList.insert(2,"181,record,video button");
    keyMapList.insert(3,"180,stop,mail button");
    keyMapList.insert(4,"113,enterKey,blocky button");
    keyMapList.insert(5,"115,closeChromeAndKodi,red button");
    keyMapList.insert(6,"116,netflix,green button");
    keyMapList.insert(7,"118,kodi,blue button");
    keyMapList.insert(8,"114,guide,search button");

    ui->listWidget->clear();
    for (QHash<int, QString>::iterator i = keyMapList.begin(); i != keyMapList.end(); ++i)
    {
        ui->listWidget->addItem("[" + QString::number(i.key())+ "] " + i.value());
    }
}

void MainWindow::registerMappings()
{
    QString failures = "";
    for (QHash<int, QString>::iterator i = keyMapList.begin(); i != keyMapList.end(); ++i)
    {
        QStringList mapping = i.value().split(",");
        int vk_val = mapping[0].toInt();
        if(!RegisterHotKey(HWND(winId()), i.key(), 0, vk_val))
            failures += "Can’t register hotkey " + mapping[0] + "\n";
    }
    if (failures.length() > 0)
        QMessageBox::warning(this, "Warning", failures);
}

void MainWindow::unregisterMappings()
{
    QString failures = "";
    for (QHash<int, QString>::iterator i = keyMapList.begin(); i != keyMapList.end(); ++i)
    {
        QStringList mapping = i.value().split(",");
        //int vk_val = mapping[0].toInt();
        if(!UnregisterHotKey(HWND(winId()), i.key()))
            failures += "Can’t unregister hotkey " + mapping[0] + "\n";
    }

    if (failures.length() > 0)
        QMessageBox::warning(this, "Warning", failures);
}

void MainWindow::on_showKeysBtn_clicked()
{
    if (!showkeysFlag)
    {
        showkeysFlag = true;
        ui->showKeysBtn->setText("unset hotkeys");
        ui->outputTxt->append("setting hotkeys " + QString::number(showkeysFlag));
        registerMappings();
    }
    else
    {
        showkeysFlag = false;
        ui->showKeysBtn->setText("set hotkeys");
        ui->outputTxt->append("unsetting hotkeys " + QString::number(showkeysFlag));
        unregisterMappings();
    }
}

void MainWindow::hotkeyPressed(int id)
{
    QStringList mapping = keyMapList.value(id).split(",");
    //int vk_val = mapping[0].toInt();
    ui->outputTxt->append("processing hotkey [" + QString::number(id) + "] " + keyMapList.value(id));
    Shortcuts::RunShortcut(mapping[1]);
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);
    MSG *msg = static_cast<MSG*>(message);
    if(msg->message == WM_HOTKEY)
    {
        hotkeyPressed(msg->wParam);
        //ui->outputTxt->append("Hotkey keycode: "+ QString::number(msg->wParam));
        //QMessageBox::information(this, "OK", "Hotkey pressed!");
        return true;
    }
    if (showkeysFlag && msg->message == WM_KEYUP)
    {
        ui->outputTxt->append("keycode: "+ QString::number(msg->wParam) + ", " + QString("0x%1").arg(msg->wParam , 0, 16));
    }
//    if (msg->message == WM_KEYDOWN && msg->wParam == 172)
//    {
//        ui->outputTxt->append("web home pressed");
//        return true;
//    }
    return false;
}

void MainWindow::on_sendKeysBtn_clicked()
{
    ui->outputTxt->append("mediaCenterStart");
    //QString s = "mediaCenterStart";
    //Shortcuts::RunShortcut(s);
    Shortcuts::mediaCenterStart();
//    // press DOWN "Alt-Tab"
//    keybd_event(VK_MENU, 0, 0, 0);
//    keybd_event(VK_TAB, 0, 0, 0);

//    QThread::msleep(500);

//    // stop pressing "Alt-Tab"
//    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
//    keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
}

void MainWindow::on_actionAbout_triggered()
{
     QMessageBox::information(this, "About", "Remote Mapper v1.1\nCreated by ejakubowski7@gmail.com");
}

void MainWindow::on_actionE_xit_triggered()
{
    this->close();
}
