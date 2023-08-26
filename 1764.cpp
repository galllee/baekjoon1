#include <iostream>
#include <stack>
using namespace std;

void fast()
{
	//속도 빠르게
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
    fast();
    string str;
    int num = 0;
    stack <int> s;

    cin >> str;
    for(int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            if (str[i + 1] == ')')
            {
                num += s.size();
                continue;
            }
            else
                s.push(str[i]);
        }
        else
        {
            if (str[i - 1] != '(')
            {
                num++;
                s.pop();
            }
        }
    }
    cout << num;
    return (0);
}