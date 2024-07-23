#include <bits/stdc++.h>
using namespace std;

// This gives wrong answer on testcase 3

/*
B2. Bouquet (Hard Version)
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is the hard version of the problem. The only difference is that in this version, instead of listing the number of petals for each flower, the number of petals and the quantity of flowers in the store is set for all types of flowers.

A girl is preparing for her birthday and wants to buy the most beautiful bouquet. There are a total of n
 different types of flowers in the store, each of which is characterized by the number of petals and the quantity of this type of flower. A flower with k
 petals costs k
 coins. The girl has decided that the difference in the number of petals between any two flowers she will use to decorate her cake should not exceed one. At the same time, the girl wants to assemble a bouquet with the maximum possible number of petals. Unfortunately, she only has m
 coins, and she cannot spend more. What is the maximum total number of petals she can assemble in the bouquet?

Input
Each test consists of several test cases. The first line contains a single integer t (1≤t≤10000) — the number of test cases. This is followed by descriptions of the test cases.

The first line of each test case contains two integers n, m (1≤n≤2⋅105,1≤m≤1018) — the number of types of flowers in the store and the number of coins the girl possesses, respectively. The second line of each test case contains n
 different integers a1,a2,…,an (1≤ai≤109), where ai is the number of petals of the i-th flower type in the store (for different indexes i≠j, it must be ai≠aj). The third line of each test case contains n
 integers c1,c2,…,cn (1≤ci≤109), where ci is the quantity of the i-th flower type in the store.

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the maximum possible number of petals in a bouquet that a girl can collect, observing all the conditions listed above.
*/

#define ll long long
#define vi vector<ll>
#define umap unordered_map

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        ll coins;
        cin >> n >> coins;
        vi uniquePetals(n), count(n);

        for (ll i = 0; i < n; ++i)
        {
            cin >> uniquePetals[i];
        }
        for (ll i = 0; i < n; ++i)
        {
            cin >> count[i];
        }

        if (coins == 0)
        {
            cout << 0 << endl;
            continue;
        }

        umap<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[uniquePetals[i]] = count[i];
        }

        sort(uniquePetals.begin(), uniquePetals.end());

        ll maxAns = 0;

        for (const auto &petal : uniquePetals)
        {
            ll ans = 0;
            ll temp = coins;

            ll currFreq = mp[petal];
            ll currElement = petal;
            ll currCost = currFreq * currElement;

            if (temp < currCost)
            {
                ans += (temp / currElement) * currElement;
                temp %= currElement;
            }
            else
            {
                ans += currCost;
                temp -= currCost;
            }
            maxAns = max(maxAns, ans);
            if (mp.count(currElement + 1))
            {
                for (int i = max(0LL, mp[currElement] - 100); i <= mp[currElement]; i++)
                {
                    ans = 0, temp = coins;
                    ll currFreq = i;
                    ll currCost = currFreq * currElement;

                    if (temp < currCost)
                    {
                        ans += (temp / currElement) * currElement;
                        temp %= currElement;
                    }
                    else
                    {
                        ans += currCost;
                        temp -= currCost;
                    }
                    ll nextFreq = mp[currElement + 1];
                    ll nextElement = currElement + 1;
                    ll nextCost = nextFreq * nextElement;
                    if (temp < nextCost)
                    {
                        ans += (temp / nextElement) * nextElement;
                        temp %= nextElement;
                    }
                    else
                    {
                        ans += nextCost;
                        temp -= nextCost;
                    }
                    maxAns = max(maxAns, ans);
                }
            }

            maxAns = max(maxAns, ans);
        }

        cout << maxAns << endl;
    }

    return 0;
}
