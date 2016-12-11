#include "shortcuts.h"
#include "windows.h"

static int KEY_PRESS_DELAY = 500;

Shortcuts::Shortcuts()
{
}

void Shortcuts::RunShortcut(QString &shortcutName)
{
    if (shortcutName == "mediaCenterStart")
        Shortcuts::mediaCenterStart();
    else if (shortcutName == "record")
        Shortcuts::record();
    else if (shortcutName == "stop")
        Shortcuts::stop();
    else if (shortcutName == "enterKey")
        Shortcuts::enterKey();
    else if (shortcutName == "closeChromeAndKodi")
        Shortcuts::closeChromeAndKodi();
    else if (shortcutName == "netflix")
        Shortcuts::netflix();
    else if (shortcutName == "kodi")
        Shortcuts::kodi();
    else if (shortcutName == "guide")
        Shortcuts::guide();
    else if (shortcutName == "musicLibrary")
        Shortcuts::musicLibrary();
    else if (shortcutName == "videoLibrary")
        Shortcuts::videoLibrary();
    else if (shortcutName == "pictureLibrary")
        Shortcuts::pictureLibrary();
    else if (shortcutName == "movieLibrary")
        Shortcuts::movieLibrary();
    else if (shortcutName == "back")
        Shortcuts::back();
    else if (shortcutName == "recordedTv")
        Shortcuts::recordedTv();
    else if (shortcutName == "moreInfo")
        Shortcuts::moreInfo();

//    static void recordedTv();//    'Recorded TV: Ctrl+O or Ctrl+Shift+T
//    static void guide();//    'Guide: Ctrl+G
//    static void musicLibrary();//    'Music Library: Ctrl+M
//    static void videoLibrary();//    'Video Library: Ctrl+E
//    static void pictureLibrary();//    'Picture Library: Ctrl+I
//    static void movieLibrary();//    'Movie Library: Ctrl+Shift+M
//    static void record();//    'Record: Ctrl+R
//    static void stop();//Ctrl+Shift+S = Stop recording or playing a TV show
//    static void radio();//    'Radio: Ctrl+A
//    static void back();//    'Go back to previous screen: Backspace
//    static void moreInfo();//    'More Info/Display shortcut menu: Ctrl+D
//    static void enterKey();
//    static void closeChrome();
//    static void closeKodi();
//    static void closeChromeAndKodi();
//    static void netflix();
//    static void kodi();
}

//    'Recorded TV: Ctrl+O or Ctrl+Shift+T
//    'Guide: Ctrl+G
//    'Music Library: Ctrl+M
//    'Video Library: Ctrl+E
//    'Picture Library: Ctrl+I
//    'Movie Library: Ctrl+Shift+M
//    'Record: Ctrl+R
//    'Radio: Ctrl+A
//    'Go back to previous screen: Backspace
//    'Toggle full screen/window: Alt+Enter
//    'Go to channel number (Live TV or Guide): Enter number using the 0–9 keys
//    'Up one channel (while playing TV): Plus (+) or Equal (=)
//    'Down one channel (while playing TV): Minus (–)
//    'Record: Ctrl+R
//    'More Info/Display shortcut menu: Ctrl+D

//    'Media Center Start page (start Media Center, if necessary): Windows logo key+Alt+Enter
void Shortcuts::mediaCenterStart()
{
    // press DOWN "key+Alt+Enter"
    keybd_event(VK_LWIN, 0, 0, 0);
    keybd_event(VK_MENU, 0, 0, 0);
    keybd_event(VK_RETURN, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing "key+Alt+Enter"
    closeChrome();
}

void Shortcuts::recordedTv()//    'Recorded TV: Ctrl+O or Ctrl+Shift+T
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x4F, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x4F, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Guide: Ctrl+G
void Shortcuts::guide()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x47, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x47, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Music Library: Ctrl+M
void Shortcuts::musicLibrary()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x4D, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x4D, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Video Library: Ctrl+E
void Shortcuts::videoLibrary()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x45, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Picture Library: Ctrl+I
void Shortcuts::pictureLibrary()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x49, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x49, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Movie Library: Ctrl+Shift+M
void Shortcuts::movieLibrary()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    //keybd_event(0x4F, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    //keybd_event(0x4F, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Record: Ctrl+R
void Shortcuts::record()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x52, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x52, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//Ctrl+Shift+S = Stop recording or playing a TV show
void Shortcuts::stop()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(VK_SHIFT, 0, 0, 0);
    keybd_event(0x53, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'Radio: Ctrl+A
void Shortcuts::radio()
{
    // press DOWN "key+Alt+Enter"
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x41, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing "key+Alt+Enter"
}

//    'Go back to previous screen: Backspace
void Shortcuts::back()
{
    // press DOWN
    //keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(VK_BACK, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0);
    //keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

//    'More Info/Display shortcut menu: Ctrl+D
void Shortcuts::moreInfo()
{
    // press DOWN
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x4F, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(0x4F, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    // stop pressing
}

void Shortcuts::enterKey()
{
    keybd_event(VK_RETURN, 0, 0, 0);

    QThread::msleep(KEY_PRESS_DELAY);

    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}

void Shortcuts::closeChrome()
{
    QProcess process;
    process.start("C:\\Windows\\System32\\taskkill.exe /F /IM chrome.exe /T");
    process.waitForFinished(10000);
    process.terminate();
}

void Shortcuts::closeKodi()
{
    QProcess process;
    process.start("C:\\Windows\\System32\\taskkill.exe /F /IM kodi.exe /T");
    process.waitForFinished(10000);
    process.terminate();
}

void Shortcuts::closeChromeAndKodi()
{
    closeChrome();
    closeKodi();
    //mediaCenterStart();
}

void Shortcuts::netflix()
{
    stop();
    QProcess process;
    //process.setWorkingDirectory("C:\\Program Files (x86)\\Google\\Chrome\\Application\\");
    //process.start("cmd.exe /c start www.netflix.com");
    if(QFileInfo("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe").exists()) //64bit
        process.startDetached("\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" -kiosk -fullscreen --disable-session-crashed-bubble --disable-infobars www.netflix.com");
    else //32-bit
        process.startDetached("\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" -kiosk -fullscreen --disable-session-crashed-bubble --disable-infobars www.netflix.com");
    //process.waitForFinished(1000);
    //process.terminate();
}

void Shortcuts::kodi()
{
    stop();
    QProcess process;
    if(QFileInfo("C:\\Program Files (x86)\\Kodi\\kodi.exe").exists()) //64bit
        process.startDetached("\"C:\\Program Files (x86)\\Kodi\\kodi.exe\"");
    else //32-bit
        process.startDetached("\"C:\\Program Files\\Kodi\\kodi.exe\"");

}

