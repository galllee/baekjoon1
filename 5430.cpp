#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int main() {
    int t, n, b=0,countr=0;
    bool error = false;
    string s, input, a="0";
    int arr[10001] = { 0 };
    cin >> t;
    for (int i = 0; i < t; i++) {
        deque <int> dq;
        cin >> s;
        cin >> n;
        cin >> input;
        b = 0; error = false;
        for (int k = 0; input[k] != '\0'; k++) {
            a = "0"; countr = 0;
            for (int j = b; input[j]!='\0'; j++) {
                if (input[j] == ']' || input[j] == ',') {
                    j++; b = j; break;
                }
                else if (input[j] - '0' >= 0 && input[j] - '0' <= 9) {
                    a += input[j];
                }
            }
            const char* p = a.c_str();
            if (atoi(p) == 0) {
                b = 0; break;
            }
            dq.push_back(atoi(p));
        }

        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == 'R') {
                countr++;
            }
            else if (s[j] == 'D') {
                if (dq.empty()) { cout << "error\n"; error = true; break; }
                else if (countr % 2 == 0) dq.pop_front();
                else if (countr % 2 != 0) dq.pop_back();
            }
        }
        
        if(!error) {
            cout << '[';
            while (!dq.empty()) {
                if (countr % 2 == 0) {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
                else {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())cout << ',';
                }
            }
            cout << "]\n";
        }
    }
}