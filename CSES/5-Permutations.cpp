#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    long long d = n;
    if (n % 2)
    {
        d--;
        while (n > 0)
        {
            cout << n << " ";
            n -= 2;
        }
        while (d != 0)
        {
            cout << d << " ";
            d -= 2;
        }
    }
    else
    {
        n--;
        while (n > 0)
        {
            cout << n << " ";
            n -= 2;
        }
        while (d != 0)
        {
            cout << d << " ";
            d -= 2;
        }
    }
    return 0;
}