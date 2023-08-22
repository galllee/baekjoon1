#include <iostream>
using namespace std;

int arr[128][128] = {0, };
int white = 0, blue = 0;

int is_it_paper(int x_start, int x_end, int y_start, int y_end)
{
    for(int i = x_start; i <= x_end; i++)
    {
        for(int j = y_start; j <= y_end; j++)
        {
            if (arr[x_start][y_start] != arr[i][j])
            {
                return (-1);
            }
        }
    }
    return (arr[x_start][y_start]);
}

void count(int x_start, int x_end, int y_start, int y_end)
{
    switch(is_it_paper(x_start, x_end, y_start, y_end))
    {
        case -1:
            count(x_start, x_start + (x_end - x_start) / 2, y_start, y_start + (y_end - y_start) / 2);
            count(x_start, x_start + (x_end - x_start) / 2, y_start + (y_end - y_start) / 2 + 1, y_end);
            count(x_start + (x_end - x_start) / 2 + 1, x_end, y_start, y_start + (y_end - y_start) / 2);
            count(x_start + (x_end - x_start) / 2 + 1, x_end, y_start + (y_end - y_start) / 2 + 1, y_end);
            return ;
        case 0:
            white++;
            return ;
        case 1:
            blue++;
            return ;
    }
}

int main(void)
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    count(0, n - 1, 0, n - 1);

    cout << white << "\n" << blue;
}