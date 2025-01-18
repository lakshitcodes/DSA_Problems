#include<bits/stdc++.h>
using namespace std;

bool comparator(int a, int b, const vector<string>& graph) {
    return graph[a - 1][b - 1] == '1'; 
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin>>n;
        vector<string>adj(n);
        vector<int>ans(n); 
        for(int i=0;i<n;i++){
            cin>>adj[i];
        }
        iota(ans.begin(), ans.end(), 0); 
        sort(ans.begin(), ans.end(), [&](int u, int v) { 
        if(u<v) { 
        return adj[u][v]=='1'; 
        } 
        return adj[v][u]=='0'; 
        }); 
        for (int i = 0; i < n; i++) { 
        cout << ans[i] +1<<" "; 
        } 
        cout<<endl;
    }

    return 0;
}
