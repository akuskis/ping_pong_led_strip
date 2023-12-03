#pragma once

#include "GameState.hpp"

class MenuState : public GameState
{
public:
    MenuState(Settings const& settings, StateMachine& state);

    void update() override;
    void render() override;

private:
    bool player_a_ready_;
    bool player_b_ready_;
};
