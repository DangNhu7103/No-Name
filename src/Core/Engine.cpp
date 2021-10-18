#include "Engine.h"
#include <iostream>
#include "TextureManager.h"
#include "Vector.h"
#include "Transform.h"

Engine* Engine::s_Instance = nullptr;

Uint32 flags = SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER;

bool Engine::Init(){

    // Setting SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || SDL_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        SDL_Log("FAILDED TO INITIALIZE SDL: %s", SDL_GetError());
        return false;
    }

    // Setting window
    m_Window = SDL_CreateWindow(
                                "2D_Engine",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                0);
    if (m_Window == nullptr) {
        SDL_Log("FAILD TO CREATE WINDOW: %s", SDL_GetError());
        return false;
    }

    // Setting  renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr) {
        SDL_Log("FAILED TO CREATE RENDERER: %s", SDL_GetError());
        return false;
    }

    // Load texture
    //TextureManager::GetInstance()->Load("tree", "assets/tree.png");
    TextureManager::GetInstance()->Load("herochar", "assets/herochar.png");

    return m_IsRunning = true;
}

void Engine::Update(){

}

void Engine::Render(){

    SDL_RenderClear(m_Renderer);
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);

    //TextureManager::GetInstance()->Draw("tree", 50, 50, 347, 465);
    TextureManager::GetInstance()->Draw("herochar", 50, 50, 160, 160);

    SDL_RenderPresent(m_Renderer);
}

void Engine::Events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            Quit();
            break;
    }
}

void Engine::Clean(){
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit(){
    m_IsRunning = false;
}
