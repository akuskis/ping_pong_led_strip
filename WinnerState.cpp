#include "WinnerState.hpp"

#include "MenuState.hpp"


namespace
{
CRGB const WINNER_COLOR(0, 155, 0);
CRGB const LOOSER_COLOR(155, 0, 0);
} // namespace


WinnerState::WinnerState(Settings const& settings, StateMachine& state, Winner winner)
  : GameState(settings, state),
    player_a_color_(winner == Winner::PlayerA ? WINNER_COLOR : LOOSER_COLOR),
    player_b_color_(winner == Winner::PlayerB ? WINNER_COLOR : LOOSER_COLOR)
{
}

void WinnerState::update()
{
    ++count_;

    if (count_ == 50)
        state().replace(new MenuState(settings(), state()));
}

void WinnerState::render()
{
    if (count_ % 2)
    {
        for (int i = 0; i < settings().NUM_LEDS / 2; ++i)
            settings().leds[i] = player_a_color_;

        for (int i = settings().NUM_LEDS / 2; i < settings().NUM_LEDS; ++i)
            settings().leds[i] = player_b_color_;
    }
}

int WinnerState::getDelay() const
{
    return 100;
}
