#include "CommandHandler.h"

CommandHandler::CommandHandler(
    MediaController& controller
)
    : mediaController(controller)
{
}

void CommandHandler::printMenu()
{
    Serial.println();
    Serial.println("====== MEDIA CONTROLLER ======");
    Serial.println("p = Play/Pause");
    Serial.println("n = Next Track");
    Serial.println("b = Previous Track");
    Serial.println("+ = Volume Up");
    Serial.println("- = Volume Down");
    Serial.println("m = Mute");
    Serial.println("==============================");
}

void CommandHandler::processCommand(char command)
{
    switch (command)
    {
        case 'p':

            Serial.println("Sending PLAY/PAUSE");

            mediaController.playPause();

            break;


        case 'n':

            Serial.println("Sending NEXT TRACK");

            mediaController.nextTrack();

            break;


        case 'b':

            Serial.println("Sending PREVIOUS TRACK");

            mediaController.previousTrack();

            break;


        case '+':

            Serial.println("Sending VOLUME UP");

            mediaController.volumeUp();

            break;


        case '-':

            Serial.println("Sending VOLUME DOWN");

            mediaController.volumeDown();

            break;


        case 'm':

            Serial.println("Sending MUTE");

            mediaController.mute();

            break;


        default:

            Serial.print("Invalid command: ");

            Serial.println(command);

            break;
    }
}