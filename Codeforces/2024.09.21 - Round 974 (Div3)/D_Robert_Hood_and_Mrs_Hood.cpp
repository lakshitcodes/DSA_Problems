#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
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
        int n, d, k;
        cin >> n >> d >> k;
        vii arr(k);
        for (auto &i : arr)
        {
            cin >> i.first >> i.second;
        }
        vi days(n + 1, 0);
        for (auto &i : arr)
        {
            for (int start = i.first; start <= i.second; start++)
            {
                days[start]++;
            }
        }
        int maxElement = INT_MIN;
        int maxi = 1, mini = 1;
        int minElement = INT_MAX;
        for (int i = 1; i <= n - d; i++)
        {
            if (days[i] > maxElement)
            {
                maxElement = days[i];
                maxi = i;
            }
            if (days[i] < minElement)
            {
                minElement = days[i];
                mini = i;
            }
        }
        cout << maxi << " " << mini << endl;
    }
    return 0;
}