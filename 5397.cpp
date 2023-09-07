#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    stack <char> fir;
    stack <char> sec;
    char print[1000001];
    string str;
    int n, j;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(j = 0; str[j]; j++){
            if (str[j] == '<'){
                if (!fir.empty()){
                    sec.push(fir.top());
                    fir.pop();
                }
            }
            else if (str[j] == '>'){
                if (!sec.empty()){
                    fir.push(sec.top());
                    sec.pop();
                }
            }
            else if (str[j] == '-'){
                if (!fir.empty())
                    fir.pop();
            }
            else{
                fir.push(str[j]);
            }
        }
        while (!sec.empty()){
            fir.push(sec.top());
            sec.pop();
        }
        for(j = 0; !fir.empty(); j++){
            print[j] = fir.top();
            fir.pop();
        }
        for(j = j - 1; j >= 0; j--){
            cout << print[j];
        }
        cout << "\n";
        while (!sec.empty()){
            sec.pop();
        }
    }
}