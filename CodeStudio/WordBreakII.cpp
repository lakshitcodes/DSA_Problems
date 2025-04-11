#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.naukri.com/code360/problems/983635

void solve(string curr,int start,string s,unordered_set<string> &dict,vector<string> &ans){
    if(start==s.length()){
        ans.push_back(curr);
        return;
    }
    for(int end=start;end<s.length();end++){
        string temp=s.substr(start,end-start+1);
        if(dict.count(temp)){
            string dupli=curr;
            if(!dupli.empty()){
                dupli+=' ';
            }
            solve(dupli+temp,end+1,s,dict,ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<string> ans;
    unordered_set<string> dict(dictionary.begin(),dictionary.end());
    solve("",0,s,dict,ans);
    return ans;
}