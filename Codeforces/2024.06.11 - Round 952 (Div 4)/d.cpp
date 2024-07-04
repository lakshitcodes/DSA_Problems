#include <bits/stdc++.h>
using namespace std;

/*
D. Manhattan Circle
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given a n by m grid consisting of '.' and '#' characters, there exists a whole manhattan circle on the grid. The top left corner of the grid has coordinates (1,1), and the bottom right corner has coordinates (n,m).

Point (a,b) belongs to the manhattan circle centered at (h,k) if |h−a|+|k−b|<r, where r is a positive constant.

On the grid, the set of points that are part of the manhattan circle is marked as '#'. Find the coordinates of the center of the circle.

InputThe first line contains t (1≤t≤1000)  — the number of test cases.

The first line of each test case contains n and m (1≤n⋅m≤2⋅105) — the height and width of the grid, respectively.

The next n lines contains m characters '.' or '#'. If the character is '#', then the point is part of the manhattan circle.

It is guaranteed the sum of n⋅m over all test cases does not exceed 2⋅105, and there is a whole manhattan circle on the grid.

Output
For each test case, output the two integers, the coordinates of the center of the circle.*/
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int maxCount = 0;
        int rowCount = 0;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '#')
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                rowCount = i;
            }
        }
        int startInd = -1, endInd = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[rowCount][i] == '#')
            {
                if (startInd == -1)
                {
                    startInd = i;
                }
                endInd = i;
            }
        }
        int colCount = (startInd + endInd) / 2;
        cout << rowCount + 1 << " " << colCount + 1 << endl;
    }
    return 0;
}