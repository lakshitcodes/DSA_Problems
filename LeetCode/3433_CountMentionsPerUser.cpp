#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-mentions-per-user/

class Solution {
public:
    static bool comparator(vector<string> &a,vector<string> &b){
        return a[1]==b[1] ? a[0][0]>b[0][0] :stoi(a[1])<stoi(b[1]);
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<long long> offStat(numberOfUsers, 0);
        
        sort(events.begin(), events.end(),comparator);

            
        for (const auto& event : events) {
            long long timestamp = stoll(event[1]);
            
            for (int i = 0; i < numberOfUsers; ++i) {
                if (offStat[i] > 0 && timestamp >= offStat[i]) {
                    online[i] = true;
                    offStat[i] = 0;
                }
            }
            
            if (event[0] == "OFFLINE") {
                int userId = stoi(event[2]);
                online[userId] = false;
                offStat[userId] = timestamp + 60;
            }
            
            if (event[0] == "MESSAGE") {
                unordered_set<int> mentionedUsers;
                istringstream iss(event[2]);
                string token;
                
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentions[i]++;
                    }
                }
                else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (online[i]) {
                            mentions[i]++;
                        }
                    }
                }
                else {
                    while (iss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }
        
        return mentions;
    }
};