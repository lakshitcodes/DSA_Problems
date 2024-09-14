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
        int n, m, q;
        cin >> n >> m >> q;
        int b1, b2, a1;
        cin >> b1 >> b2 >> a1;
        if (b1 > b2)
        {
            swap(b1, b2);
        }
        if (b2 < a1)
        {
            cout << n - b2 << endl;
        }
        else if (a1 < b1)
        {
            cout << b1 - 1 << endl;
        }
        else
        {
            ll mid = (b1 + b2) >> 1;
            ll dist1 = b1 - mid;
            ll dist2 = mid - b2;
            cout << min(abs(dist1), abs(dist2)) << endl;
        }
    }
    return 0;
}