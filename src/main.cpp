#include <Arduino.h>

#define SENSOR_PIN 8
#define BUZZER_PIN 10

unsigned long last_time = 0;

void setup()
{
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  unsigned long cur_time = millis();
  if (digitalRead(SENSOR_PIN) == HIGH)
  {
    if (cur_time - last_time >= 4000)
    {
      last_time = cur_time;

      tone(BUZZER_PIN, 700, 300);
      delay(200);
      tone(BUZZER_PIN, 400, 100);
      delay(200);
      tone(BUZZER_PIN, 350, 800);
      delay(200);
      tone(BUZZER_PIN, 1000, 1000);
      delay(200);
      noTone(BUZZER_PIN);
    }
  }
}
