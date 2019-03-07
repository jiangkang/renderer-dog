//
// Created by 姜康 on 2019/3/6.
//

#include <iostream>
#include <string>
#include <core/SkImageEncoder.h>
#include <core/SkFontMgr.h>
#include <core/SkFont.h>
#include <core/SkTextBlob.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <core/SkRRect.h>
#include <core/SkImage.h>
#include "renderer.h"

void saveAsPng(const char *filename, SkBitmap bitmap) {
    sk_sp<SkData> encodedData = SkEncodeBitmap(bitmap, SkEncodedImageFormat::kPNG, 100);
    FILE *pFile = fopen(filename, "wb+");
    if (!pFile) {
        std::cout << "文件打开失败！" << std::endl;
    } else {
        fwrite(encodedData->data(), encodedData->size(), 1, pFile);
        std::cout << "写入文件成功！" << std::endl;
    }
}

SkBitmap initBitmap(int width, int height) {
    SkBitmap skBitmap;
    skBitmap.setInfo(SkImageInfo::Make(width, height, kBGRA_8888_SkColorType, kOpaque_SkAlphaType));
    skBitmap.allocPixels(); //转换成像素填充
    return skBitmap;
}

void draw(SkCanvas *canvas) {
    std::cerr << "请调用具体的drawXXX方法!" << std::endl;
}

void drawShape(SkCanvas *canvas) {
    //绘制底色
    canvas->drawColor(SK_ColorWHITE);

    //设置Paint
    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setAntiAlias(true);
    paint.setStrokeWidth(4);
    paint.setColor(0xff003366); //这里是ARGB格式，一定得注意带上透明度

    //矩形
    SkRect rect = SkRect::MakeXYWH(10, 10, 100, 160);
    canvas->drawRect(rect, paint);

    //圆角矩形实现的椭圆
    SkRRect oval;
    oval.setOval(rect); //以之前的矩形为基准
    oval.offset(40, 80);
    paint.setColor(0xffDB4437);
    canvas->drawRRect(oval, paint);

    paint.setColor(0xffF4B400);
    paint.setStyle(SkPaint::kFill_Style);
    rect.offset(160, 80);
    canvas->drawRoundRect(rect, 10, 10, paint);

    //圆
    paint.setColor(0xff0F9D58);
    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawCircle(150, 150, 60, paint);
}

void drawText(SkCanvas *canvas) {

    canvas->drawColor(SK_ColorWHITE);

    const char *fontFamily = nullptr;
    SkFontStyle fontStyle;
    sk_sp<SkFontMgr> fontManager = SkFontMgr::RefDefault();
    sk_sp<SkTypeface> typeface = fontManager->legacyMakeTypeface(fontFamily, fontStyle);

    SkFont font1(typeface, 64.0f);
    SkFont font2(typeface, 32.0f, 1.5f, 0.0f);
    font1.setEdging(SkFont::Edging::kAntiAlias);
    font2.setEdging(SkFont::Edging::kAntiAlias);

    //这里可能会失败，因为有不支持的语言，比如中文
    sk_sp<SkTextBlob> blob1 = SkTextBlob::MakeFromString("Jiang Kang", font1);
    sk_sp<SkTextBlob> blob2 = SkTextBlob::MakeFromString("Jiang Kang", font2);
    sk_sp<SkTextBlob> blob3 = SkTextBlob::MakeFromString("Skia", font2);

    SkPaint paint1, paint2, paint3;

    paint1.setAntiAlias(true);
    paint1.setColor(SkColorSetARGB(0xFF, 0x42, 0x85, 0xF4));

    paint2.setAntiAlias(true);
    paint2.setColor(SkColorSetARGB(0xFF, 0xDB, 0x44, 0x37));
    paint2.setStyle(SkPaint::kStroke_Style);
    paint2.setStrokeWidth(3.0f);

    paint3.setAntiAlias(true);
    paint3.setColor(SkColorSetARGB(0xFF, 0x0F, 0x9D, 0x58));

    canvas->clear(SK_ColorWHITE);
    canvas->drawTextBlob(blob1.get(), 20.0f, 64.0f, paint1);
    canvas->drawTextBlob(blob2.get(), 20.0f, 144.0f, paint2);
    canvas->drawTextBlob(blob3.get(), 20.0f, 224.0f, paint3);

}

//通过SDL_Surface创建SDL_Rect
SDL_Rect create_rect(SDL_Surface *surface) {
    //创建SDL_Rect对象
    SDL_Rect src = {0, 0, surface->w, surface->h};
    //返回SDL_Rect对象
    return src;
}

void drawBySDL() {
    //声明窗口
    SDL_Window *window;
    //声明绘图表面
    SDL_Surface *surface;
    //声明渲染器
    SDL_Renderer *renderer;
    //声明纹理
    SDL_Texture *texture;
    //声明Bitmap
    SkBitmap skBitmap = initBitmap(100, 100);
    //声明RGBA结构体
    RGBA rgba;
    //声明矩形
    SDL_Rect rect;
    //声明窗口的宽高
    int width = 800;
    int height = 480;
    //初始化SDL为视频显示
    SDL_Init(SDL_INIT_VIDEO);
    //创建窗口
    window = SDL_CreateWindow("Hello Skia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    if (window == NULL) {
        return;
    }

    SkCanvas canvas(skBitmap);
    draw(&canvas);

    //通过Bitmap的像素数据创建表面
    surface = SDL_CreateRGBSurfaceFrom(skBitmap.getPixels(), width, height, 32, width * 4, rgba.rmask, rgba.gmask,
                                       rgba.bmask, rgba.amask);
    //通过SDL_Surface创建矩形
    rect = create_rect(surface);
    //创建渲染器
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //清理渲染器
    SDL_RenderClear(renderer);
    //创建纹理
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    //辅助纹理到渲染器
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    //显示到窗口
    SDL_RenderPresent(renderer);
    //延时5秒钟
//    SDL_Delay(5000);

    std::cout << "输入任意字符然后回车终止进程: ";

    char *cmd;
    std::cin >> cmd;
    //释放表面
    SDL_FreeSurface(surface);
    //释放纹理
    SDL_DestroyTexture(texture);
    //释放渲染器
    SDL_DestroyRenderer(renderer);
    //释放窗口
    SDL_DestroyWindow(window);
    //结束SDL
    SDL_Quit();
}

void testSkia() {
    SkBitmap skBitmap = initBitmap(100, 100);
    SkCanvas canvas(skBitmap);
    draw(&canvas);
    saveAsPng("file0.png", skBitmap);
}

