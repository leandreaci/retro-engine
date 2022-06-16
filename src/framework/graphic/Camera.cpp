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
    Entity* stageEntity = this->stage->entity;
    stageEntity->setCurrentFrameX(( this->player->getX() + SCREEN_WIDTH / 2 ) - SCREEN_WIDTH / 2);
}

void Camera::update() {
    int playerX = this->player->getX();
    Entity* playerEntity = this->player->entity;

    this->moveForward();

    if( playerX < 0 )
    {
        playerEntity->setCurrentFrameX(0);
    }

}


