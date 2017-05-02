/*  
  ASCII-decoder
  Door Jonas Meeuws
*/
//Variabelen
int inputPin = 13; //Index of pin used
long rate = 9600; //Baud rate
float del = 500; //Source period
long trig = 150; //Voltage threshhold
bool a;

//I/O configureren
void setup() {  //Hook at boot finish
  pinMode(inputPin, INPUT);
  Serial.begin(rate);
}

//Belangrijkste code
void loop() { //Repeatedly triggering hook
    //Variabele
    char character;

    //4 Controlebits
    if (analogRead(inputPin) > 150){
        delay(del);
        print(analogRead(inputPin))
        if (analogRead(inputPin) < 150){
          delay(del);
          if (analogRead(inputPin) > 150){
           delay(del);
            if (analogRead(inputPin) < 150){
              delay(del);

              //laatste 8 bits opslaan als karakter
                for (int i=0; i<7; ++i){
                  if (analogRead(inputPin) < 150){
                    a = 1;
                  } else {
                    a = 0;
                  }
                  
                  bitWrite(character, i, !a);
                  Serial.print("&");
                  delay(del);
                }
              //Karakter op seriële poort schrijven
              Serial.print(character, HEX);
        }
      }
    }
  }
}
