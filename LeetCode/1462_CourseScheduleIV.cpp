#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<bool>> isRelated(numCourses,vector<bool>(numCourses,false));
        unordered_map<int,vector<int>> adj;
        for(auto &u : prerequisites){
            adj[u[0]].push_back(u[1]);
        }

        for(int i=0;i<numCourses;i++){
            vector<int> visited(numCourses,false);
            queue<int> pq;
            pq.push(i);
            while(!pq.empty()){
                int front = pq.front();
                pq.pop();
                if(visited[front])  continue;
                visited[front]=true;
                isRelated[i][front]=true;
                for(auto &ele : adj[front]){
                    if(!visited[ele]){
                        pq.push(ele);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto &q : queries){
            ans.push_back(isRelated[q[0]][q[1]]);
        }
        return ans;
    }
};