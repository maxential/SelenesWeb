//
// Created by max on 2/20/2025.
//

#include "Window.h"

Window::Window(const char* title, int width, int height)
{
    window = SDL_CreateWindow(title, width, height, 0);
    if (!window) {
        SDL_Log("failed to create window with error %s", SDL_GetError());
    }
    window_size.x = width;
    window_size.y = height;
}

Window::~Window()
{
    if (window) {
        SDL_DestroyWindow(window);
    }
}

glm::ivec2 Window::getWindowSize()
{
    return window_size;
}