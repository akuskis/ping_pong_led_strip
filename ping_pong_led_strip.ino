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

/*

void draw_zone_a()
{
    for (int i = 0; i < ZONE_SIZE; ++i)
        leds[i] = CRGB(0, 55, 55);
}

void draw_zone_b()
{
    for (int i = NUM_LEDS - ZONE_SIZE; i < NUM_LEDS; ++i)
        leds[i] = CRGB(0, 55, 55);
}

    int pos = 0;
    int direction = 1;

    while (true)
    {
        FastLED.clear();

        draw_zone_a();
        draw_zone_b();

        if (pos + direction < 0 || NUM_LEDS <= pos + direction)
            direction *= -1;
        pos += direction;
        leds[pos] = CRGB(255, 0, 0);

        Player player_a(PLAYER_A_PIN);
        Player player_b(PLAYER_B_PIN);

        // create game
        //    states
        //       if loaded... wait when both players will trigger the button
        //       if player pressed button (when on its side, send ball back)
        //       else score a goal
        //       if ball was out of the range, score

        FastLED.show();
        delay(20);
    }
*/

/*

        int button_a = digitalRead(PLAYER_A_PIN);
        if (button_a == HIGH)
            break;

        int button_b = digitalRead(PLAYER_B_PIN);
        if (button_b == HIGH)
            break;
*/