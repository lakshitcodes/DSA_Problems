#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START140C/problems/MAKEPERM

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
        vector<int> arr(n);
        for (auto &i : arr)
        {
            cin >> i;
        }
        sort(arr.begin(), arr.end());
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > i + 1)
            {
                possible = false;
                break;
            }
        }
        if (possible)
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