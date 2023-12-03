#pragma once

#include "GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState(Settings const& settings, StateMachine& state);

    void update() override;
    void render() override;
    int getDelay() const override;

private:
    bool is_playing_ = false;
    int round_number_ = -1;

    int ball_position_ = 0;
    int ball_direction_ = 0;
    int speed_ = 0;

    int score_ = 0;

    void startRound_();
    void drawZoneA_();
    void drawZoneB_();
    void drawScore_();
    void drawBall_();
};
