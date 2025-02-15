#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/shortest-matching-substring/

class Solution {
    public:
        int shortestMatchingSubstring(string s, string p) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int firstStar = p.find('*');
            int lastStar = p.rfind('*');
    
            string p0 = p.substr(0, firstStar);         
            string p1 = p.substr(firstStar + 1, lastStar - firstStar - 1);
            string p2 = p.substr(lastStar + 1);         
    
            vector<int> prePositions, midPositions, sufPositions;
    
            size_t pos = s.find(p0);
            while (pos != string::npos) {
                prePositions.push_back(pos);
                pos = s.find(p0, pos + 1);
            }
    
            pos = s.find(p1);
            while (pos != string::npos) {
                midPositions.push_back(pos);
                pos = s.find(p1, pos + 1);
            }
    
            pos = s.find(p2);
            while (pos != string::npos) {
                sufPositions.push_back(pos);
                pos = s.find(p2, pos + 1);
            }
    
            if (midPositions.empty() || prePositions.empty()) return -1;
    
            int minLength = INT_MAX;
    
            for (int start : prePositions) {
                int midIdx = lower_bound(midPositions.begin(), midPositions.end(), start + p0.size()) - midPositions.begin();
                if (midIdx == midPositions.size()) continue;
    
                int midStart = midPositions[midIdx];
                int end = midStart + p1.size();
    
                if (p2.empty()) {
                    minLength = min(minLength, end - start);
                    continue;
                }
    
                int sufIdx = lower_bound(sufPositions.begin(), sufPositions.end(), end) - sufPositions.begin();
                if (sufIdx == sufPositions.size()) continue;
    
                int sufStart = sufPositions[sufIdx];
                minLength = min(minLength, (int)sufStart + (int)p2.size() - (int)start);
            }
    
            return (minLength == INT_MAX) ? -1 : minLength;
        }
    };
    