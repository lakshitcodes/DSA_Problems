#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START139D/problems/MAXDISTPERM

int main()
{
    // your code goes here
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        int diff = n / 2;
        int index = (n + 1) / 2;
        for (int i = 1; i <= index; i++)
        {
            cout << i + diff << ' ';
        }

        if (n % 2 == 0)
        {
            for (int i = index + 1; i <= n; i++)
            {
                cout << i - diff << " ";
            }
        }
        else
        {
            for (int i = index + 1; i < n; i++)
            {
                cout << i - diff << ' ';
            }
            if (n != 1)
                cout << 1;
        }
        cout << endl;
    }
    return 0;
}
