//
// Created by Le on 16/06/22.
//

#ifndef RETRO_ENGINE_CAMERA_H
#define RETRO_ENGINE_CAMERA_H

#include <framework/Entity.h>
#include <framework/Stage.h>
#include <framework/PlayerController.h>

class Camera {

public:
    Stage* stage{};
    PlayerController* player{};
    void setCurrentFrame();
    void setStage(Stage* stage);
    void setPlayer(PlayerController* playerController);
    int cont = 1;

    void moveForward();

    void update();
};

#endif //RETRO_ENGINE_CAMERA_H
