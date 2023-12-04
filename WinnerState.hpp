#pragma once

#include "GameState.hpp"

#include "FastLED.h"

class WinnerState : public GameState
{
public:
    enum class Winner
    {
        PlayerA,
        PlayerB
    };

    WinnerState(Settings const& settings, StateMachine& state, Winner winner);

    void update() override;
    void render() override;
    int getDelay() const override;

private:
    int count_ = 0;

    CRGB player_a_color_;
    CRGB player_b_color_;
};
