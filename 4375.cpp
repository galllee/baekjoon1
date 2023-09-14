//4375
#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    long long result;
    
    while (cin >> n){
        result = 1;
        for(int i = 0; ; i++){
            if (result % n == 0){
                cout << i + 1 << "\n";
                break;
            }
            result = (result * 10 + 1) % n;
        }
    }
    return (0);
}