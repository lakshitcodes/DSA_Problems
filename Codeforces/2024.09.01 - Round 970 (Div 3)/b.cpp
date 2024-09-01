#include <bits/stdc++.h>
using namespace std;

/*
B. Square or Not
time limit per test2 seconds
memory limit per test256 megabytes
A beautiful binary matrix is a matrix that has ones on its edges and zeros inside.

Examples of four beautiful binary matrices.
Today, Sakurako was playing with a beautiful binary matrix of size r×c and created a binary string s by writing down all the rows of the matrix, starting from the first and ending with the r-th. More formally, the element from the matrix in the i-th row and j-th column corresponds to the ((i−1)∗c+j)-th element of the string.

You need to check whether the beautiful matrix from which the string s was obtained could be squared. In other words, you need to check whether the string s could have been build from a square beautiful binary matrix (i.e., one where r=c).

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the length of the string.

The second line of each test case contains the string s of length n. The string is always the result of writing out the strings of a beautiful matrix.

It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

Output
Print "Yes", if the original matrix could have been square, and "No" otherwise.
*/

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int root = sqrt(n);
        if (root * root != n)
        {
            cout << "No" << endl;
            continue;
        }
        int k = root;
        bool isBeautiful = true;
        for (int i = 0; i < k && isBeautiful; ++i)
        {
            if (s[i] != '1' || s[n - k + i] != '1')
            {
                isBeautiful = false;
                break;
            }
            if (s[i * k] != '1' || s[i * k + (k - 1)] != '1')
            {
                isBeautiful = false;
                break;
            }
        }
        if (isBeautiful)
        {
            for (int i = 1; i < k - 1 && isBeautiful; ++i)
            {
                for (int j = 1; j < k - 1; ++j)
                {
                    int index = i * k + j;
                    if (s[index] != '0')
                    {
                        isBeautiful = false;
                        break;
                    }
                }
            }
        }

        if (isBeautiful)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}