#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/START139D/problems/COUNTN

#define int long long
using vi = vector<int>;

const int LIMIT = 1e6 + 2;

vector<int> primeList;
vector<int> smallestPrimeFactor(LIMIT, 0);

// Calculate the smallest prime factors (SPF) for every number up to LIMIT
void computeSmallestPrimeFactors()
{
    smallestPrimeFactor[1] = 1;
    for (int i = 2; i < LIMIT; i++)
    {
        if (smallestPrimeFactor[i] == 0)
        {
            smallestPrimeFactor[i] = i;
            for (int j = i * i; j < LIMIT; j += i)
            {
                if (smallestPrimeFactor[j] == 0)
                {
                    smallestPrimeFactor[j] = i;
                }
            }
        }
    }
}

// Function to process each test case
void handleTestCase()
{
    int k;
    cin >> k;
    int totalSum = 0;
    if (smallestPrimeFactor[k] == k)
    { // k is a prime number
        for (int i = 0; i < primeList.size() && primeList[i] <= k; i++)
        {
            totalSum += primeList[i] * k;
        }
    }
    else
    { // k is not a prime number
        for (int i = 0; i < primeList.size() && primeList[i] <= smallestPrimeFactor[k]; i++)
        {
            totalSum += primeList[i] * k;
        }
    }
    cout << totalSum << '\n';
}

signed main()
{
    // Precompute smallest prime factors for all numbers up to LIMIT
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    computeSmallestPrimeFactors();

    // Collect all prime numbers up to LIMIT
    for (int i = 2; i < LIMIT; i++)
    {
        if (smallestPrimeFactor[i] == i)
        {
            primeList.push_back(i);
        }
    }

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        handleTestCase();
    }
    return 0;
}
