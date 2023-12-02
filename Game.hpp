#pragma once

#include "StateMachine.hpp"

class Settings;

class Game
{
public:
    Game(Settings& settings);

    void run();

private:
    bool is_running_;
    StateMachine state_;

    void update_();
    void render_();
};
