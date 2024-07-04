#include <bits/stdc++.h>

// https://www.codechef.com/START140C/problems/SPLITPERM

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 1 << " " << 2 << endl;
            continue;
        }
        if (n % 2 == 1)
        {
            cout << n << ' ';
            n--;
        }
        for (int i = 1; i <= n / 2; i++)
        {
            cout << n - i + 1 << " " << i << " ";
        }
        cout << endl;
    }
    return 0;
}