#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START142B/problems/CHEFIZZA

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long temp = n;
        int power = 0;
        while (temp > 1)
        {
            temp >>= 1;
            power++;
        }
        if (temp)
        {
            power++;
        }
        long long maximum = 1 << power;
        // cout<<maximum<<' ';
        int difference = maximum - n;
        cout << n - difference << endl;
    }
    return 0;
}
