#include <bits/stdc++.h>
using namespace std;

void solve(long long n)
{
    cout << n << " ";
    if (n == 1)
    {
        return;
    }
    if (n % 2)
    {
        return solve(n * 3 + 1);
    }
    else
    {
        return solve(n / 2);
    }
}
int main()
{
    long long n;
    cin >> n;
    solve(n);
    return 0;
}