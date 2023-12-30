#include <iostream>
using namespace std;

int main(void){
    int n;
    long long totalCost = 0, totalLen = 0, min = 1000000000, cur_min = 1000000000;

    cin >> n;
    long long *len = new long long[n + 1];
    long long *price = new long long[n + 2];

    for(int i = 0; i < n - 1; i++){
        cin >> len[i];
        totalLen += len[i];
    }
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    for(int i = 0; i < n - 1; i++){
        if (min > price[i])
            min = price[i];
    }

    for(int i = 0; i < n; i++){
        if (price[i] == min){
            totalCost += price[i] * totalLen;
            break;
        }
        else{
            if (cur_min > price[i]){
                cur_min = price[i];
            }
            totalCost += cur_min * len[i];
                totalLen -= len[i];
        }
    }

    cout << totalCost;

    return (0);
}