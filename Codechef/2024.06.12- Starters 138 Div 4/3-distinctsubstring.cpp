#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int len, req;
        cin >> len >> req;
        if (req == 1 && len >= 1)
        {
            cout << "YES\n";
            continue;
        }
        int reqLength = (req + 1) * (req + 2) / 2;
        if (reqLength - 2 > len)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}