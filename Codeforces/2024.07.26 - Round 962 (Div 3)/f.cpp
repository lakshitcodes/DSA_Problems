#include <bits/stdc++.h>
using namespace std;

/*
F. Bomb
time limit per test2 seconds
memory limit per test256 megabytes
Sparkle gives you two arrays a and b of length n. Initially, your score is 0. In one operation, you can choose an integer i and add ai to your score. Then, you must set ai = max(0,ai−bi).

You only have time to perform k operations before Sparkle sets off a nuclear bomb! What is the maximum score you can acquire after k operations?

Input
The first line contains t (1≤t≤1000) — the number of test cases.

The first line of each test case contains n and k (1≤n≤2⋅105,1≤k≤109) — the length of the arrays and the number of operations you can perform.

The following line contains n integers a1,a2,...an (1≤ai≤109).

The following line contains n integers b1,b2,...bn (1≤bi≤109).

It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

Output
For each test case, output an integer, the maximum score you can acquire after k operations.
*/

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

class comparator
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first < b.first;
    }
};
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
        vii a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq(a.begin(), a.end());
        long long ans = 0;
        while (k-- && !pq.empty())
        {
            pair<int, int> frontElement = pq.top();
            pq.pop();
            if (frontElement.first == 0)
            {
                break;
            }
            ans += frontElement.first;
            frontElement.first = max(frontElement.first - frontElement.second, 0);
            if (pq.empty())
            {
                while (k && frontElement.first != 0)
                {
                    if (frontElement.first != 0)
                    {
                        ans += frontElement.first;
                        frontElement.first = max(frontElement.first - frontElement.second, 0);
                        k--;
                    }
                }
            }
            else
            {
                while (frontElement.first > pq.top().first && k)
                {
                    ans += frontElement.first;
                    frontElement.first = max(frontElement.first - frontElement.second, 0);
                    k--;
                }
            }
            if (frontElement.first > 0)
                pq.push(frontElement);
        }
        cout << ans << endl;
    }
    return 0;
}