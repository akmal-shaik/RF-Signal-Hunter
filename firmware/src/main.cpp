#include <Arduino.h>

namespace {

constexpr unsigned long SERIAL_BAUD_RATE = 115200;
constexpr uint32_t HEARTBEAT_PERIOD_MS = 1000;

uint32_t heartbeatCount = 0;
uint32_t previousHeartbeatMs = 0;

}  // namespace

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    // Give the computer time to open the USB serial connection.
    delay(1500);

    Serial.println();
    Serial.println("RF_SIGNAL_HUNTER_BOOT");
    Serial.println("test_id=TEST-ESP-001");
    Serial.println("firmware_version=0.3.0-dev");
    Serial.println("heartbeat_count,uptime_ms");

    previousHeartbeatMs = millis();
}

void loop()
{
    const uint32_t currentTimeMs = millis();

    if (currentTimeMs - previousHeartbeatMs >= HEARTBEAT_PERIOD_MS)
    {
        previousHeartbeatMs = currentTimeMs;
        heartbeatCount++;

        Serial.printf(
            "%lu,%lu\n",
            static_cast<unsigned long>(heartbeatCount),
            static_cast<unsigned long>(currentTimeMs)
        );
    }
}