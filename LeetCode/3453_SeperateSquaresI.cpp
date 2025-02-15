#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/separate-squares-i/

class Solution {
    public:
        class comparator {
        public:
            bool operator()(pair<int, int> &a, pair<int, int> &b) {
                return a.first == b.first ? a.second > b.second : a.first < b.first;
            }
        };
    
        double separateSquares(vector<vector<int>> &squares) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<pair<int, int>> sq;
            double totalArea = 0;
            
            double left = 0.0,right=0.0;
            for (auto &i : squares) {
                sq.push_back({i[1], i[1] + i[2]});
                left=min(left,(double)i[1]);
                right=max(right,(double)i[1]+i[2]);
                totalArea += (double)((double)i[2] * (double)i[2]);
            }
            // cout<<totalArea<<endl;
            sort(sq.begin(), sq.end(), comparator());
            int n = sq.size();
            
            while (right - left > 1e-6) {
                double mid = (left + right) / 2.0;
                double F_mid = findArea(mid, sq);
                // cout<<left<<" "<<right<<" "<<F_mid<<endl;
                if (F_mid >= totalArea / 2.0) 
                    right = mid;
                else 
                    left = mid;
            }
    
            return left;
        }
    
        double findArea(double mid, vector<pair<int, int>> &sq) {
            double area = 0;
            for (auto &i : sq) {
                double bottom = i.first;
                double top = i.second;
                double side = top - bottom;
    
                if (bottom >= mid) continue;
                if (top > mid) top = mid;
    
                area += (top - bottom) * side;
            }
            return area;
        }
    };
    