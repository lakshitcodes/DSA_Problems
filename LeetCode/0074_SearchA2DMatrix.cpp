#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int low = 0;
        int high = matrix.size() - 1;
        int last = matrix[0].size() - 1;
        int current = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][last])
            {
                current = mid;
                break;
            }
            else if (target < matrix[mid][0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (current == -1)
        {
            return false;
        }

        low = 0;
        high = last;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target == matrix[current][mid])
            {
                return true;
            }
            else if (target < matrix[current][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};

// In a single traversal
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int m=matrix.size();
            int n=matrix[0].size();
            int low=0,high=m*n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                int row=mid/n,col=mid%n;
                if(matrix[row][col]==target){
                    return true;
                }
                if(matrix[row][col]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }  
            return false;
        }
    };