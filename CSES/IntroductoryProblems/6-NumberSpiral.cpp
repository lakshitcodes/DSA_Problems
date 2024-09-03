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
        ll x, y;
        cin >> x >> y;
        swap(x, y);
        if (x >= y)
        {
            if (x % 2)
            {
                cout << x * x - y + 1 << endl;
            }
            else
            {
                cout << (x - 1) * (x - 1) + y << endl;
            }
        }
        else
        {
            if (y % 2)
            {
                cout << (y - 1) * (y - 1) + x << endl;
            }
            else
            {
                cout << y * y - x + 1 << endl;
            }
        }
    }
    return 0;
}