/*  
  ASCII-encoder
  Door Jonas Meeuws
*/
//Variabelen
int ledPin = 13; // The Led's pin number ('Digital' pins on the PBC)
long rate = 9600;//Delay between transferred bits in ms^-1
float del = 500; //Source period
char buff[1];

//I/O configureren
void setup() {  //Hook at boot finish
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(rate);
  
}

//4 controlebits en 1 byte (karakter) verzenden
void sendChar(char ch) { //Modulates power on ledPin using ASCII encoding
  
      digitalWrite(ledPin, HIGH);
      delay(del);
      digitalWrite(ledPin, LOW);
      delay(del);
      digitalWrite(ledPin, HIGH);
      delay(del);
      digitalWrite(ledPin, LOW);
      delay(del);
      
  for(int i=0; i<=7; i = i + 1) { //Run 8 times, for each bit in a byte
    
    bool currentBit = bitRead(ch, i); //Store the 'i'th' bit of the char
    digitalWrite(ledPin, currentBit);
    delay(del);
    
  }
}

//Seriële poort lezen
void loop() { //Constantly triggering hook
  if (Serial.available() > 0) {
    Serial.readBytes(buff, 1);
    sendChar(buff[0]);
  }
}
