#include <iostream>
using namespace std;

int main(void){
    int n, three = 0, five = 0, min, tmp, cnt = 0;

    cin >> n;
    tmp = n;
    min = n;
    while (tmp  - 5 >= 0){
            tmp -= 5;
            five++;
    }
    while (five >= 0){
        three = 0;
        tmp = n;
        cnt = 0;
        while (cnt < five){
            tmp -= 5;
            cnt++;
        }
        while (tmp - 3 >= 0){
            tmp -= 3;
            three++;
        }
        if (five + three < min && tmp == 0)
            min = five + three;
        five--;
        three--;
    }
    if (min == n)
        cout << -1;
    else cout << min;
    return (0);
}