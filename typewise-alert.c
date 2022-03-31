#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  BreachType breach;
  breach = (value < lowerLimit) ? TOO_LOW : ((value > upperLimit) ? TOO_HIGH : NORMAL); // is this better?

  return breach;  
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0; // Always 0 for now
  int upperLimit = 0;
  
  switch(coolingType) // I still like the swtich statement here because there can be more types of cooling!
  {
    case HI_ACTIVE_COOLING:
		upperLimit = 45;
		break;
    case MED_ACTIVE_COOLING:
		upperLimit = 40;
		break;
	default:
		int upperLimit = 35; // Assume passive cooling by default
		break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType) 
  {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
	default:
      break;
  }
}
