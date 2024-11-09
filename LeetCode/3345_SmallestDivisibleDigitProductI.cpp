#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/smallest-divisible-digit-product-i/

class Solution {
public:
    int productOfDigits(int num) {
        int product = 1;
        while (num > 0) {
            int digit = num % 10;
            product *= digit;
            num /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        while (true) {
            if (productOfDigits(n) % t == 0) {
                return n;
            }
            n++;
        }
        return 1;
    }
};