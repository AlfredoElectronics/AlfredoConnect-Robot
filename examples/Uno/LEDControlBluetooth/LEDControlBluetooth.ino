/**
 * Lights an Arduino or clone board's built-in LED when the "W" key is pressed in AlfredoConnect
 * while connected to the ESP32's Bluetooth.
 * 
 * TODO: Link basic setup here (board files, how to upload, how to pair Bluetooth, how to find and open port)
 */

#include <AlfredoConnect.h>
#include <BluetoothSerial.h>

BluetoothSerial bluetooth;

void setup() {
    bluetooth.begin("ESP32 Bluetooth");
    AlfredoConnect.begin(bluetooth);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    AlfredoConnect.update();
    if (AlfredoConnect.keyHeld(Key::W)) digitalWrite(2, HIGH);
    else digitalWrite(LED_BUILTIN, LOW);
}