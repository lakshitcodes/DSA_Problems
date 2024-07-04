#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START139D/problems/DISCOOKIE

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, cookie;
        cin >> n >> cookie;
        if (cookie % n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (n > cookie)
        {
            cout << n - cookie << endl;
            continue;
        }
        int divi = cookie / n;
        int ans = min(cookie - divi * n, (divi + 1) * n - cookie);
        cout << ans << endl;
    }
    return 0;
}
