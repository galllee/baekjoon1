#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    int arr[500001];
    map <int, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp[num]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        cout << mp[arr[i]];
        if (i != m)
            cout << " ";
    }
    return (0);
}