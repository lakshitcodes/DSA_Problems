#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution {
public:
    int findCount(string curr,string s){
        int count=0;
        for(int i=0;i<s.length()-curr.length()+1;i++){
            bool valid=true;
            for(int j=0;j<curr.length();j++){
                if(curr[j]!=s[i+j]){
                    valid=false;
                    break;
                }
            }
            count+=valid;
        }
        cout<<curr<<" "<<count<<endl;
        return count;
    }
    int maximumLength(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans=-1;
        for(int i=0;i<s.length();i++){
            string curr="";
            unordered_set<char> st;
            for(int j=i;j<s.length();j++){
                curr+=s[j];
                st.insert(s[j]);
                if(st.size()==1 && findCount(curr,s)>=3){
                    ans=max(ans,j-i+1);
                }
                if(st.size()>1){
                    break;
                }
            }
        }
        return ans==0 ? -1 : ans;
    }
};