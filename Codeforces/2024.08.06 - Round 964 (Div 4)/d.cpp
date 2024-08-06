#include <iostream>
#include <string>
using namespace std;

/*
D. Slavic's Exam
time limit per test2 seconds
memory limit per test256 megabytes
Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with:

There exists a string s, which consists of lowercase English letters and possibly zero or more "?".

Slavic is asked to change each "?" to a lowercase English letter such that string t becomes a subsequence (not necessarily continuous) of the string s.

Output any such string, or say that it is impossible in case no string that respects the conditions exists.

Input
The first line contains a single integer T (1≤T≤104) — the number of test cases.

The first line of each test case contains a single string s (1≤|s|≤2⋅105, and s consists only of lowercase English letters and "?"-s)  – the original string you have.

The second line of each test case contains a single string t (1≤|t|≤|s|, and t consists only of lowercase English letters)  – the string that should be a subsequence of string s.

The sum of |s| over all test cases doesn't exceed 2⋅105, where |x| denotes the length of the string x.

Output
For each test case, if no such string exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string that respects all conditions.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.
*/

bool canFormSubsequence(string &s, const string &t)
{
    int sLen = s.length();
    int tLen = t.length();

    int tIndex = 0;
    for (int i = 0; i < sLen; ++i)
    {
        if (tIndex < tLen && (s[i] == t[tIndex] || s[i] == '?'))
        {
            ++tIndex;
        }
    }

    return tIndex == tLen;
}

void fillString(string &s, const string &t)
{
    int tIndex = 0;
    int sLen = s.length();
    for (int i = 0; i < sLen; ++i)
    {
        if (s[i] == '?')
        {
            if (tIndex < t.length())
            {
                s[i] = t[tIndex++];
            }
            else
            {
                s[i] = 'a';
            }
        }
        else if (s[i] == t[tIndex])
        {
            ++tIndex;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        if (canFormSubsequence(s, t))
        {
            fillString(s, t);
            cout << "YES\n"
                 << s << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
