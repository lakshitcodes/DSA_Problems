#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reconstruct-itinerary/description/

class Solution
{
public:
    void dfs(string &source, unordered_map<string, vector<string>> &graph, vector<string> &itinerary)
    {
        while (!graph[source].empty())
        {
            string next = graph[source].back();
            graph[source].pop_back();
            dfs(next, graph, itinerary);
        }
        itinerary.push_back(source);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string, vector<string>> graph;
        for (auto &ticket : tickets)
        {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for (auto &[source, destinations] : graph)
        {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> itinerary;
        string source = "JFK";
        dfs(source, graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};