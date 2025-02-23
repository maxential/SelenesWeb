//
// Created by max on 2/21/2025.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H



#include <map>
#include <string>
#include <memory>
#include "SDL3/SDL.h"

class TextureManager
{
public:
    TextureManager(SDL_Renderer* _renderer);
    ~TextureManager();
    void CleanupTextures();
    void AddTexture(const std::string& name, SDL_Texture* texture);
    SDL_Texture* GetTexture(const std::string& name);
    bool InitializeTextures();
private:
    SDL_Renderer* renderer;
    mutable std::mutex textureMapMutex;
    std::map<std::string, SDL_Texture*> textures;
};


#endif //TEXTUREMANAGER_H
