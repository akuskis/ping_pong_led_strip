#include "StateMachine.hpp"

#include "GameState.hpp"

StateMachine::StateMachine()
  : state_(nullptr),
    replacement_state_(nullptr)
{
}

StateMachine::~StateMachine()
{
    delete replacement_state_;
    delete state_;
}

void StateMachine::replace(GameState* state)
{
    replacement_state_ = state;
}

void StateMachine::update()
{
    if (state_)
        state_->update();

    if (replacement_state_)
    {
        delete state_;
        state_ = replacement_state_;
        replacement_state_ = nullptr;
    }
}

void StateMachine::render()
{
    if (state_)
        state_->render();
}

int StateMachine::getDelay()
{
    return state_ ? state_->getDelay() : 100;
}