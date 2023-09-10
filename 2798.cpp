#include <iostream>
#include <algorithm>
using namespace std;

int m, mx;

void black_jack(int *arr, int count, int sum, int idx){
    if (sum > m)
        return;
    if (count == 3){
        if (mx < sum)
            mx = sum;
        return;       
    }
    else{
        count++;
        for(int i = idx; i >= 0; i--){
            sum += arr[i];
            black_jack(arr, count, sum, i - 1);
            sum -= arr[i];
        }
    }
}

int main(void){
    int n, count = 0, sum = 0, i;
    int *arr;

    mx = 0;
    cin >> n >> m;
    arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    black_jack(arr, count, sum, i - 1);
    cout << mx;
    return (0);
}