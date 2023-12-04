#include "WinnerState.hpp"


WinnerState::WinnerState(Settings const& settings, StateMachine& state, Winner winner)
  : GameState(settings, state),
    winner_(winner)
{
}

void WinnerState::update()
{
}

void WinnerState::render()
{
    // show winner as flicking green zone
    // looser show as flicking red zone
}

int WinnerState::getDelay() const
{
    return 100;
}
