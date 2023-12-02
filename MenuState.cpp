#include "MenuState.hpp"

#include <FastLED.h>

MenuState::MenuState(Settings& settings)
  : settings_(settings),
    player_a_ready_(false),
    player_b_ready_(false)
{
}

void MenuState::update()
{
    int button_a = digitalRead(settings_.BUTTON_A);
    if (button_a == HIGH)
        player_a_ready_ = true;

    int button_b = digitalRead(settings_.BUTTON_B);
    if (button_b == HIGH)
        player_b_ready_ = true;

    // if both are ready - change state
}

void MenuState::render()
{
    if (player_a_ready_)
    {
        for (int i = 0; i < settings_.ZONE_SIZE; ++i)
            settings_.leds[i] = CRGB(0, 55, 55);
    }
    else
    {
        for (int i = 0; i < settings_.NUM_LEDS / 2; ++i)
            settings_.leds[i] = CRGB(0, 55, 55);
    }

    if (player_b_ready_)
    {
        for (int i = settings_.NUM_LEDS - settings_.ZONE_SIZE; i < settings_.NUM_LEDS; ++i)
            settings_.leds[i] = CRGB(0, 55, 55);
    }
    else
    {
        for (int i = settings_.NUM_LEDS / 2; i < settings_.NUM_LEDS; ++i)
            settings_.leds[i] = CRGB(0, 55, 55);
    }
}
