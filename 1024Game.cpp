#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#include <ctime>
using namespace std;
#define UP 72//defining arrow keys 
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 10
int board[4][4] = { 0 };
static int steps;
static int score;
int HiScore = 0;
int winning_point = 1024;

void add_when_same()
{
    int x, y;
    int count = 0;
    while (1) {
        if (count == 1)break;
        x = rand() % 4;
        y = rand() % 4;
        if (board[x][y] == 0)
        {
            int r = rand() % 10;
            int temp;
            if (r == 0)
                temp = 4;
            else
                temp = 2;
            board[x][y] = temp;
            count = 1;
        }
    }
}

int end_of_game()
{
    int the_game_is_over = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0 || board[i][j + 1] == 0 || board[i][j] == board[i][j + 1])
            {
                the_game_is_over = 0;
                break;
            }
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == 0 || board[i + 1][j] == 0 || board[i][j] == board[i + 1][j])
            {
                the_game_is_over = 0;
                break;
            }
        }
    }
    return the_game_is_over;
}
void board_display()
{
    int x1, x2, x3, x4;

    while (1)
    {
        x1 = rand() % 4;
        x2 = rand() % 4;
        x3 = rand() % 4;
        x4 = rand() % 4;
        if (x1 == x3 && x2 == x4)
        {
            continue;
        }
        else
            break;
    }

    if (steps == 0)
    {

        cout << "_______1024  GAME______" << endl;
        cout << "Use arrow keys to move and X to quit the game" << endl;

        for (int i = 0; i < 4; i++) {

            cout << "|                       |" << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (i == x1 && j == x2)
                {
                    board[i][j] = 2;
                    cout << "  " << 2 << "  ";
                }
                else if (i == x3 && j == x4)
                {
                    int r = rand() % 10;
                    int temp;
                    if (r == 0)
                        temp = 4;
                    else
                        temp = 2;
                    board[i][j] = temp;
                    cout << "  " << temp << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << "|                       |" << endl;
    }
    else
    {
        system("cls");
        for (int i = 0; i < 4; i++) {

            cout << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (board[i][j] != 0) {
                    if (board[i][j] == 1024 || board[i][j] == 2048)
                        cout << " " << board[i][j];
                    if (board[i][j] == 128 || board[i][j] == 256 || board[i][j] == 512)
                        cout << " " << board[i][j] << " ";
                    if (board[i][j] == 16 || board[i][j] == 32 || board[i][j] == 64)
                        cout << "  " << board[i][j] << " ";
                    if (board[i][j] == 2 || board[i][j] == 4 || board[i][j] == 8)
                        cout << "  " << board[i][j] << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << endl;

    }

}

void leftmove()
{
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        int n = 0;
        int x = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[i][j] && n != 0)
            {
                board[i][x] = 2 * n;
                board[i][j] = 0;
                score += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j] != 0)
            {
                n = board[i][j];
                x = j;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (board[i][k] == 0 && board[i][k + 1] != 0)
                {
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    board[i][k + 1] = board[i][k] ^ board[i][k + 1];
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    flag++;
                }
            }
        }
    }
    if (flag != 0)
    {
        add_when_same();
        steps++;
    }
    board_display();
}
void rightmove()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int n = 0;
        int x = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[i][j] && n != 0)
            {
                board[i][x] = 2 * n;
                board[i][j] = 0;
                score += 2 * n;
                n = 0;
                count++;
                continue;
            }
            if (board[i][j] != 0)
            {
                n = board[i][j];
                x = j;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 3; k > 0; k--)
            {
                if (board[i][k] == 0 && board[i][k - 1] != 0)
                {
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    board[i][k - 1] = board[i][k] ^ board[i][k - 1];
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    count++;
                }
            }
        }
    }
    if (count != 0)
    {
        add_when_same();
        steps++;
    }
    board_display();
}
void up_move()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int n = 0;
        int x = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[j][i] && n != 0)
            {
                board[x][i] = 2 * n;
                board[j][i] = 0;
                score += 2 * n;
                n = 0;
                count++;
                continue;
            }
            if (board[j][i] != 0)
            {
                n = board[j][i];
                x = j;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (board[k][i] == 0 && board[k + 1][i] != 0)
                {
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    board[k + 1][i] = board[k][i] ^ board[k + 1][i];
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    count++;
                }
            }
        }
    }
    if (count != 0)
    {
        add_when_same();
        steps++;
    }
    board_display();
}
void down_move()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int n = 0;
        int x = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[j][i] && n != 0)
            {
                board[x][i] = 2 * n;
                board[j][i] = 0;
                score += 2 * n;
                n = 0;
                count++;
                continue;
            }
            if (board[j][i] != 0)
            {
                n = board[j][i];
                x = j;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 3; k > 0; k--)
            {
                if (board[k][i] == 0 && board[k - 1][i] != 0) {
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    board[k - 1][i] = board[k][i] ^ board[k - 1][i];
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    count++;
                }
            }
        }
    }
    if (count != 0)
    {
        add_when_same();
        steps++;
    }
    board_display();
}
int main() {

    char input;//to get characters

    cout << "1024 GAME BY MUHAMMAD AQIB KALEEM __HAMMAD TAUQIR__UMER SHAFIQ\n";
    cout << "Press any arrow key to start game";
    while (1)//infinite loop to print game board again and again
    {
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == winning_point)
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            cout << steps << " steps" << endl;
            cout << "!!!CONGRATULATIONS YOU WON THE GAME!!!" << endl;

        }
        if (end_of_game())
        {
            cout << "~~~GAME OVER~~~" << endl;
            if (HiScore < score)
                HiScore = score;
            cout << "Your Highest Score is : " << HiScore << endl;


        }
        // display();
        input = _getch();

        if (input == UP) {
            up_move();
        }
        else if (input == DOWN)
        {
            down_move();
        }
        else if (input == RIGHT) {
            rightmove();
        }
        else if (input == LEFT) {
            leftmove();

        }
        else if (input == 'x' || input == 'X')
            exit(1);
        else {
            cout << "\nInvalid input\n";
        }

        cout << " No of steps made: " << steps << endl;
        cout << "Your score is: " << score << endl;
    }
    system("pause");
    return 0;
}

