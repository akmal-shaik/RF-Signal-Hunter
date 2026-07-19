#include <Arduino.h>

const int ADC_PIN = 34;

void setup() {
    Serial.begin(115200);
}

void loop() {
    int adcValue = analogRead(ADC_PIN);

    Serial.println(adcValue);

    delay(500);
}