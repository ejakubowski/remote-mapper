#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <QThread>
#include <QProcess>
#include <QFileInfo>
#include <QString>

class Shortcuts
{
public:
    Shortcuts();
    static void RunShortcut(QString &shortcutName);
    static void mediaCenterStart();//    'Media Center Start page (start Media Center, if necessary): Windows logo key+Alt+Enter
    static void recordedTv();//    'Recorded TV: Ctrl+O or Ctrl+Shift+T
    static void guide();//    'Guide: Ctrl+G
    static void musicLibrary();//    'Music Library: Ctrl+M
    static void videoLibrary();//    'Video Library: Ctrl+E
    static void pictureLibrary();//    'Picture Library: Ctrl+I
    static void movieLibrary();//    'Movie Library: Ctrl+Shift+M
    static void record();//    'Record: Ctrl+R
    static void stop();//Ctrl+Shift+S = Stop recording or playing a TV show
    static void radio();//    'Radio: Ctrl+A
    static void back();//    'Go back to previous screen: Backspace
    static void moreInfo();//    'More Info/Display shortcut menu: Ctrl+D
    static void enterKey();
    static void closeChrome();
    static void closeKodi();
    static void closeChromeAndKodi();
    static void netflix();
    static void kodi();

    //    'Toggle full screen/window: Alt+Enter
    //    'Go to channel number (Live TV or Guide): Enter number using the 0–9 keys
    //    'Up one channel (while playing TV): Plus (+) or Equal (=)
    //    'Down one channel (while playing TV): Minus (–)

};

#endif // SHORTCUTS_H
