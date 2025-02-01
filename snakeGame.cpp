#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>


using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;

void setup();
void draw();
void input();
void logic();

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
    }
    draw();
}

void setup()
{
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw()
{
    system("cls"); // cleares the window;
    for (int i = 0; i < width; i++)
    {
        cout << "# ";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "# ";
            }
            else if (i == y && j == x)
            {
                cout << "O ";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
    {
        cout << "# ";
    }
    cout << endl;
    cout << "SCORE: " << score << endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = Left;
                break;
            case 'd':
                dir = Right;
                break;
            case 'w':
                dir = Up;
                break;
            case 's':
                dir = Down;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic()
{
    switch (dir)
    {
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Up:
            y--;
            break;
        case Down:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY)
    {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}