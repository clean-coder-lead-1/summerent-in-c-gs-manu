#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(50, 20, 30) == TOO_HIGH);
  
}
TEST_CASE("Classifies the breach according to type of cooling") 
{
	REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
	REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
	REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
	
	
	REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
	REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) == TOO_LOW);
	REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 44) == NORMAL);	
	
	REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 50) == TOO_HIGH);
	REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
	REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39) == NORMAL);
}
TEST_CASE("Checks if an alert is needed based on the breach type") 
{
	REQUIRE(isAlertNeeded(NORMAL) == false);
	REQUIRE(isAlertNeeded(TOO_HIGH) == true);
	REQUIRE(isAlertNeeded(TOO_LOW) == true);
}
  
