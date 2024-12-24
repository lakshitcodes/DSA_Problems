#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int special_idx = -1;
    long long special_val = 0;
    
    // Find special element
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 1 && a[i] != -1) {
            special_idx = i;
            special_val = a[i];
        }
    }
    
    set<long long> sums;
    sums.insert(0); // Empty subarray
    
    if(special_idx == -1) {
        // Only 1s and -1s
        int curr_sum = 0;
        for(int i = 0; i < n; i++) {
            curr_sum += a[i];
            sums.insert(curr_sum);
            
            int temp_sum = curr_sum;
            for(int j = 0; j < i; j++) {
                temp_sum -= a[j];
                sums.insert(temp_sum);
            }
        }
    } else {
        // Process left part
        vector<int> left_sums;
        left_sums.push_back(0);
        int curr_sum = 0;
        for(int i = 0; i < special_idx; i++) {
            curr_sum += a[i];
            left_sums.push_back(curr_sum);
        }
        
        // Process right part
        vector<int> right_sums ;
        right_sums.push_back(0);
        curr_sum = 0;
        for(int i = n-1; i > special_idx; i--) {
            curr_sum += a[i];
            right_sums.push_back(curr_sum);
        }
        
        // Combine all possible sums
        for(int left : left_sums) {
            for(int right : right_sums) {
                // Without special element
                sums.insert(left + right);
                // With special element
                sums.insert(left + special_val + right);
                // Only left + special
                sums.insert(left + special_val);
                // Only special + right
                sums.insert(special_val + right);
            }
        }
        // Special element alone
        sums.insert(special_val);
    }
    
    cout << sums.size() << "\n";
    for(auto &sum : sums) {
        cout << sum << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}