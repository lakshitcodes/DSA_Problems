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
        int n;
        cin >> n;
        vector<int> ans(n, 0);
        for (int i = 1; i < n - 1; i++)
        {
            ans[i] = 1;
        }
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}