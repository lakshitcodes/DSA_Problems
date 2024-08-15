#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START147B/problems/NONPRIME101

vector<bool> precomputePrimes(int max_sum)
{
    vector<bool> is_prime(max_sum + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_sum; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_sum; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main()
{
    int T;
    cin >> T;

    vector<bool> is_prime = precomputePrimes(200);

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> count(101, 0);

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
            count[A[i]]++;
        }

        bool found = false;

        for (int i = 1; i <= 100 && !found; ++i)
        {
            if (count[i] == 0)
                continue;
            for (int j = i; j <= 100; ++j)
            {
                if (count[j] == 0)
                    continue;
                int sum = i + j;
                if (!is_prime[sum])
                {
                    if (i == j && count[i] > 1)
                    {
                        found = true;
                    }
                    else if (i != j)
                    {
                        found = true;
                    }
                    if (found)
                    {
                        // Finding the indices
                        int index_i = -1, index_j = -1;
                        for (int k = 0; k < N; ++k)
                        {
                            if (A[k] == i && index_i == -1)
                            {
                                index_i = k + 1;
                            }
                            else if (A[k] == j && index_j == -1)
                            {
                                index_j = k + 1;
                            }
                            if (index_i != -1 && index_j != -1)
                            {
                                cout << index_i << " " << index_j << endl;
                                break;
                            }
                        }
                    }
                }
                if (found)
                    break;
            }
        }

        if (!found)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
