#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-substrings-divisible-by-last-digit/

class Solution {
public:
    long long countSubstrings(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = s.size();
        vector<int> mod3(3), mod9(9), mod7(7), temp7(7);
        int curSum = 0;
        mod3[0] = mod9[0] = mod7[0] = 1;
        int last2 = 0, last3 = 0, sum = 0, curMod7 = 0;
        long long count = 0;
        for(int i = 0; i < n; i++){
            int curDig = s[i]-'0';
            last2 = last2*10 + curDig;
            last3 = last3*10 + curDig;
            if(last2>=100) last2 %= 100;
            if(last3>=1000) last3 %= 1000;
            sum += s[i]-'0';
            for(int j = 0; j < 7; j++){
                temp7[(j*10)%7] = mod7[j];
            }
            mod7 = temp7;
            curMod7 = (curMod7 * 10 + curDig)%7;
            mod7[curMod7]++;
            mod3[sum%3]++;
            mod9[sum%9]++;
            // cout<<count<<" ";
            if(s[i] =='0'){
                // cout<<endl;
                continue;
            }
            else if(s[i] =='7'){
                count += mod7[curMod7]-1;
            }
            else{
                if(s[i] == '1' || s[i] == '2' || s[i] == '5') count += (i+1);
                else if(s[i] == '4'){
                    int chng = 1;
                    if(last2 % 4 == 0) chng += i;
                    count += chng;
                }
                else if(s[i] =='8'){
                    int chng = 1;
                    if(last2%8 == 0) chng++;
                    if(last3%8 == 0) chng += i-1;
                    count += chng;
                }
                else if(s[i] == '9'){
                    count += mod9[sum%9]-1;
                }
                else count += mod3[sum%3]-1;
            }
            // cout<<count<<endl;
        }
        return count;
    }
};