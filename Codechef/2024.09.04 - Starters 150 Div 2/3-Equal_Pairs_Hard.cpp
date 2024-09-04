#include <iostream>
#include <vector>
#include <unordered_map>

// Question Link : https://www.codechef.com/START150B/problems/MAXEQUAL

using namespace std;

class Solution
{
private:
    int n;
    vector<int> arr;
    unordered_map<int, int> freq;
    long long pairs = 0;
    int zeros = 0;
    int maxFreq = 0;

    void update(int x, int y)
    {
        int oldValue = arr[x];

        if (oldValue != 0)
        {
            freq[oldValue]--;
            pairs -= freq[oldValue];
            if (freq[oldValue] == 0)
                freq.erase(oldValue);
            if (freq[oldValue] == maxFreq - 1)
            {
                maxFreq--;
            }
        }
        else
        {
            zeros--;
        }

        arr[x] = y;

        if (y != 0)
        {
            pairs += freq[y];
            freq[y]++;
            if (freq[y] > maxFreq)
            {
                maxFreq = freq[y];
            }
        }
        else
        {
            zeros++;
        }
    }

    long long calculate_f()
    {
        long long max_pairs = pairs;
        if (zeros > 0)
        {
            max_pairs += (long long)zeros * maxFreq;
            max_pairs += (long long)zeros * (zeros - 1) / 2;
        }
        return max_pairs;
    }

public:
    vector<long long> solve(int N, vector<pair<int, int>> &queries)
    {
        n = N;
        arr.assign(n, 0);
        zeros = n;
        freq.clear();
        pairs = 0;
        maxFreq = 0;

        vector<long long> results;

        for (const auto &query : queries)
        {
            int x = query.first - 1;
            int y = query.second;
            update(x, y);
            results.push_back(calculate_f());
        }

        return results;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> queries(N);
        for (int i = 0; i < N; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }

        Solution sol;
        vector<long long> results = sol.solve(N, queries);

        for (long long result : results)
        {
            cout << result << " ";
        }
        cout << "\n";
    }

    return 0;
}
