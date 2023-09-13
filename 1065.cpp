#include <iostream>
#include <cstdlib>
using namespace std;

void itoa(int n, char *arr){
    for(int i = 2; n > 0; i--){
        *(arr + i) = n % 10 + '0';
        n /= 10;
    }
}

int main(void){
    int n, result;
    char arr[3];

    cin >> n;
    if (n < 100)
        result = n;
    else if (n >= 100 && n < 111)
        result = 99;
    else if (n < 1000){
        result = 99;
        for (int i = 111; i <= n; i++){
            itoa(i, arr);
            if (arr[1] - arr[0] == arr[2] - arr[1])
                result++;
        }
    }
    else
        result = 144;
    cout << result;
    return (0);
}