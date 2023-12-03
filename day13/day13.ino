#include <Arduino.h>

#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PIN_LENGTH = 4;
char current_pin[PIN_LENGTH] = {'0','0','0','0'};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

char buttons[ROWS][COLS] = {
    {'1', '2', '3', 'A'}, // 1st row
    {'4', '5', '6', 'B'}, // 2nd row
    {'7', '8', '9', 'C'}, // 3rd row
    {'*', '0', '#', 'D'}  // 4th row
};  

Keypad myPad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

const byte BUZZER_PIN = 10;


void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  delay(200);

  Serial.println("Press * to enter new PIN or # to access the system."); 
}

void loop() {
  char button_character = myPad.waitForKey();

  tone(BUZZER_PIN, 880, 100);

  Serial.print("Key: ");
  Serial.println(button_character);

  if(button_character == '*'){
    bool access_allowed = validatePin();

    if(access_allowed){
      Serial.println("Welcome, authorized user. Please Enter a new PIN: ");

      for(int i = 0; i<PIN_LENGTH; i++){
        button_character = myPad.waitForKey();
        tone(BUZZER_PIN, 880, 100);

        current_pin[i] = button_character;
        Serial.print("*");
      }

      Serial.println("\nPIN Successfully Changed!");
    } else {
      Serial.println("Access Denied. Cannot change PIN without the old or default");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
  if(button_character == '#'){
    bool access_allowed = validatePin();
    if(access_allowed) {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    } else {
      Serial.println("Access Denied");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }

}



bool validatePin(){
  Serial.println("Enter PIN to continue.");

  for(int i = 0; i < PIN_LENGTH; i++){
    char button_character = myPad.waitForKey();
    tone(BUZZER_PIN, 880, 100);
    if(current_pin[i] != button_character){
      Serial.println();
      Serial.print("WRONG PIN DIGIT: ");
      Serial.println(button_character);
      return false;
    }
    Serial.print('*');
  }

  Serial.println();
  Serial.println("Device Successfully Unlocked!");
  return true;
}