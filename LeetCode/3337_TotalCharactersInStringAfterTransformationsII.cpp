#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/total-characters-in-string-after-transformations-ii//

class Solution {
public:
    using Matrix = vector<vector<long long>>;
    const int MOD = 1e9 + 7;
    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }
    Matrix matrixExpo(Matrix base, int exp) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            result[i][i] = 1;
        }
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp /= 2;
        }
        return result;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> mp(26, 0);
        for (char c : s) {
            mp[c - 'a']++;
        }
        Matrix transform(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                transform[(i + j) % 26][i]++;
            }
        }
        Matrix poweredTransform = matrixExpo(transform, t);
        vector<long long> ans(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans[i] = (ans[i] + poweredTransform[i][j] * mp[j]) % MOD;
            }
        }
        long long sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum = (sum + ans[i]) % MOD;
        }
        return static_cast<int>(sum);
    }
};