#include <iostream>
#include <map>
using namespace std;

map <int, string> mp;
map <string, int> mp2;

int is_it_int(string quiz){
    int num = 0;
    for(int i = 0; quiz[i]; i++){
        if (quiz[i] >= '0' && quiz[i] <= '9'){
            num = num * 10 + quiz[i] - '0';
        }
        else
            return (0);
    }
    return (num);
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string s, quiz;
    int n, m, flag;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        mp[i + 1] = s;
        mp2[s] = i + 1;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> quiz;
        flag = is_it_int(quiz);
        if (flag){
            cout << mp[flag] << "\n";
        }
        else
            cout << mp2[quiz] << "\n";
    }

    return (0);
}