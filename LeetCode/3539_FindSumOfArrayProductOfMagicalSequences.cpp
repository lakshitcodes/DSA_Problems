#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/

static int C[31][31] = {{0}};
static int dp[31][31][50][31];
const int mod = 1e9 + 7;
class Solution
{
public:
    int n, m, k;

    void Pascal()
    {
        if (C[0][0] == 1)
        {
            return; // Compute only once
        }

        for (int i = 1; i <= 30; i++)
        {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++)
            {
                const int Cij = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = C[i][i - j] = Cij;
            }
        }
    }
    int dfs(int m, int k, int i, unsigned flag, vector<int> &nums)
    {
        const int bz = popcount(flag);
        if (m < 0 || k < 0 || m + bz < k)
        {
            return 0;
        }
        if (m == 0)
        {
            return (k == bz) ? 1 : 0;
        }
        if (i >= n)
        {
            return 0;
        }

        if (dp[m][k][i][flag] != -1)
        {
            return dp[m][k][i][flag];
        }

        long long ans = 0, powX = 1;
        const int x = nums[i];
        for (int f = 0; f <= m; f++)
        {
            long long perm = C[m][f] * powX % mod;

            unsigned newFlag = flag + f;
            unsigned nextFlag = newFlag >> 1;

            bool bitSet = newFlag & 1;

            ans = (ans + perm * dfs(m - f, k - bitSet, i + 1, nextFlag, nums)) % mod;
            powX = (powX * x) % mod;
        }

        return dp[m][k][i][flag] = ans;
    }
    int magicalSum(int m, int k, vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        Pascal();
        this->m = m;
        this->k = k;
        n = nums.size();

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int s = 0; s < n; s++)
                {
                    memset(dp[i][j][s], -1, sizeof(int) * (m + 1));
                }
            }
        }

        return dfs(m, k, 0, 0, nums);
    }
};