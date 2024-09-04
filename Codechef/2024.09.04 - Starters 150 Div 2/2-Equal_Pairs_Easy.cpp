#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START150B/problems/MAXEQEASY

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
        int n;
        cin >> n;
        vi arr(n);
        take(arr);
        unordered_map<int, int> freq;
        for (auto &i : arr)
        {
            freq[i]++;
        }
        int maxFreq = 0, maxElement = 0;
        for (auto &i : freq)
        {
            if (i.second > maxFreq && i.first != 0)
            {
                maxFreq = i.second;
                maxElement = i.first;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                arr[i] = maxElement;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}