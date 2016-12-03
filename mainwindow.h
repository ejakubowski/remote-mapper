#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadKeyMapping();
    void registerMappings();
    void unregisterMappings();
    void hotkeyPressed(int id);

private slots:
    void on_showKeysBtn_clicked();

    void on_sendKeysBtn_clicked();

    void on_actionAbout_triggered();

    void on_actionE_xit_triggered();

private:
    QHash<int, QString> keyMapList;
    bool showkeysFlag;
    Ui::MainWindow *ui;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
};

#endif // MAINWINDOW_H
