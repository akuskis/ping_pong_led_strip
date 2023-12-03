#include "MenuState.hpp"

#include "PlayState.hpp"

#include <FastLED.h>

MenuState::MenuState(Settings const& settings, StateMachine& state)
  : GameState(settings, state),
    player_a_ready_(false),
    player_b_ready_(false)
{
}

void MenuState::update()
{
    if (digitalRead(settings().BUTTON_A) == HIGH)
        player_a_ready_ = true;

    if (digitalRead(settings().BUTTON_B) == HIGH)
        player_b_ready_ = true;

    if (player_a_ready_ && player_b_ready_)
        state().replace(new PlayState(settings(), state()));
}

void MenuState::render()
{
    if (player_a_ready_)
    {
        for (int i = 0; i < settings().ZONE_SIZE; ++i)
            settings().leds[i] = CRGB(0, 55, 55);
    }
    else
    {
        for (int i = 0; i < settings().NUM_LEDS / 2; ++i)
            settings().leds[i] = CRGB(0, 55, 55);
    }

    if (player_b_ready_)
    {
        for (int i = settings().NUM_LEDS - settings().ZONE_SIZE; i < settings().NUM_LEDS; ++i)
            settings().leds[i] = CRGB(0, 55, 55);
    }
    else
    {
        for (int i = settings().NUM_LEDS / 2; i < settings().NUM_LEDS; ++i)
            settings().leds[i] = CRGB(0, 55, 55);
    }
}
