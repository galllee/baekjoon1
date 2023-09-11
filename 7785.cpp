#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <string, string> m;

bool rev(string s1, string s2){
    return (s1 > s2);
}

int main(void){
    map <string, string>::iterator iter;
    int n, count = 0;
    string arr[1000001];
    string name, log;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> log;
        m[name] = log;
    }
    for (iter = m.begin(); iter != m.end(); iter++){
        if (iter->second == "enter"){
            arr[count] = iter->first;
            count++;
        }
    }
    sort(arr, arr + count, rev);
    for(int i = 0; i < count; i++){
        cout << arr[i] << "\n";
    }
    return (0);
}