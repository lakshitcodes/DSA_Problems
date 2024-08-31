#include <bits/stdc++.h>
using namespace std;

/*
C. Dora and C++
time limit per test2 seconds
memory limit per test256 megabytes
Dora has just learned the programming language C++!

However, she has completely misunderstood the meaning of C++. She considers it as two kinds of adding perations on the array c with n elements. Dora has two integers a and b. In one operation, she can choose one of the following things to do.

Choose an integer i such that 1≤i≤n, and increase ci by a.
Choose an integer i such that 1≤i≤n, and increase ci by b.
Note that a and b are constants, and they can be the same.

Let's define a range of array d as max(di)−min(di). For instance, the range of the array [1,2,3,4] is 4−1=3, the range of the array [5,2,8,2,2,1] is 8−1=7, and the range of the array [3,3,3] is 3−3=0.

After any number of operations (possibly, 0), Dora calculates the range of the new array. You need to help Dora minimize this value, but since Dora loves exploring all by herself, you only need to tell her the minimized value.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows.

The first line of each test case contains three integers n, a, and b (1≤n≤105, 1≤a,b≤109) — the length of the array c and the constant values, respectively.

The second line of each test case contains n integers c1,c2,…,cn (1≤ci≤109) — the initial elements of the array c.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output a single integer — the minimum possible range of the array after any number of operations.
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

/*
Approach : Here Bezout Theorem is used, which states that given two numbers x and y,we can have all the multiples of the gcd of x and y
in the form of ax + by = gcd(x,y) where a and b are integers.
Here and b can be negative.
But in our case it is given that we can only add but can not subtract which takes away the scope for negative a or b.
But since we only have to deal with the differences  this wouldn't matter and the final answer would not change because if we have the minimum number as let say -100, we can make this number positive by adding numbers not just to it but to all the numbers thus keeping the difference same.

Now the only thing to consider is the number modulo the gcd because all of the difference can be covered by adding the numbers in a specific pattern.

And then simply find the farthest number from each and every number in a circular fashion in the modulo range, for eg if the gcd is 7 , then the remainder after modulo is 0,1,2,3,4,5,6

Here if we have the modulos as 1,2,6 , then the farthest from 1 is 6, 2 is 1 and 6 is 2.

*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int g = __gcd(a, b);
        vll arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= g;
        }
        sort(arr.begin(), arr.end());
        ll ans = arr[n - 1] - arr[0];
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, arr[i - 1] + g - arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}