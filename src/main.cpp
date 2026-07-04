#include <Arduino.h>

#include "ui/VehicleStatus.h"

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("HEGE Control Panel VehicleStatus test started");

    // ==========================
    // Simulated 0x215 CAN frame
    // SOC raw = 0x01B4 = 436
    // Battery = 43.6 %
    // ==========================

    uint8_t test215[8] = {
        0x03, 0xFF, 0x03, 0x00,
        0x00, 0x01, 0xB4, 0x01
    };

    parse_can_message(0x215, test215, 8);

    // ==========================
    // Simulated 0x315 CAN frame
    // leftRaw  = -100
    // rightRaw = +100
    // ==========================

    uint8_t test315[8] = {
        0x9C, 0xFF, 0xFF, 0xFF,
        0x64, 0x00, 0x00, 0x00
    };

    parse_can_message(0x315, test315, 8);

    // Simulate automatic mode.
    update_vehicle_mode(false);

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

    Serial.println("VehicleStatus test finished");
}

void loop() {
    delay(1000);
}