#include <bits/stdc++.h>
using namespace std;

/*
B. Substring and Subsequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two strings a and b, both consisting of lowercase Latin letters.

A subsequence of a string is a string which can be obtained by removing several (possibly zero) characters from the original string. A substring of a string is a contiguous subsequence of that string.

For example, consider the string abac:

a, b, c, ab, aa, ac, ba, bc, aba, abc, aac, bac and abac are its subsequences;
a, b, c, ab, ba, ac, aba, bac and abac are its substrings.
Your task is to calculate the minimum possible length of the string that contains a as a substring and b as a subsequence.

Input
The first line contains a single integer t (1≤t≤103) — the number of test cases.

The first line of each test case contains a string a (1≤|a|≤100), consisting of lowercase Latin letters.

The second line of each test case contains a string b (1≤|b|≤100), consisting of lowercase Latin letters.

Output
For each test case, print a single integer — the minimum possible length of the string that contains a as a substring and b as a subsequence.
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = b.length() - 1; i >= 0; i--)
        {
            int currAns = 0;
            int bInd = i;
            for (int j = a.length() - 1; j >= 0; j--)
            {
                if (bInd >= 0 && b[bInd] == a[j])
                {
                    bInd--;
                    currAns++;
                }
                if (bInd < 0)
                {
                    break;
                }
            }
            ans = max(ans, currAns);
        }
        cout << a.length() + b.length() - ans << endl;
    }
    return 0;
}