#include <Arduino.h>
#include <HijelHID_BLEKeyboard.h>

#include "MediaController.h"
#include "CommandHandler.h"


// --------------------------------------------------
// BLE HID object
// --------------------------------------------------

HijelHID_BLEKeyboard bleKeyboard(
    "ESP32 Media Controller",
    "ESP32",
    100
);


// --------------------------------------------------
// Application objects
// --------------------------------------------------

MediaController mediaController(bleKeyboard);

CommandHandler commandHandler(mediaController);


// --------------------------------------------------
// Setup
// --------------------------------------------------

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("=================================");
    Serial.println("   ESP32 BLE Media Controller");
    Serial.println("=================================");

    bleKeyboard.begin();

    Serial.println("BLE started!");

    Serial.println(
        "Connect phone to: ESP32 Media Controller"
    );
}


// --------------------------------------------------
// Main loop
// --------------------------------------------------

void loop()
{
    // ----------------------------------------------
    // Wait for BLE connection
    // ----------------------------------------------

    if (!mediaController.isConnected())
    {
        Serial.println(
            "Waiting for BLE connection..."
        );

        delay(2000);

        return;
    }


    // ----------------------------------------------
    // Display command menu
    // ----------------------------------------------

    commandHandler.printMenu();


    // ----------------------------------------------
    // Wait for serial command
    // ----------------------------------------------

    while (Serial.available() == 0)
    {
        delay(10);
    }


    // ----------------------------------------------
    // Read command
    // ----------------------------------------------

    char command = Serial.read();


    // ----------------------------------------------
    // Remove remaining characters and empty spaces
    // such as \r and \n
    // ----------------------------------------------

    while (Serial.available() > 0)
    {
        Serial.read();
    }


    // ----------------------------------------------
    // Process command
    // ----------------------------------------------

    commandHandler.processCommand(command);


    delay(300);
}