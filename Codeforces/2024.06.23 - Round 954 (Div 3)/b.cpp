#include <bits/stdc++.h>
using namespace std;
/*
B. Matrix Stabilization
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a matrix of size n×m, where the rows are numbered from 1 to n from top to bottom, and the columns are numbered from 1 to m from left to right.
The element at the intersection of the i-th row and the j-th column is denoted by aij.

Consider the algorithm for stabilizing matrix a:

Find the cell (i,j) such that its value is strictly greater than the values of all its neighboring cells. If there is no such cell, terminate the algorithm. If there are multiple such cells, choose the cell with the smallest value of i
, and if there are still multiple cells, choose the one with the smallest value of j.
Set aij=aij−1.
Go to step 1.In this problem, cells (a,b) and (c,d) are considered neighbors if they share a common side, i.e., |a−c|+|b−d|=1.

Your task is to output the matrix a after the stabilization algorithm has been executed. It can be shown that this algorithm cannot run for an infinite number of iterations.

Input
Each test consists of multiple sets of input data. The first line contains a single integer t (1≤t≤104) — the number of sets of input data. This is followed by their description.

The first line of each set of input data contains two integers n and m (1≤n,m≤100,n⋅m>1) — the number of rows and columns of matrix a.

The next n lines describe the corresponding rows of the matrix. The i-th line contains m integers ai1,ai2,…,aim (1≤aij≤109).

It is guaranteed that the sum of n⋅m over all sets of input data does not exceed 2⋅105.

Output
For each set of input data, output n lines with m numbers in each line — the values of the cells of matrix a after the stabilization algorithm.*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool isMax = true;

                if (i + 1 < m && matrix[i][j] <= matrix[i + 1][j])
                {
                    isMax = false;
                }
                if (j + 1 < n && matrix[i][j] <= matrix[i][j + 1])
                {
                    isMax = false;
                }
                if (i - 1 >= 0 && matrix[i][j] <= matrix[i - 1][j])
                {
                    isMax = false;
                }
                if (j - 1 >= 0 && matrix[i][j] <= matrix[i][j - 1])
                {
                    isMax = false;
                }

                if (isMax)
                {
                    int a = 0;
                    if (i + 1 < m)
                    {
                        a = max(a, matrix[i + 1][j]);
                    }
                    if (j + 1 < n)
                    {
                        a = max(a, matrix[i][j + 1]);
                    }
                    if (i - 1 >= 0)
                    {
                        a = max(a, matrix[i - 1][j]);
                    }
                    if (j - 1 >= 0)
                    {
                        a = max(a, matrix[i][j - 1]);
                    }
                    matrix[i][j] = a;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
