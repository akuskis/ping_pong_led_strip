#pragma once

#include "GameState.hpp"

class StateMachine
{
public:
    StateMachine(GameState* state);
    ~StateMachine();

    void replace(GameState* state);

    void update();
    void render();

private:
    GameState* state_;
    GameState* replacement_state_;
};
