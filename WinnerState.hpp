#pragma once

#include "GameState.hpp"

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
    Winner winner_;
};
