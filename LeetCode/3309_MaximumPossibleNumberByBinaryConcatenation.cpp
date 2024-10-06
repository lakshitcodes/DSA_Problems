#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/

class Solution {
public:
    string decimalToBinary(int n) {
        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n /= 2;
        }
        return binary;
    }
    int toNum(string binary){
        int decimal = 0;
    int length = binary.length();

    for (int i = 0; i < length; i++) {
        if (binary[length - i - 1] == '1') {
            decimal += pow(2, i);
        }
    }

    return decimal;
    }
    int maxGoodNumber(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<string> binary;
        for(auto i : nums){
            binary.push_back(decimalToBinary(i));
        }
        string a=binary[0]+binary[1]+binary[2];
        string b=binary[0]+binary[2]+binary[1];
        string c=binary[1]+binary[2]+binary[0];
        string d=binary[1]+binary[0]+binary[2];
        string e=binary[2]+binary[0]+binary[1];
        string f=binary[2]+binary[1]+binary[0];
        int ans=max({toNum(a),toNum(b),toNum(c),toNum(d),toNum(e),toNum(f)});
        return ans;
    }
};