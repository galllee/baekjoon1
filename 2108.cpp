#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void    print_mode(int *arr, int n)
{
    int count[8001] = {0, };
    int max = 0, idx, countmode = 0;

    for (int i = 0; i < n; i++)
        count[arr[i] + 4000]++;
    //if (n == 1)
    //    idx = arr[0] + 4000;
    for (int i = arr[0] + 4000; i <= arr[n - 1] + 4000; i++)
    {
        if (max < count[i])
        {
            idx = i;
            max = count[i];
            countmode = 1;
        }
        else if (max == count[i])
        {
            countmode++;
            if (countmode == 2)
                idx = i;
        }
    }
    cout << idx - 4000 << "\n";
    return ;
}

int main(void)
{
    int n;
    double sum = 0;
    int *arr;

    cin >> n;
    arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if (round(sum / n) == -0)
        cout << "0\n";
    else
        cout << round(sum / n) << "\n";

    sort(arr, arr + n);
    cout << arr[n / 2] << "\n";
    print_mode(arr, n);
    cout << arr[n - 1] - arr[0];
}