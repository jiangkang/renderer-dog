//
// Created by 姜康 on 2019/3/1.
//
#include <iostream>
#include <fstream>
#include "core/SkRRect.h"
#include "renderer.h"
#include "demo_sdl.h"


int main(int args, char *argv[]) {
    // SkBitmap bitmap;
    // bitmap.setInfo(SkImageInfo::Make(120, 120, kRGBA_8888_SkColorType, kOpaque_SkAlphaType));
    // bitmap.allocPixels();
    // SkCanvas canvas(bitmap);
    // canvas.drawColor(SK_ColorWHITE);
    // SkPaint paint;
    // paint.setColor(SK_ColorRED);
    // canvas.drawLine(0.0f, 0.0f, bitmap.width(), bitmap.height(), paint);
    // canvas.drawLine(bitmap.width(), 0.0f, 0, bitmap.height(), paint);

    // SkBitmap bmp;
    // saveAsPng("line.png", bitmap);
//    MinSDLExample();
//    showImage();
    drawBySDL();
    return 0;
}





