//
// Created by leandro on 22/03/2021.
//

#include <SDL.h>
#include <game/ConfigurationGame.h>
#include "FrameRate.h"

void FrameRate::initialize() {
    lastTime = SDL_GetTicks();
}

Uint32 FrameRate::getFrameRate() {
    return controller.rate;
}

Uint32 FrameRate::getTicks() {
    Uint32 ticks = SDL_GetTicks();

    if (ticks == 0) {
        return 1;
    } else {
        return ticks;
    }
}

void FrameRate::init() {
    controller.frameCount = 0;
    controller.rate = FPS_DEFAULT;
    controller.rateTicks = (1000.0f / (float) FPS_DEFAULT);
    controller.baseTicks = getTicks();
    controller.lastTicks = controller.baseTicks;
}

void FrameRate::calculate() {

    ConfigurationGame config;
    config.load();

    init();
    delay();
}

void FrameRate::delay() {
    Uint32 current_ticks;
    Uint32 target_ticks;
    Uint32 the_delay;
//    Uint32 time_passed = 0;

    controller.frameCount++;

    current_ticks = getTicks();
//    time_passed = current_ticks - controller.lastTicks;
    controller.lastTicks = current_ticks;
    target_ticks = controller.baseTicks + (Uint32) ((float) controller.frameCount * controller.rateTicks);

    if (current_ticks <= target_ticks) {
        the_delay = target_ticks - current_ticks;
        SDL_Delay(the_delay);
    } else {
        controller.frameCount = 0;
        controller.baseTicks = getTicks();
    }
}