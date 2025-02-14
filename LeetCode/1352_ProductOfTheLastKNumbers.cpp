#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
    public:
        vector<int> products;
        ProductOfNumbers() {
            // Do nothing
        }
        
        void add(int num) {
            if(num==0){
                products.clear();
                return;
            }
            if(products.empty()){
                products.push_back(num);
                return;
            }
            products.push_back(products.back()*num);
        }
        
        int getProduct(int k) {
            if(products.size()<k){
                return 0;
            }
            if(products.size()==k){
                return products.back();
            }
            int n=products.size();
            return products[n-1]/products[n-k-1];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */