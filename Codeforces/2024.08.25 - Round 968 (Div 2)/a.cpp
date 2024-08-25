#include <bits/stdc++.h>
using namespace std;

/*
A. Turtle and Good Strings
time limit per test1 second
memory limit per test256 megabytes
Turtle thinks a string s is a good string if there exists a sequence of strings t1,t2,…,tk (k is an arbitrary integer) such that:
 k≥2.s=t1+t2+…+tk, where + represents the concatenation operation. For example, abc=a+bc.
For all 1≤i<j≤k, the first character of ti isn't equal to the last character of tj.
Turtle is given a string s consisting of lowercase Latin letters. Please tell him whether the string s is a good string!

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤100) — the length of the string.

The second line of each test case contains a string s of length n, consisting of lowercase Latin letters.

Output
For each test case, output "YES" if the string s is a good string, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
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
        if (s.front() != s.back())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}