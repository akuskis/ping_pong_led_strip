#pragma once

#include "GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState(Settings const& settings, StateMachine& state);

    void update() override;
    void render() override;
};
