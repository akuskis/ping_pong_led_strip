#include "PlayState.hpp"

#include "WinnerState.hpp"

#include <FastLED.h>

namespace
{
int const MAX_SPEED = 20;
int const SCORE_TO_WIN = 4;

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

    handleEvents_();

    if (!is_playing_)
        return;

    ball_position_ += ball_direction_;

    if (ball_position_ < 0)
        scoreB_();
    else if (ball_position_ == settings().NUM_LEDS)
        scoreA_();

    if (score_ == -SCORE_TO_WIN)
        state().replace(new WinnerState(settings(), state(), WinnerState::Winner::PlayerA));

    if (score_ == SCORE_TO_WIN)
        state().replace(new WinnerState(settings(), state(), WinnerState::Winner::PlayerB));
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
    if (0 <= ball_position_ && ball_position_ < settings().NUM_LEDS)
        settings().leds[ball_position_] = BALL_COLOR;
}

void PlayState::handleEvents_()
{
    bool button_a = digitalRead(settings().BUTTON_A);
    if (!button_a_ && button_a == HIGH)
        onButtonA_();
    button_a_ = button_a;

    bool button_b = digitalRead(settings().BUTTON_B);
    if (!button_b_ && button_b == HIGH)
        onButtonB_();
    button_b_ = button_b;
}

void PlayState::onButtonA_()
{
    if (ball_position_ < 0 || settings().ZONE_SIZE <= ball_position_)
        scoreB_();
    else
    {
        speed_ = settings().ZONE_SIZE - ball_position_;
        ball_direction_ *= -1;
    }
}

void PlayState::onButtonB_()
{
    if (ball_position_ < settings().NUM_LEDS - settings().ZONE_SIZE || settings().NUM_LEDS <= ball_position_)
        scoreA_();
    else
    {
        speed_ = settings().ZONE_SIZE - (settings().NUM_LEDS - ball_position_ - 1);
        ball_direction_ *= -1;
    }
}

void PlayState::scoreA_()
{
    --score_;
    is_playing_ = false;
}

void PlayState::scoreB_()
{
    ++score_;
    is_playing_ = false;
}
