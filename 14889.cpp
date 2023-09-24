#include <iostream>
#include <algorithm>
using namespace std;

int A[11] = {0, }, B[11] = {0, };
int input[21][21];
int n, mn = 101;

int sum_of_power(int *arr){
    int sum = 0;

    for(int i = 0; i < n / 2; i++){
        for(int j = i + 1; j < n / 2; j++){
            sum += input[arr[i] - 1][arr[j] - 1];
            sum += input[arr[j] - 1][arr[i] - 1];
        }
    }
    return (sum);
}
void make_team(int len, int idx){
    int value;
    if (len == n / 2){
        for(int i = 0; i < n / 2; i++){
            for(int j = 1; j <= n; j++){
                if (find(begin(A), end(A), j) == end(A) && find(begin(B), end(B), j) == end(B))
                {
                    B[i] = j;
                    break;
                }
            }
        }
        value = abs(sum_of_power(A) - sum_of_power(B));
        if (value < mn)
            mn = value;
    }
    else{
        for(int i = idx; i <= n; i++){
            if (!A[len]){
                A[len] = i;
                make_team(len + 1, i + 1);
                A[len] = 0;
                for(int j = 0; j < n / 2; j++)
                    B[j] = 0;
            }
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> input[i][j];
    }
    make_team(0, 1);
    cout << mn;
    return(0);
}