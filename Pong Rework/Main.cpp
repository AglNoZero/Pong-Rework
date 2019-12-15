#include "pre.h"
#include "Ball.h"
#include "Bonus.h"
#include "Control.h"

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WIDTH_DISPLAY, HEIGHT_DISPLAY), "SFML");

    Clock clock;
    const float FPS = 120.0f;    //The desired FPS. (The number of updates each second).
    bool redraw = true;           //Do I redraw everything on the screen?

    CPaddle *paddle = new CPaddle();
    CBall *ball = new CBall();
    CWall *wall = new CWall();
    CControl *Control = new CControl();

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
        }

        //Wait until 1/120th of a second has passed, then update everything.
        if (clock.getElapsedTime().asSeconds() >= 1.0f / (FPS)) {
            redraw = true; //We're ready to redraw everything

            // điều khiển bóng, paddle, các va chạm cơ bản 
            Control->control(*paddle, *ball, *wall);
            ball->logic(*paddle, *wall);
            paddle->ifCollisionBonus(*wall);

            // xử lý thắng thua 
            // if (wall->getWall().size() == 0 || paddle->getLife() == 0) {
            if (false) {
                window.clear(Color::Black);
                wall->drawWall(window);
                ball->drawBall(ball->getBall().getPosition(), window);
                paddle->draw(window, *wall);
                window.display();

                Time t = seconds(1.0);
                sleep(t);
                window.close();

                RenderWindow win(VideoMode(WIDTH_DISPLAY, HEIGHT_DISPLAY), "SFML");
                while (win.isOpen()) {
                    while (win.pollEvent(e)) {
                        if (e.type == Event::Closed) {
                            win.close();
                        }
                    }

                    Font font;
                    font.loadFromFile("Rainbow Colors - TTF.ttf");
                    Text text;
                    text.setFont(font);
                    text.setPosition(Vector2f(200, 500));
                    text.setColor(Color::Green);
                    text.setCharacterSize(150);

                    if (wall->getWall().size() == 0) {
                        text.setString("You Won :)");
                    }
                    else {
                        text.setString("You loser :( ");
                    }

                    win.clear();
                    win.draw(text);
                    win.display();
                }
            }
            clock.restart();
        }
        // Sleep until next 1/120th of a second comes around 
        else { 
            Time sleepTime = seconds((1.0f / FPS) - clock.getElapsedTime().asSeconds());
            sleep(sleepTime);
        }

        if (redraw) {
            window.clear(Color::Black);
            wall->drawWall(window);
            ball->drawBall(ball->getBall().getPosition(), window);
            paddle->draw(window, *wall);
            window.display();
            redraw = false;
        }
    }

    return 0;
}
