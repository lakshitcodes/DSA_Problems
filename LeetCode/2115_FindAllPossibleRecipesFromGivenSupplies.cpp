#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-all-possible-recipes-from-supplies/

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int newMade=0;
            unordered_set<string> inventory(supplies.begin(),supplies.end());
            vector<string> ans;
            for(int i=0;i<recipes.size();i++){
                bool valid=true;
                for(auto &s : ingredients[i]){
                    if(inventory.find(s)==inventory.end()){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    ans.push_back(recipes[i]);
                    inventory.insert(recipes[i]);
                    newMade++;
                }
            }
            while(newMade!=0){
                newMade=0;
                for(int i=0;i<recipes.size();i++){
                    if(inventory.find(recipes[i])==inventory.end()){
                        bool valid=true;
                        for(auto &s : ingredients[i]){
                            if(inventory.find(s)==inventory.end()){
                                valid=false;
                                break;
                            }
                        }
                        if(valid){
                            ans.push_back(recipes[i]);
                            inventory.insert(recipes[i]);
                            newMade++;
                        }
                    }
                }
            }
            return ans;
        }
    };