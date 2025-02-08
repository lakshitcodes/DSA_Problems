#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/design-a-number-container-system

class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> indexes;
    unordered_map<int,int> mp;
    NumberContainers() {
        // do nothing
    }
    
    void change(int index, int number) {
        indexes[number].push(index);
        mp[index]=number;
    }
    
    int find(int number) {
        if(indexes.find(number)==indexes.end()){
            return -1;
        }

        while(!indexes[number].empty() && mp[indexes[number].top()]!=number){
            indexes[number].pop();
        }
        if(indexes[number].empty()){
            indexes.erase(number);
            return -1;
        }
        return indexes[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */