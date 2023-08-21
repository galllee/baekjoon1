#include <iostream>
using namespace std;

int main(void)
{
    int x, y, newx = 0, newy = 0, sum, newsum = 0;
    int revx[4] = {0, }, revy[4] = {0, }, revsum[4] = {0, };

    cin >> x >> y;
    for(int i = 0; i < 4; i++)
    {
        if (x == 0)
            revx[i] = -1;
        else
        {
            revx[i] = x % 10;
            x /= 10;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (y == 0)
            revy[i] = -1;
        else
        {
            revy[i] = y % 10;
            y /= 10;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (revx[i] == -1)
            break;
        newx = newx * 10 + revx[i];
    }
    for(int i = 0; i < 4; i++)
    {
        if (revy[i] == -1)
            break;
        newy = newy * 10 + revy[i];
    }
    sum = newx + newy;
    for(int i = 0; i < 4; i++)
    {
        if (sum == 0)
            revsum[i] = -1;
        else
        {
            revsum[i] = sum % 10;
            sum /= 10;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (revsum[i] == -1)
            break;
        newsum = newsum * 10 + revsum[i];
    }
    cout << newsum;
}