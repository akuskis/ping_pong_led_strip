#include "GameState.hpp"

GameState::GameState(Settings const& settings, StateMachine& state)
  : settings_(settings),
    state_(state)
{
}

Settings const& GameState::settings() const
{
    return settings_;
}

StateMachine& GameState::state()
{
    return state_;
}
