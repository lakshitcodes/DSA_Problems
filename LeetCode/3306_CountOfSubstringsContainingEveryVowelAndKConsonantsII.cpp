#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/

class Solution {
    public:
        bool isVowel(char s){
            return s=='a' || s=='e' || s=='i' || s=='o' || s=='u';
        }
        long long countK(string word, int k) {
            long long ans=0;
            int n=word.length();
            int cons=0;
            int left=0;
            int a=0,e=0,i=0,o=0,u=0;
            for(int right=0;right<n;right++){
                a+=word[right]=='a';
                e+=word[right]=='e';
                i+=word[right]=='i';
                o+=word[right]=='o';
                u+=word[right]=='u';
                if(!isVowel(word[right])){
                    cons++;
                }
                while(cons>=k && a && e && i && o && u){
                    ans+=n-right;
                    a-=word[left]=='a';
                    e-=word[left]=='e';
                    i-=word[left]=='i';
                    o-=word[left]=='o';
                    u-=word[left]=='u';
                    if(!isVowel(word[left])){
                        cons--;
                    }
                    left++;
                }
            }
            return ans;
        }
        long long countOfSubstrings(string word,int k){
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            return countK(word,k)-countK(word,k+1);
        }
    };