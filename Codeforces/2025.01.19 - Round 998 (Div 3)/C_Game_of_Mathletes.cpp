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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;

        vi arr(n);
        take(arr);

        sort(arr);

        int left=0,right=n-1;
        int score=0;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == k) {
                ++score;
                ++left;
                --right;
            } else if (sum < k) {
                ++left;
            } else {
                --right;
            }
        }
        cout << score << endl;

    }
    return 0;
}