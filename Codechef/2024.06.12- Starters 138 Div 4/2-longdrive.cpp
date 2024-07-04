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
        int curr, req;
        cin >> curr >> req;
        int ans = 0;
        int currDist = curr * 10;
        while (currDist / (10 + ans) < req)
        {
            ans++;
            currDist += 100;
        }
        cout << ans << endl;
    }
    return 0;
}