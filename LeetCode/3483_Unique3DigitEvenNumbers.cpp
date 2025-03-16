#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/unique-3-digit-even-numbers/

class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            set<int> numbers;
            for(int i=0;i<digits.size();i++){
                for(int j=0;j<digits.size();j++){
                    for(int k=0;k<digits.size();k++){
                        if(i==j || j==k || k==i){
                            continue;
                        }
                        int num=digits[i]*100 + digits[j]*10 + digits[k];
                        if(num>=100 && num<1000 && num%2==0){
                            cout<<num<<endl;
                            numbers.insert(num);
                        }
                    }
                }
            }
            return numbers.size();
        }
    };