#ifndef PRE_H_
#define PRE_H_

#include "iostream"
using namespace std;

#include "SFML/Graphics.hpp"
using namespace sf;

#include "stdlib.h"

#include "vector"

#define HEIGHT_DISPLAY 1400/2
#define WIDTH_DISPLAY 1000/2

#define SIZE_PADDLE Vector2f(200/2, 20/2)
#define SPEED_PADDLE 6.0f
#define BEGINNING_POS_PADDLE Vector2f(WIDTH_DISPLAY/2 - SIZE_PADDLE.x/2, HEIGHT_DISPLAY - SIZE_PADDLE.y)
#define BEGINNING_POS_TEXT Vector2f(500/2 - 133/2, 500/2)

#define SIZE_BRICK Vector2f(100/2, 50/2)

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

#define SIZE_BALL Vector2f(20/2, 20/2)
#define SPEED_BALL_X 6.0f
#define SPEED_BALL_Y 6.0f
#define BEGINNING_POS_BALL Vector2f(500/2, 500/2)

#define SIZE_BONUS Vector2f(50/2, 50/2)
#define X_Y_ORIGIN_BONUS Vector2f(25/2, 25/2)
/*
        * tăng kích thước bóng
        * xổ ra 1 đống bóng (khác màu bóng chính), có thể tung hứng nhưg k bị mất mạng 
        * bắn
        * bắn ra tia sét :) để hủy 1 số lượng bóng nhất định
*/

#endif // !PRE_H_