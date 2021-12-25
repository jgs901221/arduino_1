void setup() {
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT_PULLUP);
  Serial.begin(9600);
}

bool LED_ON_OFF = false;
unsigned long Time = millis();

void loop() {
  int bright = map(analogRead(A4),0,1023,0,255);
  if(Time+500 < millis()) {
    if(digitalRead(2) == 1) {
      if(LED_ON_OFF == false) {
        LED_ON_OFF = true;
      } else {
        LED_ON_OFF = false;
      }
      Time = millis();
    }
  }
  Serial.println(analogRead(A5));
  if(LED_ON_OFF == true) {
    if(analogRead(A5) < 550) {
      analogWrite(3,bright);
    } else {
      digitalWrite(3,LOW);
    }
  }
  else {
    digitalWrite(3,LOW);
  }
}
