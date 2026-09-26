#include "MediaController.h""

MediaController::MediaController(
    HijelHID_BLEKeyboard& keyboard
)
    : bleKeyboard(keyboard)
{
}

void MediaController::playPause()
{
    bleKeyboard.tap(MEDIA_PLAY_PAUSE);
}

void MediaController::nextTrack()
{
    bleKeyboard.tap(MEDIA_NEXT_TRACK);
}

void MediaController::previousTrack()
{
    bleKeyboard.tap(MEDIA_PREV_TRACK);
}

void MediaController::volumeUp()
{
    bleKeyboard.tap(MEDIA_VOLUME_UP);
}

void MediaController::volumeDown()
{
    bleKeyboard.tap(MEDIA_VOLUME_DOWN);
}

void MediaController::mute()
{
    bleKeyboard.tap(MEDIA_MUTE);
}

bool MediaController::isConnected()
{
    return bleKeyboard.isConnected();
}