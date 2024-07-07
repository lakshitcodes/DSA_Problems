#include <iostream>
#include <vector>
using namespace std;

// Question Link : https://codeforces.com/contest/1983/problem/B

/*
B. Corner Twist
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two grids of numbers a and b, with n rows and m columns. All the values in the grid are 0, 1 or 2.

You can perform the following operation on a any number of times:

Pick any subrectangle in the grid with length and width ≥2. You are allowed to choose the entire grid as a subrectangle.The subrectangle has four corners. Take any pair of diagonally opposite corners of the chosen subrectangle and add 1 to their values modulo 3.
For the pair of corners not picked, add 2 to their values modulo 3.
Note that the operation only changes the values of the corners of the picked subrectangle.

Is it possible to convert the grid a into grid b by applying the above operation any number of times (possibly zero)?
Input
The first line contains an integer t, the number of testcases (1≤t≤250).

For each testcase:

The first line contains two integers n and m, the number of rows and columns in the grid (2≤n,m≤500).

Each of the next n lines contain m characters — the j-th character of the i-th line represents ai,j.

Each of the next n lines contain m characters — the j-th character of the i-th line represents bi,j (0≤ai,j,bi,j≤2).

It is guaranteed that the sum of n over all test cases and the sum of m over all test cases do not exceed 500.

Output
For each test case print "YES" (without quotes) if it is possible to convert grid a into grid b and "NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/

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

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char temp;
                cin >> temp;
                a[i][j] = temp - '0';
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char temp;
                cin >> temp;
                b[i][j] = temp - '0';
            }
        }

        bool possible = true;
        vector<int> rowDiff(n, 0), colDiff(m, 0);
        for (int i = 0; i < n; ++i)
        {
            int rowSum = 0;
            for (int j = 0; j < m; ++j)
            {
                rowSum += (b[i][j] - a[i][j] + 3) % 3;
            }
            rowDiff[i] = rowSum % 3;
        }

        for (int j = 0; j < m; ++j)
        {
            int colSum = 0;
            for (int i = 0; i < n; ++i)
            {
                colSum += (b[i][j] - a[i][j] + 3) % 3;
            }
            colDiff[j] = colSum % 3;
        }

        for (int i = 0; i < n; ++i)
        {
            if (rowDiff[i] != 0)
            {
                possible = false;
                break;
            }
        }

        for (int j = 0; j < m; ++j)
        {
            if (colDiff[j] != 0)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
