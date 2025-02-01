#include <iostream>
using namespace std;

bool output(void);
void structure(void);

string arr[3][3] = {{"1,1","1,2","1,3"},{"2,1","2,2","2,3"},{"3,1","3,2","3,3"}};

// switches between P1 & P2, takes the value from the user and assignes to the given position...
int main(void)
{
    int x,y;
    for (int i = 0; i < 9; i++)
    {
        structure();

        int x = 0, y = 0;
        if (i % 2 == 0)
        {
            do
            {
                cout << "P1 [ X ], please enter the x & y" << endl;
                cin >> x >> y;
            }
            while (arr[x-1][y-1] == " X " || arr[x-1][y-1] == " O " || x > 3 || x < 1 || y > 3 || y < 1);
            arr[x-1][y-1] = " X ";
            if (output() == true)
            {
                structure();
                cout << "P1 won the game";
                break;
            }
        }
        else
        {
            do
            {
                cout << "P2 [ O ], please enter the x & y" << endl;
                cin >> x >> y;
            }
            while (arr[x-1][y-1] == " X " || arr[x-1][y-1] == " O " || x > 3 || x < 1 || y > 3 || y < 1);
            arr[x-1][y-1] = " O ";
            if (output() == true)
            {
                structure();
                cout << "P2 won the game";
                break;
            }
        }       
    }
    if (output() != true)
    {
        structure();
        cout << "Tie";
    }
}

// Checks for all the winning conditions...
bool output(void)
{
    for (int i = 0; i < 3; i++)
    {
        if((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) || (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]))
        {
            return true;     
        }
        if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
        {
            return true;
        }
    }
}

// Create the tick tack tow structure...
void structure(void)
{
    for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << arr[k][j];
                if (j == 2)
                {
                    continue;
                }
                else
                {
                    cout << "|";
                }
            }
            cout << endl;
            if (k == 2)
            {
                continue;
            }
            else{
                for (int j = 0; j < 3; j++)
                {
                    cout << "----";
                }
            }
            cout << endl;
        }
        cout << endl;
}