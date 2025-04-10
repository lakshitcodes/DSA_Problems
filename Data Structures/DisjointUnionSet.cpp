#include<bits/stdc++.h>
using namespace std;

class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;  // Tracks the size of each component
    
    public:
        // Constructor to initialize DSU for `n` elements (0 to n)
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);  // Initially, each component has size 1
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
    
        // Find with path compression
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }
    
        // Union by rank and size
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
    
            if (rootX == rootY) return;
    
            // Union by size: attach the smaller tree to the larger tree
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];  // Update the size of rootY
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];  // Update the size of rootX
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];  // Update the size of rootX
            }
        }
    
        // Get the size of the component containing `x`
        int getSize(int x) {
            int rootX = find(x);
            return size[rootX];
        }
    };
    