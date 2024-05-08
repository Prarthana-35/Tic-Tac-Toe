#include <iostream>
using namespace std;
// ctrl+alt+n : run shortcut

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char char_token = 'x';
bool flag = false;
string n1 = "";
string n2 = "";

void playground()
{

    cout << "         |         |        \n";
    cout << "  " << space[0][0] << "         |" << space[0][1] << "         |" << space[0][2] << "  \n";
    cout << "_________|_________|________\n";
    cout << "         |         |        \n";
    cout << "  " << space[1][0] << "         |" << space[1][1] << "         |" << space[1][2] << "  \n";
    cout << "_________|_________|________\n";
    cout << "         |         |        \n";
    cout << "  " << space[2][0] << "         |" << space[2][1] << "         |" << space[2][2] << "  \n";
    cout << "         |         |        \n";
}

void elements()
{
    int digit;
    if (char_token == 'x')
    {
        cout << n1 << " Enter here: ";
        cin >> digit;
    }
    if (char_token == '0')
    {
        cout << n2 << " Enter here: ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }

    if (digit == 2)
    {
        row = 0;
        column = 1;
    }

    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid" << endl;
    }

    if (char_token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = 'x';
        char_token = '0';
    }
    else if (char_token == '0' && space[row][column] != '0' && space[row][column] != 'x')
    {
        space[row][column] = '0';
        char_token = 'x';
    }
    else
    {
        cout << "There is no empty space!" << endl;
        elements();
    }
    playground();
}
bool check()
{
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }

        if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    flag = true;
    return false;
}

int main()
{
    int space[3][3] = {{00, 01, 02}, {10, 11, 12}, {20, 21, 22}};
    cout << "\nEnter name of first player:  ";
    getline(cin, n1);
    cout << "\nEnter name of second player:  ";
    getline(cin, n2);
    cout << n1 << " is player1 & will play first \n";
    cout << n2 << " is player2 & will play second \n";
    while (!check())
    {
        playground();
        elements();
        check();
    }
    if (char_token == 'x' && flag == false)
    {
        cout << n2 << "WINS!\n"
             << endl;
    }
    else if (char_token == '0' && flag == false)
    {
        cout << n1 << "WINS!\n"
             << endl;
    }
    else
    {
        cout << "It's a DRAW!\n"
             << endl;
    }
    
}
