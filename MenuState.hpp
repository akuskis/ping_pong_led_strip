#pragma once

#include "GameState.hpp"
#include "Settings.hpp"

class MenuState : public GameState
{
public:
    MenuState(Settings& settings);

    void update() override;
    void render() override;

private:
    Settings& settings_;

    bool player_a_ready_;
    bool player_b_ready_;
};
