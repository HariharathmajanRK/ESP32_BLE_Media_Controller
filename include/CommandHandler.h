#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "MediaController.h"

class CommandHandler
{
private:

    MediaController& mediaController;

public:

    CommandHandler(MediaController& controller);

    void processCommand(char command);

    void printMenu();
};

#endif