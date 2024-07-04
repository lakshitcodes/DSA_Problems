#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n, const vector<bool> &sieve)
{
    return n > 1 && !sieve[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        // Generate primes up to sqrt(N) using Sieve of Eratosthenes
        int limit = sqrt(N);
        vector<bool> sieve(limit + 1, false);
        sieve[0] = sieve[1] = true;
        for (int i = 2; i * i <= limit; i++)
        {
            if (!sieve[i])
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    sieve[j] = true;
                }
            }
        }

        // Collect all primes up to limit
        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
        {
            if (!sieve[i])
                primes.push_back(i);
        }

        bool found = false;

        // Iterate over all combinations of distinct primes a, b, c
        for (int i = 0; i < primes.size() && !found; ++i)
        {
            int a = primes[i];
            for (int j = i + 1; j < primes.size() && !found; ++j)
            {
                int b = primes[j];
                for (int k = j + 1; k < primes.size() && !found; ++k)
                {
                    int c = primes[k];
                    if (a * a + b * b + c * c == N)
                    {
                        cout << "Yes\n";
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found)
            cout << "No\n";
    }

    return 0;
}
