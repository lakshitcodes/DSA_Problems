#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START140C/problems/YOGACLASS

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (y > 2 * x)
        {
            long long ans = 0;
            ans += y * (n / 2);
            if (n % 2 == 1)
            {
                ans += x;
            }
            cout << ans << endl;
        }
        else
        {
            long long ans = n * x;
            cout << ans << endl;
        }
    }
    return 0;
}