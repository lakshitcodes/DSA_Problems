#include <bits/stdc++.h>
using namespace std;

/*
B. Generate Permutation
time limit per test1.5 seconds
memory limit per test256 megabytes
There is an integer sequence a of length n, where each element is initially −1.

Misuki has two typewriters where the first one writes letters from left to right, with a pointer initially pointing to 1, and another writes letters from right to left with a pointer initially pointing to n.

Misuki would choose one of the typewriters and use it to perform the following operations until a becomes a permutation of [1,2,…,n]write number: write the minimum positive integer that hasn't appeared in a to ai, i is the position where the pointer points at. Such operation can be performed only when ai=−1.
carriage return: return the pointer to its initial position (i.e. 1 for the first typewriter, n for the second)move pointer: move the pointer to the next position, let i be the position the pointer points at before this operation, if Misuki is using the first typewriter, i:=i+1 would happen, and i:=i−1 otherwise. Such operation can be performed only if after the operation, 1≤i≤n holds.
Your task is to construct any permutation p of length n, such that the minimum number of carriage return operations needed to make a=p is the same no matter which typewriter Misuki is using.

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the permutation.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a line of n integers, representing the permutation p of length n such that the minimum number of carriage return operations needed to make a=p
 is the same no matter which typewriter Misuki is using, or −1 if it is impossible to do so.

If there are multiple valid permutations, you can output any of them.
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
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 0)
        {
            cout << -1 << endl;
            continue; // hain hi nhi
        }

        for (int i = 1; i <= n / 2; i++)
        {
            cout << i << " ";
        }
        for (int i = n; i > n / 2; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}