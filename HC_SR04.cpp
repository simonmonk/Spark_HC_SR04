#include "HC_SR04.h"
 
HC_SR04::HC_SR04(int trigPin, int echoPin){
  _trigPin = trigPin;
  _echPin = echoPin;
}
double HC_SR04::getDistanceCM(){

}

double HC_SR04::getDistanceInch(){
  return (getDistanceCM() * 2.5);
}

