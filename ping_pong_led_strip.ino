#include "Game.hpp"
#include "Settings.hpp"

#include <FastLED.h>

namespace
{
int const LED_PIN = 2;
int const PLAYER_A_PIN = 3;
int const PLAYER_B_PIN = 4;

int const NUM_LEDS = 100;
int const ZONE_SIZE = 20;

CRGB leds[NUM_LEDS];
} // namespace

void setup()
{
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 350);
    FastLED.clear();
    FastLED.show();

    randomSeed(analogRead(5));

    pinMode(PLAYER_A_PIN, INPUT);
    pinMode(PLAYER_B_PIN, INPUT);
}

void loop()
{
    Settings settings{PLAYER_A_PIN, PLAYER_B_PIN, LED_PIN, NUM_LEDS, ZONE_SIZE, leds};
    Game game(settings);

    game.run();
}
