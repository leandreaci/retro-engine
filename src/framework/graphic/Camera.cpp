//
// Created by Le on 16/06/22.
//

// TODO get screen width and weight from config

#include "Camera.h"
#include <framework/Stage.h>
#include <iostream>


void Camera::setCurrentFrame() {
    this->cont++;
    this->stage->entity->setCurrentFrame(this->cont, 0, 1280, 720);
}

void Camera::setStage(Stage *stage) {
    this->stage = stage;
}

void Camera::setPlayer(PlayerController *playerController) {
    this->player = playerController;
}

void Camera::moveForward() {
}

void Camera::update() {
//    this->player->getX();

    if (this->player->getX() > 500)
    {
        this->stage->entity->setCurrentFrameX( this->stage->entity->getX() + this->player->getX());
    }
//    std::cout << this->player->getX() << std::endl;
//    this->moveForward();
}


