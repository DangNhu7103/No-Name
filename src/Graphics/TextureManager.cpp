#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string fileName){
    SDL_Surface* surface = IMG_Load(fileName.c_str());
    if (surface == nullptr) {
        SDL_Log("FAILED TO LOAD SURFACE: %s %s", fileName.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    if (texture == nullptr) {
        SDL_Log("FAILED TO CREATE TEXTURE FROM SURFACE: %s", SDL_GetError());
        return false;
    }

    m_TextureMap[id]  = texture;
    return true;
}

void TextureManager::Remove(std::string id){
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

// Clear everything in progam else it still in RAM when you close program
void TextureManager::Clean(){
    std::map<std::string, SDL_Texture*>::iterator it;
    for (it = m_TextureMap.begin(); it != m_TextureMap.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }
    m_TextureMap.clear();
    SDL_Log("TEXTURES ARE CLEAN !!!");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip){
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect desRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &desRect, 0, nullptr, flip);
}
