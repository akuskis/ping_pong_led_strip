#pragma once

class CRGB;

struct Settings
{
public:
    int const BUTTON_A;
    int const BUTTON_B;
    int const LED_PIN;
    int const NUM_LEDS;
    int const ZONE_SIZE;

    CRGB* leds;
};
