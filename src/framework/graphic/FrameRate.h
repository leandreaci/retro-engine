//
// Created by leandro on 22/03/2021.
//

#ifndef RETRO_ENGINE_FRAMERATE_H
#define RETRO_ENGINE_FRAMERATE_H

#define FPS_DEFAULT		30
#define FPS_LOWER_LIMIT		1
#define FPS_UPPER_LIMIT		200

class FrameRate {

public:
    Uint32 getFrameRate();
    void calculate();
    void initialize();

private:
    Uint32 getTicks();

    typedef struct {
        Uint32 frameCount;
        float rateTicks;
        Uint32 baseTicks;
        Uint32 lastTicks;
        Uint32 rate;
    } FpsController;

    FpsController controller;

    void init();

    void delay();
};


#endif //RETRO_ENGINE_FRAMERATE_H
