#include "HC_SR04.h"
 
HC_SR04::HC_SR04(int trigPin, int echoPin){
  _trigPin = trigPin;
  _echoPin = echoPin;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

double HC_SR04::getDistanceCM(){
  sendTriggerPulse(_trigPin);
  waitForEcho(_echoPin, HIGH, 100);
  long startTime = millis();
  waitForEcho(_echoPin, LOW, 100);
  long endTime = millis();
  long duration = endTime - startTime;
  double distance = duration * 1000.0 / 29.0 / 2.0;
  return distance;
}

double HC_SR04::getDistanceInch(){
  return (getDistanceCM() * 2.5);
}

void HC_SR04::sendTriggerPulse(int pin){
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
}

void HC_SR04::waitForEcho(int pin, int value, long timeout){
    long giveupTime = millis() + timeout;
    while (digitalRead(pin) != value && millis() < giveupTime) {}
}

