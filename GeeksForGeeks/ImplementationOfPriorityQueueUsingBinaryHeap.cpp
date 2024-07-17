#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1

// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution
{
public:
    int extractMax()
    {
        if (s == -1)
        {
            return -1;
        }

        int result = H[0];

        H[0] = H[s];
        s = s - 1;

        shiftDown(0);

        return result;
    }
};