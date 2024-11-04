byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26};
int ledCounts;

void setup()
{
  ledCounts = sizeof(ledPins) / sizeof(ledPins[0]);
  for (int i = 0; i < ledCounts; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for (int number = 1; number <= 256; number++)
  {                             // Loopar genom talen 1 till 256
    showBinaryOnLEDBar(number); // Visar talet i binär form på LED-bar
    delay(500);                 // Väntar en halv sekund innan nästa tal visas
  }
}

void showBinaryOnLEDBar(int number)
{
  for (int i = 0; i < ledCounts; i++)
  {
    (number & (1 << i)) ? digitalWrite(ledPins[i], HIGH) : digitalWrite(ledPins[i], LOW); // Tänder eller släcker LED
  }
}
