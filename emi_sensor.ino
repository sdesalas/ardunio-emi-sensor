/*
 * Arduino EMI Sensor
 * By Steven de Salas
 * 
 * A simple sensor that detects electromagnetic inteference.
 * It works because Arduino analog pins are very sensitive when using
 * a 'floating ground' (ie when antenna is not connected to main ground).
 * 
 * DIAGRAM:
 * 
 * (Antenna)
 *  Y
 *  |    +--------+
 *  |    |*      *|9 --O-| (Red LED)
 *  |    |*      *|8 --O-| (Red LED)
 *  |    |*      *|7 --O-| (Yellow LED)
 *  |- A3|*      *|6 --O-| (Green LED)
 *       |*      *|      |
 *       |*      *|GND --|
 *       +--------+
 */
 
int leds[] = { 6, 7, 8, 9 };
int thresholds[] = { 256, 512, 768, 950 };

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(A3, INPUT);
}

void loop() { 
  int emi = analogRead(A3); 
  for (byte i = 0; i < 4; i++) {
    digitalWrite(leds[i], emi > thresholds[i] ? 1 : 0);
  }
  delay(10);
}
