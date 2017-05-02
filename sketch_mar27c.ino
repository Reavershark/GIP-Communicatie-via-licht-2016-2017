int inputPin = 0; //Index of analog pin used (ex A'0')
long rate = 9600; //Baud rate

void setup() {  //Hook at boot finish
  Serial.begin(rate);
}

void loop() {
  Serial.println(analogRead(inputPin));
  delay(200);
}
