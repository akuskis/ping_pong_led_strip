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
    int getDelay();

private:
    GameState* state_;
    GameState* replacement_state_;
};
