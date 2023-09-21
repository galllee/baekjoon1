#include <iostream>
using namespace std;

int main(void){
    int n, tmp, count = 0, num = 0, cut = 0;

    cin >> n;
    for(int i = 666; num != n; i++){
        cut = 0;
        count = 0;
        tmp = i;
        for(; tmp != 0; tmp /= 10){
            if (tmp % 10 == 6)
                count++;
            else if (count > 0 && count < 3 && tmp % 10 != 6)
                count = 0;
            if (count >= 3)
            {
                num++;
                if (num == n){
                    cout << i;
                    break;
                }
                else
                    break;
            }
        }
    }
    return (0);
}