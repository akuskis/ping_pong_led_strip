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

        FastLED.clear();
        render_();
        FastLED.show();

        delay(50);
    }
}

void Game::update_()
{
    state_.update();
}

void Game::render_()
{
    state_.render();
}
