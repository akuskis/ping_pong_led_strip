#include "PlayState.hpp"

#include <FastLED.h>

namespace
{
int const MAX_SPEED = 20;

CRGB const ZONE_COLOR(0, 55, 55);
CRGB const BALL_COLOR(255, 0, 0);
CRGB const SCORE_COLOR(0, 255, 0);
} // namespace


PlayState::PlayState(Settings const& settings, StateMachine& state)
  : GameState(settings, state)
{
}

void PlayState::update()
{
    if (!is_playing_)
    {
        startRound_();
        return;
    }

    // check when player press the button (was not pressed before
    //    if not in range... score a loss
    //    if in range (and direction is good)... change direction and speed

    ball_position_ += ball_direction_;

    if (ball_position_ < 0)
    {
        ++score_;
        is_playing_ = false;
    }
    else if (ball_position_ == settings().NUM_LEDS)
    {
        --score_;
        is_playing_ = false;
    }

    if (score_ < -5 || 5 < score_)
    {
        // TODO: change state to show the winner
    }
}

void PlayState::render()
{
    drawZoneA_();
    drawZoneB_();
    drawScore_();
    drawBall_();
}

int PlayState::getDelay() const
{
    return 1 + (MAX_SPEED - speed_);
}

void PlayState::startRound_()
{
    ++round_number_;

    is_playing_ = true;
    speed_ = random(MAX_SPEED) + 1;

    if (round_number_ % 2)
    {
        ball_position_ = settings().NUM_LEDS - 1;
        ball_direction_ = -1;
    }
    else
    {
        ball_position_ = 0;
        ball_direction_ = 1;
    }
}

void PlayState::drawZoneA_()
{
    auto* leds = settings().leds;
    for (int i = 0; i < settings().ZONE_SIZE; ++i)
        leds[i] = ZONE_COLOR;
}

void PlayState::drawZoneB_()
{
    auto* leds = settings().leds;
    for (int i = settings().NUM_LEDS - settings().ZONE_SIZE; i < settings().NUM_LEDS; ++i)
        leds[i] = ZONE_COLOR;
}

void PlayState::drawScore_()
{
    auto* leds = settings().leds;

    if (score_ < 0)
    {
        int pos = settings().NUM_LEDS / 2 - 1;
        for (int i = 0; score_ < i; --i)
            leds[pos + i * 2] = SCORE_COLOR;
    }
    else if (score_ > 0)
    {
        int pos = settings().NUM_LEDS / 2;
        for (int i = 0; i < score_; ++i)
            leds[pos + i * 2] = SCORE_COLOR;
    }
}

void PlayState::drawBall_()
{
    settings().leds[ball_position_] = BALL_COLOR;
}
