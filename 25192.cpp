#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n, cnt = 0;
    map <string, int> m;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "ENTER")
            m.clear();
        else
            m[s]++;
        if (m[s] == 1)
            cnt++;
    }
    cout << cnt;
    return (0);
}