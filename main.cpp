//
// Created by 姜康 on 2019/3/1.
//
#include <iostream>
#include <fstream>
#include <core/SkRRect.h>
#include "renderer.h"


int main(int args, char *argv[]) {
    SkBitmap skBitmap = initBitmap(600, 300);
    SkCanvas skCanvas(skBitmap);


    drawText(&skCanvas);


    saveAsPng("shape.png", skBitmap);
}





