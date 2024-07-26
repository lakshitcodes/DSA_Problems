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

long long countTriplets(int n, int x)
{
    long long count = 0;
    for (int a = 1; a <= x - 2; ++a)
    {
        for (int b = 1; b <= x - a - 1; ++b)
        {
            int max_c = min(x - a - b, (n - a * b) / (a + b));
            if (max_c >= 1)
            {
                count += max_c;
            }
        }
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        cout << countTriplets(n, x) << endl;
    }
    return 0;
}