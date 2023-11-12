// The goal of today is to create something of your own creation using only the components and concepts we've covered so far.

// My idea is to keep the board configuation the same as day 4 but to change what the various dipswitch configurations do. 

// each switch will add a number of blinks per second to the blink sequence.

int LED1 = 10;   // HERO board pin 10
int LED2 = 11;   // HERO board pin 11
int LED3 = 12;   // HERO board pin 12
int Switch1 = 2; // Input pin 2
int Switch2 = 3; // Input pin 3
int Switch3 = 4; // Input pin 4

int blinksPerSecond = 0;

void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(Switch1, INPUT);
    pinMode(Switch2, INPUT);
    pinMode(Switch3, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int blinksPerSecond = 0;

    // when switch 1 is on, LED Sequence will blink one more time per second
    if(digitalRead(Switch1) == HIGH)
    {
        blinksPerSecond++;
        Serial.println("Switch 1 is on");
        Serial.println(blinksPerSecond);

    }
    // // when switch 2 is on, LED Sequence will blink 2 more times per second
    if(digitalRead(Switch2) == HIGH)
    {
        blinksPerSecond += 2;
        Serial.println("Switch 2 is on");
        Serial.println(blinksPerSecond);
    }

    // // when switch 3 is on, LED Sequence will blink 3 more times per second
    if(digitalRead(Switch3) == HIGH)
    {
        blinksPerSecond += 3;
        Serial.println("Switch 3 is on");
        Serial.println(blinksPerSecond);
    }

    // run the blink sequence if the number of blinks per second is greater than 0
    if(blinksPerSecond > 0)
    {
        Serial.println("blinking");
        Serial.println(blinksPerSecond);
        blinkSequence(1000/blinksPerSecond);
    }
    
}

void blink(int LED, int delayTime)
{
    digitalWrite(LED, HIGH);
    delay(delayTime); // duration that the light is on
    digitalWrite(LED, LOW);
}

void blinkSequence(int delayTime) 
{
    blink(LED1, delayTime);
    blink(LED2, delayTime);
    blink(LED3, delayTime);
}














// I want to make it so that the first switch turns on the first LED, the second switch turns on the second LED, and the third switch turns on the third LED. I also want to make it so that if the first and second switches are on, the third LED will blink. If the first and third switches are on, the second LED will blink. If the second and third switches are on, the first LED will blink. If all three switches are on, all three LEDs will blink. If no switches are on, no LEDs will be on.