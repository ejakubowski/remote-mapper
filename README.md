# remote-mapper
Remote Mapper is an application used to capture a remote control's input and map it to a more useful keystroke.  Currently the application is configured to work with the Rveal RMKR1 Air Mouse Remote & Keyboard.  The default mapping helps this remote work more seamlessly with Windows Media Center, Kodi, and Netflix.  For example if you are running the Remote Mapper application it will map the Web Home button (blue house looking picture) to press the Media Center Start Page Shortcut, which is the Windows + ALT + Enter keys.

The default mappings done by this application are listed below:

    //remote's keycode   - button description, target action 
    
    //keycode: 115, 0x73 - red button, closeChromeAndKodi
    //keycode: 116, 0x74 - green button, Netflix
    //keycode: 117, 0x75 - yellow
    //keycode: 118, 0x76 - blue button, Kodi
    //keycode: 114, 0x72 - search button, guide
    //keycode: 172, 0xac - home button, mediaCenterStart
    //keycode: 93, 0x5d - context button
    //keycode: 113, 0x71 - blocky button - enterKey
    //keycode: 181, 0xb5 - video button - record tv
    //keycode: 180, 0xb4 - mail button - stop

# Installation

This application is really simple to install with only a couple of steps. 

1. Download the [zip file](https://github.com/ejakubowski/remote-mapper/releases/download/v1.0/remote-mapper.zip) and extract it somewhere on your Windows PC.  Currently tested and working on the following OSes: Windows 7 32 + 64-bit.
2. Run the application remote_mapper.exe, which was extracted from the zip.  You will notice the application will start minimized since it will generally run in the background.
3. To have the application startup with your computer just add a shortcut to remote_mapper.exe in your startup programs folder:
  %AppData%\Microsoft\Windows\Start Menu\Programs\Startup


# Supported Device

+ Rveal RMKR1 Air Mouse Remote & Keyboard
  https://www.amazon.com/Rveal-RMKR1-Mouse-Remote-Keyboard/dp/B018T3VIT6/ref=sr_1_1?ie=UTF8&qid=1480770575&sr=8-1&keywords=rveal+air+mouse
  

# Troubleshooting
This application is pretty new so let me know if you are having issues and I will try to help and post things here.


# Building
Developed using C++ with Qt5.5 mingw for windows.  To rebuild simply install Qt5.5 and open the remote_mapper.pro project and build it.  Deploying the exe only requires you package or include all standard Qt5.5 dependency dll's.
