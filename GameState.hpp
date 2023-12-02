#pragma once

class GameState
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
};
