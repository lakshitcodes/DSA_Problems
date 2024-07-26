#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
C. Sort
time limit per test5 seconds
memory limit per test256 megabytes
You are given two strings a and b of length n. Then, you are (forced against your will) to answer q queries.

For each query, you are given a range bounded by l and r. In one operation, you can choose an integer i (l≤i≤r) and set ai=x where x is any character you desire. Output the minimum number of operations you must perform such that sorted(a[l..r])=sorted(b[l..r]). The operations you perform on one query does not affect other queries.

For an arbitrary string c, sorted(c[l..r]) denotes the substring consisting of characters cl,cl+1,...,cr sorted in lexicographical order.

Input
The first line contains t (1≤t≤1000) – the number of test cases.

The first line of each test case contains two integers n and q (1≤n,q≤2⋅105) – the length of both strings and the number of queries.

The following line contains a of length n. It is guaranteed a only contains lowercase latin letters.

The following line contains b of length n. It is guaranteed b only contains lowercase latin letters.

The following q lines contain two integers l and r (1≤l≤r≤n) – the range of the query.

It is guaranteed the sum of n and q over all test cases does not exceed 2⋅105.

Output
For each query, output an integer, the minimum number of operations you need to perform in a new line.
*/

#define ALPHABET_SIZE 26

void preprocess(const string &a, const string &b, vector<vector<int>> &prefix)
{
    int n = a.size();
    prefix.assign(n + 1, vector<int>(ALPHABET_SIZE, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < ALPHABET_SIZE; ++j)
        {
            prefix[i + 1][j] = prefix[i][j];
        }
        prefix[i + 1][a[i] - 'a']++;
        prefix[i + 1][b[i] - 'a']--;
    }
}

int solve(const vector<vector<int>> &prefix, int start, int end)
{
    vector<int> diff(ALPHABET_SIZE, 0);

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        diff[i] = prefix[end][i] - prefix[start - 1][i];
    }

    int pos = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (diff[i] > 0)
            pos += diff[i];
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> prefix;
        preprocess(a, b, prefix);

        while (q--)
        {
            int start, end;
            cin >> start >> end;
            cout << solve(prefix, start, end) << endl;
        }
    }
    return 0;
}
