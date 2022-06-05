//
// Created by leandro on 21/04/2020.
//

#ifndef INC_2D_RGP_EXAMPLE_SDL2_RENDERWINDOW_H
#define INC_2D_RGP_EXAMPLE_SDL2_RENDERWINDOW_H

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    void init();

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    const char *getTitle() const;

    void setTitle(const char *title);

    int width;
    int height;
    const char* title;
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity *p_entity);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif //INC_2D_RGP_EXAMPLE_SDL2_RENDERWINDOW_H
