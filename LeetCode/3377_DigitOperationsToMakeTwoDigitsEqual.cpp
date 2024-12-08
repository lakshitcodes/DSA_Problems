#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/digit-operations-to-make-two-digits-equal/

class Solution {
public:
    vector<bool> computePrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false; 
    
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    int minimumCost(int n, int m, const vector<bool>& isPrime) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unordered_set<int> visited;
        
        pq.push({n, n}); // {cost, number}
    
        while (!pq.empty()) {
            auto [cost, current] = pq.top();
            pq.pop();
    
            if (visited.count(current)) continue;
            visited.insert(current);
    
            if (current == m) return cost;
    
            string numStr = to_string(current);
            int numDigits = numStr.size();
    
            for (int i = 0; i < numDigits; i++) {
                char original = numStr[i];
    
                if (original < '9') {
                    numStr[i] = original + 1;
                    int newNumber = stoi(numStr);
                    if (!isPrime[newNumber] && !visited.count(newNumber)) {
                        pq.push({cost + newNumber, newNumber});
                    }
                }
    
                numStr[i] = original;
                if (original > '0') {
                    numStr[i] = original - 1;
                    int newNumber = stoi(numStr);
                    if (!isPrime[newNumber] && !visited.count(newNumber)) {
                        pq.push({cost + newNumber, newNumber});
                    }
                }
    
                numStr[i] = original;
            }
        }
        return -1;
    }
    int minOperations(int n, int m) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<bool> isPrime = computePrimes(9999);
        if (isPrime[n] || isPrime[m]) return -1;
        return minimumCost(n, m, isPrime);
    }
};