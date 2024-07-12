#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

class Solution{
    public:
    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &queries) {
        vector<int> result;
    
        // Iterate through each query index
        for (int i = 0; i < q; i++) {
            int countNGE = 0;
            int queryIndex = queries[i];
    
            // Count NGEs to the right of the query index
            for (int j = queryIndex + 1; j < n; j++) {
                if (arr[j] > arr[queryIndex]) {
                    countNGE++;
                }
            }
    
            // Store the result for this query
            result.push_back(countNGE);
        }
    
        return result;
    }
};