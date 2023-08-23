#include <iostream>
using namespace std;

int main(void)
{
    int x, y, numofday = 0;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> x >> y;
    if (x == 1)
        numofday = y - 1;
    else
    {
        for(int i = x - 1; i >= 1; i--)
        {
            if (i == 2)
                numofday += 28;
            else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                numofday += 31;
            else
                numofday += 30;
        }
        numofday += y - 1;
    }
    
    cout << week[numofday % 7];
}