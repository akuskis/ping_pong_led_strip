#pragma once

class GameState;

class StateMachine
{
public:
    StateMachine();
    ~StateMachine();

    void replace(GameState* state);

    void update();
    void render();

private:
    GameState* state_;
    GameState* replacement_state_;
};
