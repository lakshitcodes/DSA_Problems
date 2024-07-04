#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i != 0)
        {
            if (nums[i - 1] > nums[i])
            {
                ans += nums[i - 1] - nums[i];
                nums[i] = nums[i - 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}