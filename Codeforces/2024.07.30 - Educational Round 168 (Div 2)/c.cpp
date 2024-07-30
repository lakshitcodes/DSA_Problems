#include <bits/stdc++.h>
using namespace std;

/*
C. Even Positions
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp had a regular bracket sequence s of length n (n is even). He even came up with his own way to calculate its cost.

He knows that in a regular bracket sequence (RBS), each opening bracket is paired up with the corresponding closing bracket. So he decided to calculate the cost of RBS as the sum of distances between pairs of corresponding bracket pairs.

For example, let's look at RBS (())(). It has three pairs of brackets:

(__)__: the distance between brackets at position 1 and at 4 is 4−1=3;
_()___: the distance is 3−2=1;
____(): the distance is 6−5=1.
So the cost of (())() is 3+1+1=5.
Unfortunately, due to data corruption, Monocarp lost all characters on odd positions s1,s3,…,sn−1
. Only characters on even positions (s2,s4,…,sn) remain. For example, (())() turned to _(_)_).

Monocarp wants to restore his RBS by placing brackets on the odd positions. But since the restored RBS may not be unique, he wants to choose one with minimum cost. It's too hard to do for Monocarp alone, so can you help him?

Reminder: A regular bracket sequence is a string consisting of only brackets, such that this sequence, when inserted 1-s and +-s, gives a valid mathematical expression. For example, (), (()) or (()())() are RBS, while ), ()( or ())(() are not.

Input
The first line contains a single integer t (1≤t≤5000) — the number of test cases. Next t cases follow.

The first line of each test case contains a single integer n (2≤n≤2⋅105; n is even) — the length of string s.

The second line of each test case contains a string s of length n, where all characters on the odd positions are '_' and all characters on the even positions are either '(' or ')'.

Additional constraints:

s can be restored to at least one regular bracket sequence;
the total sum of n over all test cases doesn't exceed 2⋅105.
Output
For each test case, print one integer — the minimum cost of the regular bracket sequence that can be obtained from s
 by replacing '_'-s with brackets.
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

int findScore(string s)
{
    stack<int> st;
    int score = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            score += i - st.top();
            st.pop();
        }
    }
    return score;
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
        string s;
        cin >> s;
        int open = 0, close = 0;
        for (auto &i : s)
        {
            if (i == '(')
            {
                open++;
            }
            else if (i == ')')
            {
                close++;
            }
            else
            {
                if (open <= close)
                {
                    open++;
                    i = '(';
                }
                else
                {
                    close++;
                    i = ')';
                }
            }
        }
        int score = findScore(s);
        cout << score << endl;
    }
    return 0;
}