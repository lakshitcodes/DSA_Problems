#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a, b) map<a, b>
#define set(a, b) set<a, b>
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
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
        int n, k;
        cin >> n >> k;
        vi arr(n);
        take(arr);
        int ans = 0, curr = 0;
        for (auto &i : arr)
        {
            if (i >= k)
            {
                curr += i;
            }
            else if (i == 0)
            {
                if (curr)
                {
                    curr--;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}