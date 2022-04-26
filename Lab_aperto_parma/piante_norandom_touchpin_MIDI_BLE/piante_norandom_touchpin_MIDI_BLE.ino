//Bluetooth touch sensor NO RANDOM for Parma Open Lab in 2022
//Made by "Chi ha ucciso Il Conte?"  from an Antonio de Vincentiis code
//chihauccisoilconte.eu


#include <Arduino.h>
#include <BLEMidi.h>

// TOUCH
const int TOUCH_NUM_READINGS = 3; // number of positive read for switch on
int touchReadIndex = 0;
int touchTotal1 = 0;
int touchTotal2 = 0;
int touchTotal3 = 0;
int touchTotal4 = 0;
int touchTotal5 = 0;


const int TOUCH_PIN_1 = 12;
const int TOUCH_PIN_2 = 14;
const int TOUCH_PIN_3 = 27;
const int TOUCH_PIN_4 = 33;
const int TOUCH_PIN_5 = 32;

//const int LED_PIN1=25; // default on Heltec WiFi Kit32

const int TOUCH_THRESHOLD_1 = 35;
const int TOUCH_THRESHOLD_2 = 35;
const int TOUCH_THRESHOLD_3 = 35;
const int TOUCH_THRESHOLD_4 = 35;
const int TOUCH_THRESHOLD_5 = 35;



const int ledPin1 = 16;
const int ledPin2 = 17;
const int ledPin3 = 5;
const int ledPin4 = 18;
const int ledPin5 = 19;

int ledState1 = LOW;             // ledState used to set the LED
int ledState2 = LOW;             // ledState used to set the LED
int ledState3 = LOW;             // ledState used to set the LED
int ledState4 = LOW;             // ledState used to set the LED
int ledState5 = LOW;             // ledState used to set the LED


void setup() {

  Serial.begin(115200);
  Serial.println("Initializing bluetooth");
  BLEMidiServer.begin("Basic MIDI device");
  Serial.println("Waiting for connections...");
  delay(1000);

  pinMode(TOUCH_PIN_1, INPUT);
  pinMode(TOUCH_PIN_2, INPUT);
  pinMode(TOUCH_PIN_3, INPUT);
  pinMode(TOUCH_PIN_4, INPUT);
  pinMode(TOUCH_PIN_5, INPUT);

  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
  pinMode (ledPin5, OUTPUT);


}

void touch_monitor(void) {
  Serial.print("Touch values:  ");
  Serial.print(touchRead(TOUCH_PIN_1));
  Serial.print(" - ");
  Serial.print(touchRead(TOUCH_PIN_2));
  Serial.println();
  Serial.print("Touch events: ");
  Serial.print(touchTotal1);
  Serial.print(" - ");
  Serial.print(touchTotal2);
  Serial.println();
}


void loop() {

  if (TOUCH_THRESHOLD_1 > touchRead(TOUCH_PIN_1)) {
    touchTotal1++;
  }
  if (TOUCH_THRESHOLD_2 > touchRead(TOUCH_PIN_2)) {
    touchTotal2++;
  }

  if (TOUCH_THRESHOLD_3 > touchRead(TOUCH_PIN_3)) {
    touchTotal3++;
  }
  if (TOUCH_THRESHOLD_4 > touchRead(TOUCH_PIN_4)) {
    touchTotal4++;
  }

  if (TOUCH_THRESHOLD_5 > touchRead(TOUCH_PIN_5)) {
    touchTotal5++;
  }


  // uncomment for activate serial monitor
  touch_monitor();

//touch1

  if (touchTotal1 >= TOUCH_NUM_READINGS) {
    digitalWrite(ledPin1, HIGH);

    Serial.println(" - LED on");
    BLEMidiServer.noteOn(0, 69, 127);
    delay(1000);
    BLEMidiServer.noteOff(0, 69, 127);

  } else {
    // turn LED off
    digitalWrite(ledPin1, LOW);
    Serial.println(" - LED off");
  }

//touch2

  if (touchTotal2 >= TOUCH_NUM_READINGS) {
    digitalWrite(ledPin2, HIGH);

    Serial.println(" - LED on");
    BLEMidiServer.noteOn(0, 70, 127);
    delay(1000);
    BLEMidiServer.noteOff(0, 70, 127);

  } else {
    // turn LED off
    digitalWrite(ledPin2, LOW);
    Serial.println(" - LED off");
  }

//touch3

    if (touchTotal3 >= TOUCH_NUM_READINGS) {
    digitalWrite(ledPin3, HIGH);

    Serial.println(" - LED on");
    BLEMidiServer.noteOn(0, 71, 127);
    delay(1000);
    BLEMidiServer.noteOff(0, 71, 127);

  } else {
    // turn LED off
    digitalWrite(ledPin3, LOW);
    Serial.println(" - LED off");
  }

  //touch4
  
    if (touchTotal4 >= TOUCH_NUM_READINGS) {
    digitalWrite(ledPin4, HIGH);

    Serial.println(" - LED on");
    BLEMidiServer.noteOn(0, 72, 127);
    delay(1000);
    BLEMidiServer.noteOff(0, 72, 127);

  } else {
    // turn LED off
    digitalWrite(ledPin4, LOW);
    Serial.println(" - LED off");
  }

//touch5

      if (touchTotal5 >= TOUCH_NUM_READINGS) {
    digitalWrite(ledPin5, HIGH);

    Serial.println(" - LED on");
    BLEMidiServer.noteOn(0, 73, 127);
    delay(1000);
    BLEMidiServer.noteOff(0, 73, 127);

  } else {
    // turn LED off
    digitalWrite(ledPin5, LOW);
    Serial.println(" - LED off");
  }



  // end read sequence to the beginning
  if (touchReadIndex >= TOUCH_NUM_READINGS) {
    touchReadIndex = 0;
    touchTotal1 = 0;
    touchTotal2 = 0;
    touchTotal3 = 0;
    touchTotal4 = 0;
    touchTotal5 = 0;

  }
  touchReadIndex++;

  delay(100);
}
