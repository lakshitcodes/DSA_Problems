#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.codechef.com/START144B/problems/TCG

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << "INCREASED" << endl;
    }
    else if (a == b)
    {
        cout << "SAME" << endl;
    }
    else
    {
        cout << "DECREASED" << endl;
    }
}
