#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int maxLength = 0;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        int currLength = 1;
        char currChar = s[i];
        while (i < n - 1 && s[i + 1] == currChar)
        {
            i++;
            currLength++;
        }
        maxLength = max(maxLength, currLength);
        i++;
    }
    cout << maxLength << endl;
    return 0;
}