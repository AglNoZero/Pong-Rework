#ifndef PRE_H_
#define PRE_H_
#define SFML_NO_DEPRECATED_WARNINGS
#include "iostream"
using namespace std;

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;

#include "stdlib.h"

#include "vector"

#include "fstream"

// #define HEIGHT_DISPLAY 1400
// #define WIDTH_DISPLAY 1000
#define HEIGHT_DISPLAY 600
#define WIDTH_DISPLAY 900

#define SIZE_PADDLE Vector2f(200, 10)
#define SPEED_PADDLE 8.0f
#define BEGINNING_POS_PADDLE Vector2f(WIDTH_DISPLAY/2 - SIZE_PADDLE.x/2, HEIGHT_DISPLAY - SIZE_PADDLE.y - 40)
#define BEGINNING_POS_TEXT Vector2f(300, 450)

#define SIZE_BRICK Vector2f(90, 45)

/*
        * 3 - Right Up
        * 4 - Right down
        * 5 - Left Up
        * 6 - Left down
        * 
        *      5 left-up _______________________ right-up 3
        *               |                       |
        *               |                       |
        *               |                       |
        *               |                       |
        *               |_______________________|
        *      6 left-down                       right-down 4
        */

#define LEFT_UP 5
#define LEFT_DOWN 6
#define RIGHT_UP 3
#define RIGHT_DOWN 4
#define UP 1
#define DOWN 2

#define SIZE_BALL Vector2f(10, 10)
#define SPEED_BALL_X 4.0f
#define SPEED_BALL_Y 4.0f
#define BEGINNING_POS_BALL Vector2f(450, 300)

#define SIZE_BONUS Vector2f(30, 30)
#define X_Y_ORIGIN_BONUS Vector2f(10, 10)
#define SPEED_BONUS Vector2f(0, 4)
#define TYPE0 0 // tăng kích cỡ bóng cho đến lúc mất 1 mạng 
#define TYPE1 1 // thu nhỏ paddle cho đến khi chết :) 
#define TYPE2 2 // đóng băng đến khi mất cmn 1 mạng :) 
#define TYPE3 3 // tăng tốc độ bóng lên gấp đôi 
#define TYPE4 4 // xổ ra 1 đống bóng :)

#define SPEED_ROCKET Vector2f(0, -2);


#endif // !PRE_H_