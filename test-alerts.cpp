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
}
  
