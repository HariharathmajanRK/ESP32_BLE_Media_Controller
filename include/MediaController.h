#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

#include <HijelHID_BLEKeyboard.h>

class MediaController
{
private:

    HijelHID_BLEKeyboard& bleKeyboard;

public:

    MediaController(HijelHID_BLEKeyboard& keyboard);

    void playPause();
    void nextTrack();
    void previousTrack();

    void volumeUp();
    void volumeDown();

    void mute();

    bool isConnected();
};

#endif