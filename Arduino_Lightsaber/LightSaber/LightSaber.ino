// --- LIBRARIES ---
#include <Adafruit_NeoPixel.h> // ARGB LED library
#include <toneAC.h>            // A specialized speaker LIBRARY
#include "Wire.h"
#include "MPU6050.h"           // Gyro library
#include "I2Cdev.h"
MPU6050 accelgyro;

// --- VARIABLES ---
#define PIN_LED 3
#define PIN_BUTTON 4
#define PIN_VIBMOTOR 6
#define PIN_SPEAKER 9
#define NUMPIXELS 94
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN_LED, NEO_GRB + NEO_KHZ800);
#define VIB_L 200
#define VIB_H 400

boolean LED_state = false;

int16_t ax, ay, az;
int16_t gx, gy, gz;
unsigned long ACC, GYR, COMPL;
int gyroX, gyroY, gyroZ, accelX, accelY, accelZ, freq, freq_f = 20;
float k = 0.2;
unsigned long mpuTimer;

short redColor = 0;
short greenColor = 0;
short blueColor = 0;
short colorCounter = 0;
short colorStates[3][3] = {{255,0,0},{0,255,0},{0,0,255}};

short redColorF = 0;
short greenColorF = 0;
short blueColorF = 0;
short f = 0;
short colorStatesF[3][3] = {{255,f,f},{f,255,f},{f,f,255}};



byte buttonState = 0;
unsigned long timePress = 0;
unsigned long timePressLimit = 0;
byte clicks = 0;
byte buttonPushCounter = 0;

// --- SETUP ---
void setup() {  
  Serial.begin(9600);
  Wire.begin();
  pixels.begin();
  pinMode (PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_VIBMOTOR, OUTPUT);

accelgyro.initialize();
  accelgyro.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
  accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_250);
}


// --- MAIN LOOP ---
void loop() {
  getFreq();
  buttonFunc();
  ledFunc();
  vibmotorFunc();
  flickerLED();
  freqFunc();
  if (LED_state == false) noToneAC();;
}


// --- FUNCTIONS ---

// -LED FUNCTIONS- 

// Sequently changes the LED's color depending on how many clicks it's been
void setColor() {
  if (colorCounter == 3) colorCounter = 0;
  redColor = colorStates[colorCounter][0];
  greenColor = colorStates[colorCounter][1];
  blueColor = colorStates[colorCounter][2];
  for (int i=0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    pixels.setPixelColor(NUMPIXELS-(1+i), pixels.Color(redColor, greenColor, blueColor));
    long a = 0.6 + i*0.1;
    toneAC(freq_f, a);
    if (LED_state == true) {
      pixels.show();
    }
    else {
      delay(20);
      pixels.show();}
  }
  delay(10);
}

// Gives the LED a flickering effect depending on the computed gyro frequency (which is mentioned below)
void flickerLED() {
  if (LED_state == true && millis() > 200) {
   pixels.clear();
   pixels.show();
   delay(8);
    
    if (freq_f > 20 && freq_f < 255) {
      f = freq_f;
      redColorF = colorStatesF[colorCounter][0];
      greenColorF = colorStatesF[colorCounter][1];
      blueColorF = colorStatesF[colorCounter][2];
      pixels.fill(pixels.Color(redColorF, greenColorF, blueColorF), 0, 94);
    }
    else if (freq_f < 20) {
      pixels.fill(pixels.Color(redColor, greenColor, blueColor), 0, 94);        
    }
    else if (freq_f > 255) {
      pixels.fill(pixels.Color(255,255,255), 0, 94);   
    }
    pixels.show();
    delay(8);
  }
}

// Click counter
void buttonFunc() {
  buttonState = digitalRead(PIN_BUTTON);
  if (buttonState == HIGH){
    delay(200);
    Serial.println("Button Pressed");
    if (clicks == 0) {
      timePress = millis();
      timePressLimit = timePress + 500;    
      clicks = 1;
    }

    else if (clicks == 1 && millis() < timePressLimit){
      Serial.println("Button Pressed twice");
      timePress = 0;
      timePressLimit = 0;
      clicks = 0;
      buttonPushCounter = 2;
    }    
  }

  if (clicks == 1 && timePressLimit != 0 && millis() > timePressLimit){
     Serial.println("Button Pressed Once");
     timePress = 0;
     timePressLimit = 0;
     clicks = 0;
     buttonPushCounter = 1;
  }
}

// Primary function for the LED, also controls the vibration motor depending on turning off-on etc.
void ledFunc() {
  if (buttonPushCounter == 1 && LED_state == false) {
    Serial.println("Turn on");
    analogWrite(PIN_VIBMOTOR, VIB_L);
    setColor();
    LED_state = true;
    buttonPushCounter = 0;
    delay(100);
  }
  else if (buttonPushCounter == 1 && LED_state == true) {
    Serial.println("Change colour");
    analogWrite(PIN_VIBMOTOR, VIB_L);
    colorCounter++;
    setColor();
    buttonPushCounter = 0;
    delay(100);
   }
  else if (buttonPushCounter == 2 && LED_state == true) {
    Serial.println("Turn off");
    LED_state = false;
    buttonPushCounter = 0;
    for (int i = 0; i < NUMPIXELS/2; i++) {
      pixels.setPixelColor(NUMPIXELS/2-(1+i), 0, 0, 0);
      pixels.setPixelColor(NUMPIXELS/2+i, 0, 0, 0);
      pixels.show();
      long a = 10 - i*0.1;
      toneAC(freq_f, a);
      delay(20);
    }
    noToneAC();
    delay(100);
  }
}

//Vibration motor function
void vibmotorFunc() {
  if (LED_state == true) {
    analogWrite(PIN_VIBMOTOR, VIB_H);
  }
  else {analogWrite(PIN_VIBMOTOR, 0);}
}

// Reads the gyro and computes a frequency for the speaker
void getFreq() {
  if (LED_state == true) {                                               // if GyverSaber is on
    if (millis() - mpuTimer > 500) {                            
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);       

      // find absolute and divide on 100
      gyroX = abs(gx / 150);
      gyroY = abs(gy / 150);
      gyroZ = abs(gz / 150);
      accelX = abs(ax / 25);
      accelY = abs(ay / 25);
      accelZ = abs(az / 25);

      // vector sum
      ACC = sq((long)accelX) + sq((long)accelY) + sq((long)accelZ);
      ACC = sqrt(ACC);
      GYR = sq((long)gyroX) + sq((long)gyroY) + sq((long)gyroZ);
      GYR = sqrt((long)GYR);
      COMPL = ACC + GYR;

         Serial.print("$");
         Serial.print(gyroX);
         Serial.print(" ");
         Serial.print(gyroY);
         Serial.print(" ");
         Serial.print(gyroZ);
         Serial.println(";");
         Serial.println(freq_f);

      freq = (long)COMPL * COMPL / 1500;                        // parabolic tone change
      freq = constrain(freq, 18, 300);                          
      freq_f = freq * k + freq_f * (1 - k);                     // smooth filter
      mpuTimer = micros();
    }
  }
}

// Speaker function, uses the computed frequency
void freqFunc() {
  if (LED_state == true) {
      toneAC(freq_f);
      delay(10);
  }
}
