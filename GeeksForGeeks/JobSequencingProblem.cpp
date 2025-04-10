#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
    public:
      vector<int> parent;
  
      // Find with path compression
      int find(int x) {
          if (parent[x] == x) return x;
          return parent[x] = find(parent[x]);
      }
  
      // Union
      void merge(int u, int v) {
          parent[u] = v;
      }
  
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          int n = deadline.size();
          int maxDeadline = 0;
          vector<pair<int,int>> task;
  
          for (int i = 0; i < n; i++) {
              task.emplace_back(profit[i], deadline[i]);
              maxDeadline = max(maxDeadline, deadline[i]);
          }
  
          // Sort jobs by descending profit
          sort(task.begin(), task.end(), greater<>());
  
          // Initialize DSU
          parent.resize(maxDeadline + 1);
          for (int i = 0; i <= maxDeadline; i++) {
              parent[i] = i;
          }
  
          int totalJobs = 0;
          int totalProfit = 0;
  
          for (int i = 0; i < n; i++) {
              int availableSlot = find(task[i].second);
              if (availableSlot > 0) {
                  totalJobs++;
                  totalProfit += task[i].first;
                  // Mark this slot as used
                  merge(availableSlot, availableSlot - 1);
              }
          }
  
          return {totalJobs, totalProfit};
      }
  };