#include <iostream>
using namespace std;

int main(void){
    int n, m, min = 64, count = 0;
    bool rev = 0;
    char **arr;
    string str;

    cin >> n >> m;
    arr = new char *[n];
    for(int i = 0; i < n; i++)
        arr[i] = new char[m];
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j];
        }
    }
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8 || rev; j++){
            count = 0;
            if (rev){
                count++;
                j--;
                if (arr[i][j] == 'W')
                    arr[i][j] = 'B';
                else
                    arr[i][j] = 'W';
            }
            for(int a = 0; a < 8; a++){
                for(int b = 0; b < 8; b++){
                    if (arr[i][j] == 'W'){
                        if (a % 2 == 0 && b % 2 != 0 && arr[i + a][j + b] != 'B')
                            count++;
                        else if (a % 2 == 0 && b % 2 == 0 && arr[i + a][j + b] != 'W')
                            count++;
                        else if (a % 2 != 0 && b % 2 == 0 && arr[i + a][j + b] != 'B')
                            count++;
                        else if (a % 2 != 0 && b % 2 != 0 && arr[i + a][j + b] != 'W')
                            count++;
                    }
                    else if (arr[i][j] == 'B'){
                        if (a % 2 == 0 && b % 2 != 0 && arr[i + a][j + b] != 'W')
                            count++;
                        else if (a % 2 == 0 && b % 2 == 0 && arr[i + a][j + b] != 'B')
                            count++;
                        else if (a % 2 != 0 && b % 2 == 0 && arr[i + a][j + b] != 'W')
                            count++;
                        else if (a % 2 != 0 && b % 2 != 0 && arr[i + a][j + b] != 'B')
                            count++;
                    }
                }
            }
            if (rev)
                rev = 0;
            else
                rev = 1;
            if (count < min)
                min = count;
        }
    }
    cout << min;
    return (0);
}