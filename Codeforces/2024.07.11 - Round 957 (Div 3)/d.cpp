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
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;
        river = "L" + river + "L";
        int currPos = 0;
        int swum = 0;
        bool isSafe = true;

        while (currPos <= n && isSafe)
        {
            bool jumped = false;

            for (int i = 1; i <= m; ++i)
            {
                if (currPos + i > n + 1)
                    break;
                if (river[currPos + i] == 'L')
                {
                    currPos += i;
                    jumped = true;
                    break;
                }
            }

            if (!jumped)
            {
                for (int i = 1; i <= k; ++i)
                {
                    if (currPos + i > n + 1)
                        break;
                    if (river[currPos + i] == 'C')
                    {
                        isSafe = false;
                        break;
                    }
                    if (river[currPos + i] == 'L')
                    {
                        currPos += i;
                        swum += i;
                        jumped = true;
                        break;
                    }
                }
                if (!jumped)
                {
                    currPos += k;
                    swum += k;
                }
            }

            if (swum > k)
            {
                isSafe = false;
            }
        }

        if (isSafe && currPos >= n + 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
