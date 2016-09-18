#define LDR 0
#define PIR 2
#define LED 3

int pirState;
int ldrValue;

void setup() {
  //Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
  digitalWrite(LED, LOW);
}

void loop(){
  ldrValue = analogRead(LDR);
  //Serial.print("Analog reading = ");
  //Serial.println(ldrValue);

  if (ldrValue <= 512) { // dark
    pirState = digitalRead(PIR);
    //Serial.println(pirState);
    if (pirState == LOW) {
      digitalWrite(LED, HIGH);
      delay(10000);
      //digitalWrite(LED, LOW);
      //delay(1000);
    } 
    else { // pirState == LOW
      digitalWrite(LED, LOW);
    }
    
  } 
  else { // ldrValue > 512
    digitalWrite(LED, LOW);
  }
  // The processing in the Arduino occurs faster
  // than the response from the PIR, and adding this delay
  // eliminated a flickering on the LED
  delay(1000);
}
