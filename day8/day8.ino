int red = 11;
int green = 10;
int blue = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

// pulse width modulation
void RGB_color(int red_value, int green_value, int blue_value){
  // custom function to set three PWM color channels to any given mixture
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void loop() {
  // put your main code here, to run repeatedly:

  RGB_color(0, 0, 0); // Off?
  delay(800);
  RGB_color(10, 10, 10); // White?
  delay(800);
  RGB_color(50, 50, 50); // White?
  delay(800);
  RGB_color(80, 80, 80); // White?
  delay(800);
  RGB_color(125, 125, 125); // White?
  delay(2000);

}
