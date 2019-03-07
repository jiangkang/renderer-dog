
cmake_minimum_required(VERSION 3.10)

project(renderer-go)

# 这里需要换成你自己的skia项目路径
set(SKIA /Users/jiangkang/OpenProjects/skia)


include_directories(
        ${SKIA}/include
        ${SKIA}/include/android
        ${SKIA}/include/atlastext
        ${SKIA}/include/c
        ${SKIA}/include/codec
        ${SKIA}/include/config
        ${SKIA}/include/core
        ${SKIA}/include/effects
        ${SKIA}/include/encode
        ${SKIA}/include/gpu
        ${SKIA}/include/gpu/gl
        ${SKIA}/include/gpu/mock
        ${SKIA}/include/gpu/mtl
        ${SKIA}/include/gpu/vk
        ${SKIA}/include/pathops
        ${SKIA}/include/ports
        ${SKIA}/include/private
        ${SKIA}/include/svg
        ${SKIA}/include/utils
        ${SKIA}/include/utils/mac
        ${SKIA}/include/views
        /usr/local/Cellar/sdl2/2.0.9/include/
        include
)

# 这个地方前后参数很容易写错
aux_source_directory(src SOURCE_DIR)

add_definitions(-std=c++11)

find_library(SDL_LIB SDL2 SDL2main /usr/local/Cellar/sdl2/2.0.9/lib)

find_library(LIB_SKIA skia lib)

link_libraries(
        ${LIB_SKIA}
        ${SDL_LIB}
)

add_executable(renderer-go main.cpp ${SOURCE_DIR})
