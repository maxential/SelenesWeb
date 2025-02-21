//
// Created by max on 2/20/2025.
//

#ifndef WINDOW_H
#define WINDOW_H


#include "SDL3/SDL.h"
#include "common/math.h"

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    SDL_Window* getSDLWindow() const { return window; }
    glm::ivec2 getWindowSize();

private:
    SDL_Window* window;
    glm::ivec2 window_size;
};





#endif //WINDOW_H
