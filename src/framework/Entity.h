//
// Created by leandro on 21/04/2020.
//

#ifndef INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H
#define INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H

#include <SDL.h>
#include <SDL_image.h>


class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    void setX(float axiosX);
    void setY(float axiosY);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(int x, int y, int w, int h);
    void moveFrame(int frame);
    bool flipHorizontalVertical();
    bool flipHorizontal();
    bool flipVertical();
    void flipHorizontalVertical(bool val);
    void flipHorizontal(bool val);
    void flipVertical(bool val);
    void setCurrentFrameX(int x);
    void setCurrentFrameY(int y);

protected:
    bool flipEntityHorizontal = false;
public:
    bool isFlipEntityHorizontal() const;

    bool isFlipEntityVertical() const;

protected:
    bool flipEntityVertical = false;
    float x, y;
    SDL_Rect currentFrame{};
    SDL_Texture* texture;



};

#endif //INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H
