#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"
extern "C" {
#include "duration.h"
}

// See Catch2's documentation:
// https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Test the constructor, both with and without arguments
TEST_CASE("Constructor") {
    Duration d1;
    REQUIRE(d1.getDuration() == 0);

    Duration d2(10);
    REQUIRE(d2.getDuration() == 10);
}

// Test the tick function, both with and without arguments
TEST_CASE("Tick") {
    Duration d3;
    REQUIRE(d3.getDuration() == 0);
    d3.tick();
    d3.tick();
    REQUIRE(d3.getDuration() == 2);
    d3.tick(4);
    REQUIRE(d3.getDuration() == 6);
}

// Test alarm function
TEST_CASE("Alarm") {
    Duration d4;
    d4.setAlarm(3);
    REQUIRE(d4.tick() == false);
    REQUIRE(d4.tick(5) == true);
    REQUIRE(d4.tick(2) == false);
    d4.setAlarm(5);
    REQUIRE(d4.tick(3) == false);
    d4.setAlarm(13);
    REQUIRE(d4.tick() == false);
    REQUIRE(d4.tick() == false);
    REQUIRE(d4.tick() == true);
}