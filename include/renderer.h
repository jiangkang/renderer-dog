//
// Created by 姜康 on 2019/3/6.
//

#ifndef KRENDERER_RENDERER_H
#define KRENDERER_RENDERER_H

#include "core/SkBitmap.h"
#include "core/SkCanvas.h"
#include "SDL2/SDL_quit.h"

//创建RGBA结构体
struct RGBA {
    //设置Red
    Uint32 rmask = 0x00ff0000;
    //设置Green
    Uint32 gmask = 0x0000ff00;
    //设置Blue
    Uint32 bmask = 0x000000ff;
    //设置Alpha
    Uint32 amask = 0xff000000;
};

void saveAsPng(const char *filename, SkBitmap bitmap);

SkBitmap initBitmap(int width, int height);

void draw(SkCanvas *canvas);

void drawShape(SkCanvas *canvas);

void drawText(SkCanvas *canvas);

void drawBySDL();

void testSkia();

#endif //KRENDERER_RENDERER_H
