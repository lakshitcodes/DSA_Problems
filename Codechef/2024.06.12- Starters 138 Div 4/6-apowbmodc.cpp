#include <bits/stdc++.h>
using namespace std;

bool checkCondition(long long A, long long B, long long C)
{
    return (A % B == 0) && (B % A == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long A;
        cin >> A;

        long long B = A + 1; // Start with B = A + 1
        long long C = 2;     // Start with C = 2

        while (true)
        {
            if (checkCondition(A, B, C))
            {
                cout << B << " " << C << endl;
                break;
            }
            if (A * A % B == 0)
            {
                C++;
            }
            B++;
        }
    }

    return 0;
}
