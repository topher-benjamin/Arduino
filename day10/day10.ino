int sensorPin = A0;
int sensorValue = 0;

int red = 11;
int green = 10;
int blue = 9;

unsigned int batteryCapacity = 50000;
int batteryLevel = 0;
unsigned int drainRate = 1000;
unsigned int batteryThreshold = 100;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;

//************************************

void setup()
{
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Start serial monitor
  Serial.begin(9600);
}

void RGB_color(int red_value, int green_value, int blue_value)
{
  // custom function to set three PWM color channels to any given mixture
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void color_red() { RGB_color(125, 0, 0); }
void color_green() { RGB_color(0, 125, 0); }
void color_blue() { RGB_color(0, 125, 125); }
void color_yellow() { RGB_color(125, 80, 0); }
void color_orange() { RGB_color(125, 165, 0); }
void color_white() { RGB_color(125, 125, 125); }
void color_off() { RGB_color(0, 0, 0); }

void blinkStatusLight()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

double getBatteryPercentage()
{
  // custom function calculates battery charge percentage
  return (((double)batteryLevel / (double)batteryCapacity) * 100);
}

void ShowBatteryPercentage(bool isCharging)
{
  // send battery results to both serial and LED outputs
  // calculate the charge percentage with a custom function...
  PercentFull = getBatteryPercentage();

  Serial.print(ticks);
  Serial.print(" ms    charge at ");
  Serial.print(PercentFull);
  Serial.println("%");

  // Light LED with the appropriate color
  if (!isCharging)
  {
    blinkStatusLight();
  }

  if (PercentFull > 0 && PercentFull <= 25)
  {
    color_red();
  }
  else if (PercentFull > 25 && PercentFull <= 50)
  {
    color_orange();
  }
  else if (PercentFull > 50 && PercentFull <= 75)
  {
    color_yellow();
  }
  else if (PercentFull > 75 && PercentFull < 100)
  {
    color_blue();
  }
}

void loop()
{
  sensorValue = analogRead(sensorPin); // analog pin 0-1023 / tick
  Serial.println(sensorValue);
  bool isCharging = sensorValue > batteryThreshold;
  if (isCharging)
  {
    // charge battery
    batteryLevel += sensorValue;
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
     // drain battery
     batteryLevel -= drainRate;
  }
  ticks += wait;

Serial.print("Battery Level: ");
Serial.println(batteryLevel);
  if (batteryLevel >= batteryCapacity)
  {
     Serial.print(ticks);
     Serial.print(" ms    ");
     Serial.print("FULLY CHARGED");
     batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
     ticks = 0;
     color_green(); // charging complete
  }
  else if (batteryLevel <= 0)
  {
     Serial.print(ticks);
     Serial.print(" ms    ");
     Serial.print("EMPTY");
     batteryLevel = 0; // to prevent integer from continuing to decrease  
     ticks = 0;
     digitalWrite(LED_BUILTIN, HIGH);
     color_off();
  }
  else
  {
     ShowBatteryPercentage(isCharging);
  }

  delay(wait);
}
