#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution
{
public:
    int upperBound(vector<int> &arr, int x, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x)
            {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int m, int n)
    {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int req = (n * m) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, m, n, mid);
            if (smallEqual <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};