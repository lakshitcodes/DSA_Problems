#include <bits/stdc++.h>
using namespace std;

/*
E. Alternating String
time limit per test
2 seconds
memory limit per test
256 megabytes

Sakurako really loves alternating strings. She calls a string s of lowercase Latin letters an alternating string if characters in the even positions are the same, if characters in the odd positions are the same, and the length of the string is even.

For example, the strings 'abab' and 'gg' are alternating, while the strings 'aba' and 'ggwp' are not.

As a good friend, you decided to gift such a string, but you couldn't find one. Luckily, you can perform two types of operations on the string:

    Choose an index iand delete the i-th character from the string, which will reduce the length of the string by 1. This type of operation can be performed no more than 1
time;
Choose an index i and replace si    with any other letter.
Since you are in a hurry, you need to determine the minimum number of operations required to make the string an alternating one.
Input

The first line contains a single integer t(1≤t≤104)  — the number of test cases.

The first line of each test case contains a single number n(1≤n≤2⋅105)  — the length of the string.

The second line of each test case contains a string s, consisting of lowercase Latin letters.

It is guaranteed that the sum of nacross all test cases does not exceed 2⋅105
Output

For each test case, output a single integer — the minimum number of operations required to turn the string s into an alternating one.
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 0)
        {
            map<char, int> even, odd;
            for (int i = 0; i < n; i++)
            {
                if (i % 2)
                {
                    odd[s[i]]++;
                }
                else
                {
                    even[s[i]]++;
                }
            }
            int evenMax = 0, oddMax = 0;
            for (auto &i : even)
            {
                evenMax = max(evenMax, i.second);
            }
            for (auto &i : odd)
            {
                oddMax = max(oddMax, i.second);
            }
            int evenRem = n / 2 - evenMax;
            int oddRem = n / 2 - oddMax;
            int ans = evenRem + oddRem;
            cout << ans << endl;
        }
        else
        {
            map<char, int> even, odd, even2, odd2;
            for (int i = 0; i < n - 1; i++)
            {
                if (i % 2)
                {
                    odd[s[i]]++;
                }
                else
                {
                    even[s[i]]++;
                }
            }
            int evenMax = 0, oddMax = 0;
            for (auto &i : even)
            {
                evenMax = max(evenMax, i.second);
            }
            for (auto &i : odd)
            {
                oddMax = max(oddMax, i.second);
            }
            int ans = (n / 2 - oddMax) + (n / 2 - evenMax);
            for (int i = n - 2; i >= 0; i--)
            {
                if (i % 2)
                {
                    odd[s[i]]--;
                    odd2[s[i + 1]]++;
                }
                else
                {
                    even[s[i]]--;
                    even2[s[i + 1]]++;
                }

                map<char, int> evenMerge = even;
                map<char, int> oddMerge = odd;
                for (auto &i : odd2)
                {
                    oddMerge[i.first] += i.second;
                }
                for (auto &i : even2)
                {
                    evenMerge[i.first] += i.second;
                }
                evenMax = 0, oddMax = 0;
                for (auto &i : evenMerge)
                {
                    evenMax = max(evenMax, i.second);
                }
                for (auto &i : oddMerge)
                {
                    oddMax = max(oddMax, i.second);
                }
                ans = min(ans, n / 2 + n / 2 - evenMax - oddMax);
            }
            cout << ans + 1 << endl;
        }
    }
    return 0;
}