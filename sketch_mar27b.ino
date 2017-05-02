/*  
  ASCII-decoder
  Door Jonas Meeuws
*/

int analogPin = 0; //Index of analog pin used ex. '0' for A0
long rate = 9600;
long minDelay = 1; //Script period in ms

void setup() {  //Hook at boot finish
  pinMode(analogPin, INPUT);
  Serial.begin(rate);
}

void loop() { //Constantly triggering hook
  Serial.println(analogRead(analogPin));
  delay(500);
}
