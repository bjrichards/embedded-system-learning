const int pin_arr[] = {6, 7, 8};
const int pin_button = 12;
int count = 0;
int button_state = 0;
int last_button_state = 0;
void setup() {
  for (int i = 0; i < 3; i++)
    pinMode(pin_arr[i], OUTPUT);

  pinMode(pin_button, INPUT);
    
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  button_state = digitalRead(pin_button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button_state == LOW && last_button_state == 1)
  {
    count++;
    last_button_state = 0;
  }
  else if (button_state == HIGH)
  {
    last_button_state = 1;
  }
  // Light up leds based on count's binary equivalent
  int temp_count = count;
  int rem;
  for (int i = 0; i < 3; i++)
  {
    rem = temp_count % 2;
    temp_count = temp_count / 2;
    if (rem == 1)
    digitalWrite(pin_arr[i], HIGH);
  else
    digitalWrite(pin_arr[i], LOW);
  }
  
 
  Serial.print(button_state);
//  Serial.print(' ');
//  Serial.print(count / 2);
  Serial.println();
  count = count % 8;
  
//  delay(1000);
}
