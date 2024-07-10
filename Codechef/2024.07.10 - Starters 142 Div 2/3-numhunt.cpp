#include <iostream>
using namespace std;

// Question Link :  https://www.codechef.com/START142B/problems/NUMHUNT

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
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
        int prime1 = n;
        // Agar prime hi nahi to fix karo
        while (!isPrime(prime1))
        {
            prime1++;
        }

        // Bada Prime Number than n
        int prime2 = prime1 + 1;
        while (!isPrime(prime2))
        {
            prime2++;
        }

        cout << (long long)prime1 * prime2 << endl;
    }
    return 0;
}