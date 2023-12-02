#include "StateMachine.hpp"

StateMachine::StateMachine(GameState* state)
  : state_(state),
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
    state_->render();
}
