#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs
{
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto &i : nums2)
        {
            mp[i]++;
        }
    }

    void add(int index, int val)
    {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
    }

    int count(int tot)
    {
        int ans = 0;
        for (auto &i : nums1)
        {
            if (mp.count(tot - i))
            {
                ans += mp[tot - i];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */