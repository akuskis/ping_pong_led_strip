#include "Game.hpp"

#include "MenuState.hpp"
#include "Settings.hpp"

#include <FastLED.h>

Game::Game(Settings& settings)
  : is_running_(true)
{
    state_.replace(new MenuState{settings, state_});
}

void Game::run()
{
    while (is_running_)
    {
        update_();
        render_();
        delay_();
    }
}

void Game::update_()
{
    state_.update();
}

void Game::render_()
{
    FastLED.clear();
    state_.render();
    FastLED.show();
}

void Game::delay_()
{
    // delay is incorrect solution here because this is not related to FPS
    // so on different HW game will play differently (but this is a toy to play at home)
    delay(state_.getDelay());
}
