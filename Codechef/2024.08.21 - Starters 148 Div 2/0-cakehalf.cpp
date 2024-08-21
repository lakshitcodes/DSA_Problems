#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START148B/problems/CAKEHALF

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        while (a != b)
        {
            if (a > b)
            {
                int diff = (a + 1) / 2;
                ans += diff;
                a -= diff;
            }
            else
            {
                int diff = (b + 1) / 2;
                ans += diff;
                b -= diff;
            }
        }
        cout << ans << endl;
    }
    return 0;
}