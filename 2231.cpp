#include <iostream>
using namespace std;

int main(void){
    int n, sum, num, answer = 0;

    cin >> n;
    for(int i = 1; i <= n; i++){
        sum = i;
        num = i;
        while (num != 0){
            sum += (num % 10);
            num /= 10;
        }
        if (sum == n){
            answer = i;
            break;
        }
    }
    cout << answer;
    return(0);
}