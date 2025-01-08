#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

class Solution {
public:
    bool isValid(string a,string b){
        if(a.length()>b.length()){
            return false;
        }
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        int n=b.length();
        int m=a.length();
        for(int i=0;i<m;i++){
            if(a[i]!=b[n-m+i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                count+=isValid(words[i],words[j]);
            }
        }
        return count;
    }
};