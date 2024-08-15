#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START147B/problems/TRUTHLIE

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
        int n, m;
        cin >> n >> m;
        if (n > m)
        {
            cout << 2 * m + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}