#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

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

const unsigned int TONES[ROWS][COLS] = {
  {31,93,147,208},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 0}
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char button_character = myPad.waitForKey();

  unsigned int tone_frequency = 0;
  for(byte i = 0; i< ROWS; i++){
    for(byte j = 0; j<COLS; j++){
      // something i,j
      if(button_character == buttons[i][j]){
        tone_frequency = TONES[i][j];
      }
    }
  }

  Serial.print("Key: ");
  Serial.print(button_character);
  Serial.print("   Freq: ");
  Serial.println(tone_frequency);

  if(tone_frequency > 0){
    tone(BUZZER_PIN, tone_frequency);
  } else {
    noTone(BUZZER_PIN);
  }


}
