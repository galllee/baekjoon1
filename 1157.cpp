#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    string  s;
    int     len = 0;
    int     alphabet[26] = {0};
    int     max = 0;
    int     maxindex;
    char    maxalphabet;

    cin >> s;
    while (s[len])
        len++;
    for (int i = 0; i < len; i++)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (s[i] == c || s[i] == c - 'A' + 'a')
            {
                alphabet[c - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (max < alphabet[i])
        {
            max = alphabet[i];
            maxindex = i;
            maxalphabet = i + 'A';
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (i == maxindex)
            continue;
        if (max == alphabet[i])
        {
            cout << "?";
            return (0);
        }
    }
    cout << maxalphabet;
    return (0);
}