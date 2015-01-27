#ifndef _HC_SR04
#define _HC_SR04
 
#include "application.h"
 
class HC_SR04
{
public: 
  HC_SR04(int trigPin, int echoPin);  
  double getDistanceCM();  
  double getDistanceInch();
}
 
#endif  
