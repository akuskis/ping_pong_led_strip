#pragma once

#include "Settings.hpp"
#include "StateMachine.hpp"

class GameState
{
public:
    GameState(Settings const& settings, StateMachine& state);

    virtual void update() = 0;
    virtual void render() = 0;

    Settings const& settings() const;
    StateMachine& state();

private:
    Settings const& settings_;
    StateMachine& state_;
};
