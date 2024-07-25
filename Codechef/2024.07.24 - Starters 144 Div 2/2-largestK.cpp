#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START144B/problems/LARGESTK

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

int findLargestK(int n, vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int num : arr)
    {
        freq[num]++;
    }

    vector<int> distinctCounts;

    for (auto it : freq)
    {
        distinctCounts.push_back(it.second);
    }

    sort(distinctCounts.rbegin(), distinctCounts.rend());

    int numDistinct = distinctCounts.size();
    vector<int> prefixSums(numDistinct + 1, 0);

    for (int i = 0; i < numDistinct; i++)
    {
        prefixSums[i + 1] = prefixSums[i] + distinctCounts[i];
    }

    int maxK = 0;

    for (int d = 1; d <= numDistinct; d++)
    {
        int totalElements = prefixSums[d];
        maxK = max(maxK, totalElements - (totalElements % d));
    }

    return maxK;
}

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
        cout << findLargestK(n, arr) << endl;
    }
    return 0;
}

// Solution Here