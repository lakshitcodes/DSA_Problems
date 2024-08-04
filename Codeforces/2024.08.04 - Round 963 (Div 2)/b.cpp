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
        int n;
        cin >> n;
        vll arr(n);
        take(arr);

        ll even = 0;
        ll odd = 0;
        ll oddValue = 0;
        for (auto &i : arr)
        {
            if (i % 2 == 0)
                even++;
            if (i % 2)
            {
                odd++;
                oddValue = max(oddValue, i);
            }
        }
        if (even == 0 || odd == 0)
        {
            cout << 0 << endl;
            continue;
        }

        priority_queue<ll> pq;
        ll ans = 0;
        pq.push(oddValue);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                ll element = pq.top();
                while (element < arr[i])
                {
                    element += arr[i];
                    ans++;
                }
                ans++;
                pq.push(element + arr[i]);
            }
        }
        cout << min(ans, even + 1) << endl;
    }
    return 0;
}