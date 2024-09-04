#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START150B/problems/RATIO2

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
        int x, y;
        cin >> x >> y;
        if (y > x)
        {
            swap(x, y);
        }
        if (x < 2 * y)
        {
            cout << min(2 * y - x, y - x / 2) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}