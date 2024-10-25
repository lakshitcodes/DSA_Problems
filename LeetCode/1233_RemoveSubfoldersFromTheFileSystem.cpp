#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution {
public:
    class folder{
        public:
        unordered_map<string,folder*> subfolder;
        bool isEnd;
        folder(){
            isEnd=false;
        }   
        void insert(string structure){
            folder* curr = this;
            string dir="";
            for(auto ch : structure){
                if(ch=='/'){
                    if(!dir.empty()){
                        if(curr->subfolder.find(dir)==curr->subfolder.end()){
                            curr->subfolder[dir]=new folder();
                        }
                        curr=curr->subfolder[dir];
                        dir.clear();
                    }
                }
                else{
                    dir+=ch;
                }
            }
            if(!dir.empty()){
                        if(curr->subfolder.find(dir)==curr->subfolder.end()){
                            curr->subfolder[dir]=new folder();
                        }
                        curr=curr->subfolder[dir];
                    }
            curr->isEnd=true;
        }
    };
    void findAns(folder* root,string path,vector<string> &result){
        if(root->isEnd){
            result.push_back(path);
            return;
        }
        for(auto dir : root->subfolder){
            findAns(dir.second,path+"/"+dir.first,result);
        }
    }
    vector<string> removeSubfolders(vector<string>& directories) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        folder* root = new folder();
        for(auto &i : directories){
            root->insert(i);
        }
        vector<string> result;
        findAns(root,"",result);
        return result;
    }
};