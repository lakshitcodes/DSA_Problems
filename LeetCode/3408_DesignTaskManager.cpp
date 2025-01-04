#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/design-task-manager/

class TaskManager {
public:
    priority_queue<pair<int, int>> pq; // {priority, taskId}
    unordered_map<int, pair<int, int>> mapping; // taskId -> {priority, userId}

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            pq.push({task[2], task[1]}); 
            mapping[task[1]] = {task[2], task[0]}; 
        }
    }

    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mapping[taskId] = {priority, userId};
    }

    void edit(int taskId, int newPriority) {
        if (mapping.find(taskId) != mapping.end()) {
            int userId = mapping[taskId].second;
            pq.push({newPriority, taskId});
            mapping[taskId] = {newPriority, userId};
        }
    }

    void rmv(int taskId) {
        mapping.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (mapping.find(taskId) != mapping.end() && mapping[taskId].first == priority) {
                int userId = mapping[taskId].second;
                mapping.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
