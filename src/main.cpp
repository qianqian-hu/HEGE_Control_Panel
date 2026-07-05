#include <Arduino.h>

#include "can/CanDriver.h"
#include "can/CanFrame.h"
#include "ui/VehicleStatus.h"

static unsigned long lastPrintMs = 0;

static void printByteHex(uint8_t value)
{
    if (value < 0x10) {
        Serial.print("0");
    }
    Serial.print(value, HEX);
}

static void printCanFrame(const CanFrame& frame)
{
    Serial.print("[RX] ID=0x");
    Serial.print(frame.id, HEX);
    Serial.print(" DLC=");
    Serial.print(frame.dlc);
    Serial.print(" DATA=");

    for (uint8_t i = 0; i < frame.dlc && i < 8; i++) {
        printByteHex(frame.data[i]);
        Serial.print(" ");
    }

    Serial.println();
}

static void printVehicleStatus()
{
    Serial.println("---------- VehicleStatus ----------");

    Serial.print("CAN connected: ");
    Serial.println(vehicleStatus.canConnected ? "true" : "false");

    Serial.print("Battery valid: ");
    Serial.println(vehicleStatus.batteryValid ? "true" : "false");

    Serial.print("Battery: ");
    Serial.println(vehicleStatus.battery);

    Serial.print("Speed valid: ");
    Serial.println(vehicleStatus.speedValid ? "true" : "false");

    Serial.print("Left speed: ");
    Serial.println(vehicleStatus.leftSpeed);

    Serial.print("Right speed: ");
    Serial.println(vehicleStatus.rightSpeed);

    Serial.print("Steering valid: ");
    Serial.println(vehicleStatus.steeringValid ? "true" : "false");

    Serial.print("Steering enum: ");
    Serial.println((int)vehicleStatus.steering);

    Serial.print("Manual mode: ");
    Serial.println(vehicleStatus.manualMode ? "true" : "false");

    Serial.println("-----------------------------------");
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println("HEGE Control Panel real CAN RX test started");

    reset_vehicle_status();

    bool canReady = can_driver_init();

    if (canReady) {
        Serial.println("[INIT] CAN ready.");
    } else {
        Serial.println("[INIT] CAN not ready.");
    }

    update_vehicle_mode(false);
}

void loop()
{
    CanFrame rxFrame;

    while (can_driver_receive(rxFrame)) {
        printCanFrame(rxFrame);

        parse_can_message(
            rxFrame.id,
            rxFrame.data,
            rxFrame.dlc
        );
    }

    if (millis() - lastPrintMs >= 1000) {
        lastPrintMs = millis();
        printVehicleStatus();
    }

    delay(5);
}