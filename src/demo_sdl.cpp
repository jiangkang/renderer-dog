//
// Created by 姜康 on 2020-09-13.
//
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "demo_sdl.h"

using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 600;

SDL_Texture* LoadImg(const char *filename,SDL_Renderer *renderer){
    SDL_Surface *image = IMG_Load(filename);
    if (!image){
        cout << "加载图片失败：" << SDL_GetError() << endl;
        return nullptr;
    }

    // 如果使用硬件加速，则必须将Surface转换成Texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,image);
    SDL_FreeSurface(image);
    return texture;
}

void showImage() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "初始化失败" << endl;
        return;
    }
    SDL_Window *window = SDL_CreateWindow("Show Image",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "创建Window失败：" << SDL_GetError() << endl;
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cout << "创建Renderer失败：" << SDL_GetError() << endl;
        return;
    }

    // 如果使用硬件加速，则必须将Surface转换成Texture
    SDL_Texture *texture = LoadImg("/Volumes/T5/CppPractice/renderer-dog/res/demo.jpg",renderer);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Event windowEvent;
    while (true){
        if (SDL_PollEvent(&windowEvent)){
            if (windowEvent.type == SDL_QUIT){
                std::cout << "终止程序" << std::endl;
                break;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Hello World版本的SDL
void MinSDLExample() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "初始化失败" << std::endl;
    }
    SDL_Window *window = SDL_CreateWindow("Skia + SDL"
            ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED
            ,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr){
        std::cout<< "创建Window失败" << std::endl;
    }

    SDL_Event windowEvent;
    while (true){
        if (SDL_PollEvent(&windowEvent)){
            if (windowEvent.type == SDL_QUIT){
                std::cout << "终止程序" << std::endl;
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}

