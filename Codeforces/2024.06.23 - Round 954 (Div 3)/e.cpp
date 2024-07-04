#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
using namespace std;

/*
E. Beautiful Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array of integers a1,a2,…,an and an integer k. You need to make it beautiful with the least amount of operations.
Before applying operations, you can shuffle the array elements as you like. For one operation, you can do the following:

Choose an index 1≤i≤n,Make ai=ai+k.
The array b1,b2,…,bn is beautiful if bi=bn−i+1 for all 1≤i≤n.

Find the minimum number of operations needed to make the array beautiful, or report that it is impossible.

Input
Each test consists of several sets of input data. The first line contains a single integer t (1≤t≤104) — the number of sets of input data. Then follows their description.

The first line of each set of input data contains two integers n and k (1≤n≤105, 1≤k≤109) — the size of the array a and the number k from the problem statement.

The second line of each set of input data contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.

It is guaranteed that the sum of n over all sets of input data does not exceed 2⋅105.

Output
For each set of input data, output the minimum number of operations needed to make the array beautiful, or −1 if it is impossible.
*/

using VecLL = vector<long long>;

void processTestCase(int caseNumber)
{
    long long n, k;
    cin >> n >> k;
    VecLL array(n);

    for (auto &element : array)
        cin >> element;

    map<long long, set<long long>> remainderGroups;

    for (long long number : array)
    {
        if (remainderGroups[number % k].find(number) != remainderGroups[number % k].end())
        {
            remainderGroups[number % k].erase(number);
        }
        else
        {
            remainderGroups[number % k].insert(number);
        }
    }

    long long oddGroupCount = 0, oddRemainder = -1;

    for (auto &group : remainderGroups)
    {
        long long groupSize = group.second.size();
        if (groupSize % 2 != 0)
        {
            oddGroupCount++;
            oddRemainder = group.first;
        }
    }

    if (oddGroupCount > 1)
    {
        cout << -1 << endl;
        return;
    }

    long long totalCost = 0;

    for (auto &group : remainderGroups)
    {
        if (group.first == oddRemainder)
            continue;
        while (!group.second.empty())
        {
            long long first = *group.second.begin();
            group.second.erase(first);
            if (group.second.empty())
                break;
            long long second = *group.second.begin();
            group.second.erase(second);
            totalCost += (second - first) / k;
        }
    }

    if (oddGroupCount)
    {
        VecLL oddGroupValues;
        for (long long value : remainderGroups[oddRemainder])
            oddGroupValues.push_back(value);

        long long oddGroupSize = oddGroupValues.size();
        if (oddGroupSize == 1)
        {
            cout << totalCost << endl;
            return;
        }

        VecLL prefixSum(oddGroupSize, 0), suffixSum(oddGroupSize, 0);
        prefixSum[1] = oddGroupValues[1] - oddGroupValues[0];
        for (long long i = 3; i < oddGroupSize; i += 2)
        {
            prefixSum[i] = oddGroupValues[i] - oddGroupValues[i - 1] + prefixSum[i - 2];
        }

        suffixSum[oddGroupSize - 2] = oddGroupValues[oddGroupSize - 1] - oddGroupValues[oddGroupSize - 2];
        for (long long i = oddGroupSize - 4; i >= 0; i -= 2)
        {
            suffixSum[i] = oddGroupValues[i + 1] - oddGroupValues[i] + suffixSum[i + 2];
        }

        long long minAdditionalCost = LLONG_MAX;
        for (long long i = 0; i < oddGroupSize; i += 2)
        {
            long long additionalCost = 0;
            if (i > 0)
                additionalCost += prefixSum[i - 1];
            if (i + 1 < oddGroupSize)
                additionalCost += suffixSum[i + 1];
            minAdditionalCost = min(minAdditionalCost, additionalCost);
        }

        totalCost += minAdditionalCost / k;
    }

    cout << totalCost << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        processTestCase(i);
    }

    return 0;
}
