#include <iostream>
#include <map>
using namespace std;

map <string, bool> m;

int main(void)
{
    string a, b;
    int n, cnt = 0;

    cin >> n;
    m["ChongChong"] = 1;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a >> b;
        if ((m[a] == 1 && m[b] == 0) || (m[a] == 0 && m[b] == 1))
        {
            m[a] = 1;
            m[b] = 1;
            cnt++;
        }
    }
    cout << cnt + 1;
    return (0);
}