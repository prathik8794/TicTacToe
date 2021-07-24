#include <iostream>
#include <time.h>
using namespace std;
bool check(char a[][3])
{
    if ((a[0][0] == 'O') && (a[0][1] == 'O') && (a[0][2] == 'O'))
    {
        return 1;
    }
    else if ((a[1][0] == 'O') && (a[1][1] == 'O') && (a[1][2] == 'O'))
    {
        return 1;
    }
    else if ((a[2][0] == 'O') && (a[2][1] == 'O') && (a[2][2] == 'O'))
    {
        return 1;
    }
    else if ((a[0][0] == 'O') && (a[1][0] == 'O') && (a[2][0] == 'O'))
    {
        return 1;
    }
    else if ((a[0][1] == 'O') && (a[1][1] == 'O') && (a[2][1] == 'O'))
    {
        return 1;
    }
    else if ((a[0][2] == 'O') && (a[1][2] == 'O') && (a[2][2] == 'O'))
    {
        return 1;
    }
    else if ((a[0][0] == 'O') && (a[1][1] == 'O') && (a[2][2] == 'O'))
    {
        return 1;
    }
    else if ((a[0][2] == 'O') && (a[1][1] == 'O') && (a[2][0] == 'O'))
    {
        return 1;
    }
    return 0;
}
bool compcheck(char a[][3])
{
    if ((a[0][0] == 'X') && (a[0][1] == 'X') && (a[0][2] == 'X'))
    {
        return 1;
    }
    else if ((a[1][0] == 'X') && (a[1][1] == 'X') && (a[1][2] == 'X'))
    {
        return 1;
    }
    else if ((a[2][0] == 'X') && (a[2][1] == 'X') && (a[2][2] == 'X'))
    {
        return 1;
    }
    else if ((a[0][0] == 'X') && (a[1][0] == 'X') && (a[2][0] == 'X'))
    {
        return 1;
    }
    else if ((a[0][1] == 'X') && (a[1][1] == 'X') && (a[2][1] == 'X'))
    {
        return 1;
    }
    else if ((a[0][2] == 'X') && (a[1][2] == 'X') && (a[2][2] == 'X'))
    {
        return 1;
    }
    else if ((a[0][0] == 'X') && (a[1][1] == 'X') && (a[2][2] == 'X'))
    {
        return 1;
    }
    else if ((a[0][2] == 'X') && (a[1][1] == 'X') && (a[2][0] == 'X'))
    {
        return 1;
    }
    return 0;
}
void computer(char ch[][3])
{
    int count = 0;
    while (count != 1)
    {
        int num1 = rand() % 3;
        int num2 = rand() % 3;
        if (ch[num1][num2] != 'X' && ch[num1][num2] != 'O')
        {
            ch[num1][num2] = 'X';
            count++;
        }
    }
}

void human(char ch[][3], int x, int y)
{
    ch[x][y] = 'O';
}
void print(char ch[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ch[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}
int main()
{
    srand(time(0));
    char temp[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int num1, num2, x, y;
    /*
*1)first move by human
/*
*user='O'
*computer='X'
*/
    bool flag;
    cin >> flag;
    /*
*if flag is true implies you want to have first move
*/
    if (flag == true)
    {

        cin >> x >> y;
        /*1*/ human(temp, x, y); //1 -1
        print(temp);
        computer(temp); //2-1
        print(temp);
        cin >> x >> y;
        /*2*/ human(temp, x, y); //3 -2
        print(temp);
        computer(temp); //4-2
        print(temp);
        cin >> x >> y;
        /*3*/ human(temp, x, y); //5 -3
        print(temp);
        if (check(temp))
        {
            cout << "YOU HAVE WON" << endl;
        }
        else
        {
            computer(temp); //6-3
            print(temp);
            if (compcheck(temp))
            {
                cout << "YOU HAVE LOST" << endl;
            }
            else
            {
                cin >> x >> y;
                /*4*/ human(temp, x, y); //7-4
                if (check(temp))
                {
                    cout << "YOU HAVE WON" << endl;
                }
                else
                {
                    computer(temp); //8-4
                    print(temp);
                    if (compcheck(temp))
                    {
                        cout << "YOU HAVE LOST" << endl;
                    }
                    else
                    {
                        cin >> x >> y;
                        /*5*/ human(temp, x, y);
                        print(temp);
                        if (check(temp))
                        {
                            cout << "YOU HAVE WON" << endl;
                        }
                        else
                        {
                            cout << "DRAW" << endl;
                        }
                    }
                }
            }
        }
    }
    else{
        cout<<"You need to have the first move"<<endl;
    }
}
