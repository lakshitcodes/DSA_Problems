#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximize-the-minimum-game-score/        

class Solution {
public:
    long long maxScore(vector<int>& pts, int M) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        int n = pts.size();
        if(M < n) return 0;
        // f(v): Checks if we can ensure each gameScore >= v within M moves.
        auto f = [&](long long v) -> bool {
            long long tot = 0, tr = 0, skip = 0;
            for (int i = 0; i < n && tot <= M; i++) {
                int p = pts[i];
                // Required moves = ⌈v / p⌉ (using integer math)
                long long need = (v + p - 1) / p;
                if (tr >= need) {
                    tr = 0; 
                    skip++; // Free move from previous overkill
                } else {
                    long long cur = tr * p;  
                    long long ops = (v - cur + p - 1) / p; // extra ops needed
                    tot += 2 * ops - 1 + skip;  // cost: go and return, plus free moves
                    tr = max(ops - 1, 0LL);
                    skip = 0;
                }
            }
            return tot <= M;
        };
        long long lo = 1, hi = 1e18, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (f(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};