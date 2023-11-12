int LED1 = 10;  //HERO board pin 10
int LED2 = 11;  //HERO board pin 11
int LED3 = 12;  //HERO board pin 12
int Switch1 = 2; // Input pin 2
int Switch2 = 3; // Input pin 3
int Switch3 = 4; // Input pin 4



void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
}

void loop() {
  if(digitalRead(Switch1) == HIGH){ // check switch 1
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if(digitalRead(Switch2) == HIGH){ // check switch 2
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if(digitalRead(Switch3) == HIGH){ // check switch 3
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

}

