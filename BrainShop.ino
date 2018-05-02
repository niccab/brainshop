#include "FastLED.h"

#define NUM_LEDS 10
#define NUM_STRIPS 3
#define COLOR_ORDER RGB
#define MAX_BRIGHTNESS 128
#define MIN_BRIGHTNESS 32

#define FORWARD 0
#define BACKWARD 1
#define SLOW 250
#define MEDIUM 50
#define FAST 5

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];

const int color1 = A0;
const int color2 = A1;
const int color3 = A2;

void setup() {

Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 4>(leds1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, 3>(leds2, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, 2>(leds3, NUM_LEDS);

  FastLED.setBrightness(MAX_BRIGHTNESS);
}


void loop() {

  int mappedValue = map(analogRead(A3), 0, 1023, 0, 255);


  for (int i = 0; i < NUM_LEDS; i++) {
    int mappedHue = map(analogRead(color1), 0, 1023, 0, 255);
    leds1[i] = CHSV(mappedHue, 255, mappedValue);
    FastLED.show();
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    int mappedHue = map(analogRead(color2), 0, 1023, 0, 255);
    leds2[i] = CHSV(mappedHue, 255, mappedValue);
    FastLED.show();
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    int mappedHue = map(analogRead(color3), 0, 1023, 0, 255);
    leds3[i] = CHSV(mappedHue, 255, mappedValue);
    FastLED.show();
  }


  int eval1 = analogRead(0);
  int emotion1 = map(eval1, 0, 1023, 0, 100);

  int eval2 = analogRead(1);
  int emotion2 = map(eval2, 0, 1023, 0, 100);

  int eval3 = analogRead(2);
  int emotion3 = map(eval3, 0, 1023, 0, 100);


  Serial.write(emotion1);
  Serial.write(emotion2);
  Serial.write(emotion3);


  delay(50); //be nice

}






//
//
//
//
//  //0  Purple (BACK)
//  if (sensorState0 == LOW) {
//    digitalWrite(solenoidPin0, LOW);
//    colorwipe0();
//  }
//
//  if (sensorState0 == HIGH) {
//    rainbow0();
//  }
//
//
//  //1 Blue
//  if (sensorState1 == LOW) {
//    digitalWrite(solenoidPin1, LOW);
//    colorwipe1();
//  }
//
//  if (sensorState1 == HIGH) {
//    rainbow1();
//  }
//
//
//
//  //2 Green
//  if (sensorState2 == LOW) {
//    digitalWrite(solenoidPin2, LOW);
//    colorwipe2();
//  }
//
//  if (sensorState2 == HIGH) {
//    rainbow2();
//  }
//
//
//  //3 Yellow
//
//  if (sensorState3 == LOW) {
//    digitalWrite(solenoidPin3, LOW);
//    colorwipe3();
//  }
//
//  if (sensorState3 == HIGH) {
//    rainbow3();
//  }
//
//  //4 Red (Front)
//
//  if (sensorState4 == LOW) {
//    digitalWrite(solenoidPin4, LOW);
//    colorwipe4();
//  }
//
//  if (sensorState4 == HIGH) {
//    rainbow4();
//  }
//
//  FastLED.show();
//
//}
//
//void rainbow0() {
//  // the moving rainbow
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    leds0[i] = CHSV((millis() / 4) - (i * 3), 255, 255);
//  }
//}
//
//void rainbow1() {
//  // the moving rainbow
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    leds1[i] = CHSV((millis() / 4) - (i * 3), 255, 255);
//  }
//}
//
//void rainbow2() {
//  // the moving rainbow
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    leds2[i] = CHSV((millis() / 4) - (i * 3), 255, 255);
//  }
//}
//
//void rainbow3() {
//  // the moving rainbow
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    leds3[i] = CHSV((millis() / 4) - (i * 3), 255, 255);
//  }
//}
//
//void rainbow4() {
//  // the moving rainbow
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    leds4[i] = CHSV((millis() / 4) - (i * 3), 255, 255);
//  }
//}
//
//
//
//// Wipes color from end to end
//void colorwipe0() {
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    uint8_t red = (millis() / 3) + (i * 5);
//    if (red > 128) red = 0;
//    leds0[i] = CRGB(255, 0, 255);
//  }
//}
//
//void colorwipe1() {
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    uint8_t red = (millis() / 3) + (i * 5);
//    if (red > 128) red = 0;
//    leds1[i] = CRGB(0,125,255);
//  }
//}
//
//void colorwipe2() {
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    uint8_t red = (millis() / 3) + (i * 5);
//    if (red > 128) red = 0;
//    leds2[i] = CRGB(0,255,0);
//  }
//}
//
//void colorwipe3() {
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    uint8_t red = (millis() / 3) + (i * 5);
//    if (red > 128) red = 0;
//    leds3[i] = CRGB(255,255,0);
//  }
//}
//
//void colorwipe4() {
//  for (uint16_t i = 0; i < NUM_LEDS; i++) {
//    uint8_t red = (millis() / 3) + (i * 5);
//    if (red > 128) red = 0;
//    leds4[i] = CRGB(255,0,0);
//  }
//}
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//CRGB Wheel(byte WheelPos) {
//  if (WheelPos < 85) {
//    return CRGB(WheelPos * 3, 255 - WheelPos * 3, 0);
//  }
//  else if (WheelPos < 170) {
//    WheelPos -= 85;
//    return CRGB(255 - WheelPos * 3, 0, WheelPos * 3);
//  }
//  else {
//    WheelPos -= 170;
//    return CRGB(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
//
//CRGB randomColor() {
//  return Wheel(random(256));
//}
//
//

