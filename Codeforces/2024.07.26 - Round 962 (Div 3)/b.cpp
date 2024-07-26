#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
B. Scale
time limit per test2 seconds
memory limit per test256 megabytes
Tina has a square grid with n rows and n columns. Each cell in the grid is either 0 or 1.

Tina wants to reduce the grid by a factor of k (k is a divisor of n). To do this, Tina splits the grid into k×k
 nonoverlapping blocks of cells such that every cell belongs to exactly one block.
Tina then replaces each block of cells with a single cell equal to the value of the cells in the block. It is guaranteed that every cell in the same block has the same value.

For example, the following demonstration shows a grid being reduced by factor of 3.

Original grid
000111000
111000111
111000111
000111000
Reduced grid
01
10
Help Tina reduce the grid by a factor of k.

InputThe first line contains t (1≤t≤100) – the number of test cases.

The first line of each test case contains two integers n and k (1≤n≤1000, 1≤k≤n, k is a divisor of n) — the number of rows and columns of the grid, and the factor that Tina wants to reduce the grid by.

Each of the following n lines contain n characters describing the cells of the grid. Each character is either 0 or 1. It is guaranteed every k by k block has the same value.

It is guaranteed the sum of n over all test cases does not exceed 1000.

Output
For each test case, output the grid reduced by a factor of k on a new line.
*/

vector<string> reduceGrid(int n, int k, const vector<string> &grid)
{
    int reducedGridSize = n / k;
    vector<string> reducedGrid(reducedGridSize);

    for (int blockRow = 0; blockRow < n; blockRow += k)
    {
        string reducedRow;
        for (int blockCol = 0; blockCol < n; blockCol += k)
        {
            char blockValue = grid[blockRow][blockCol];
            reducedRow += blockValue;
        }

        reducedGrid[blockRow / k] = reducedRow;
    }

    return reducedGrid;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }

        vector<string> reducedGrid = reduceGrid(n, k, grid);
        for (const string &row : reducedGrid)
        {
            cout << row << endl;
        }
    }

    return 0;
}
