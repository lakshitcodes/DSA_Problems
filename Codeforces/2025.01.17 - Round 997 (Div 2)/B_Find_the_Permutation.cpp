#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comparator(int a, int b, const vector<string>& graph) {
    return graph[a - 1][b - 1] == '1'; 
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        vector<string> graph(n);

        for (int i = 0; i < n; i++) {
            cin >> graph[i];
        }

        vector<int> permutation(n);
        for (int i = 0; i < n; i++) {
            permutation[i] = i + 1;
        }
        sort(permutation.begin(), permutation.end(), [&](int a, int b) {
            return comparator(a, b, graph);
        });

        for (int i = n-1; i >=0; i--) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
