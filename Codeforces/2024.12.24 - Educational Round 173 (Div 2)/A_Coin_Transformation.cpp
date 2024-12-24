#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a,b) map<a,b>
#define set(a,b) set<a,b>
#define sort(arr) sort(arr.begin(),arr.end())
#define sum(arr) accumulate(arr.begin(),arr.end(),0LL)
#define take(arr) for(auto &i : arr) cin>>i;

long long maxCoins(long long n, unordered_map<long long, long long>& memo) {
    if (n <= 3) {
        return 1;
    }
    if (memo.count(n)) {
        return memo[n]; 
    }
    long long splitValue = (n) / 4;
    memo[n] = 2 * maxCoins(splitValue, memo); 
    return memo[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        unordered_map<long long, long long> memo;
        cout << maxCoins(n, memo) << endl;
    }
    return 0;
}