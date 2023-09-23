#include <iostream>
using namespace std;

int number[12];
int oper[4];
int n, mx = -1000000001, mn = 1000000001, i = 0;

void make_operation(int sum, int i){
    if (i == n){
        if (sum < mn)
            mn = sum;
        if (sum > mx)
            mx = sum;
    }
    else{
        for(int j = 0; j < 4; j++){
            if (oper[j]){
                oper[j]--;
                if (j == 0)
                    //sum += number[i]; 밑에처럼 매개변수로만 줘도 i == n까지 가면 어쨌든 매개변수인sum이 바뀌는거긴 하니까, 판별이 되겠지
                    make_operation(sum + number[i], i + 1);
                else if (j == 1)
                    make_operation(sum - number[i], i + 1);
                else if (j == 2)
                    make_operation(sum * number[i], i + 1);
                else if (j == 3)
                    make_operation(sum / number[i], i + 1);
                oper[j]++;
            }
        }
    }
}

int main(void){
    int sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> number[i];
    for(int i = 0; i < 4; i++)
        cin >> oper[i];
    make_operation(number[0], 1);
    cout << mx << "\n" << mn;
    return (0);
}