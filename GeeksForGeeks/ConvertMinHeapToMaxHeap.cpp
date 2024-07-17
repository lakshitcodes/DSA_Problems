#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

class Solution
{
public:
    void downHeapify(vector<int> &arr, int N, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < N && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            downHeapify(arr, N, largest);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        // Start from the last non-leaf node and heapify each node
        for (int i = (N / 2) - 1; i >= 0; i--)
        {
            downHeapify(arr, N, i);
        }
    }
};