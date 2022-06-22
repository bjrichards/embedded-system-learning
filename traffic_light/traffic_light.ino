/*
 * Traffic light test of LEDs
 * Turns on green, yellow, red LEDs in sequence when button pressed
 * There is a 1 second delay between each step
 */

const int led_red_pin = 2;
const int led_yellow_pin = 4;
const int led_green_pin = 7;
int count = 0;

void setup() {
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_yellow_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
}

void loop() {
  if (count > 0)
    digitalWrite(led_green_pin, HIGH);
  else
    digitalWrite(led_green_pin, LOW);
  
  if (count > 1)
    digitalWrite(led_yellow_pin, HIGH);
  else
    digitalWrite(led_yellow_pin, LOW);

  if (count > 2)
    digitalWrite(led_red_pin, HIGH);
  else
    digitalWrite(led_red_pin, LOW);
  
  count = (count + 1) % 4;
  
  delay(1000);
}
