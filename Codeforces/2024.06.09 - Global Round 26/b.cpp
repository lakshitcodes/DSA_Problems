#include <iostream>
#include <string>
using namespace std;

/* B. Large Addition
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A digit is large if it is between 5 and 9, inclusive. A positive integer is large if all of its digits are large.

You are given an integer x. Can it be the sum of two large positive integers with the same number of digits?

Input
The first line contains a single integer t
 (1≤t≤104) — the number of test cases.

The only line of each test case contains a single integer x
 (10≤x≤1018).

Output
For each test case, output YES
 if x satisfies the condition, and NO
 otherwise. */

// Function to check if a given string is valid
void checkString()
{
    string input;
    cin >> input;
    bool isValid = true;

    // Check if the first character is '1'
    if (input[0] != '1')
    {
        isValid = false; // If not, the string is not valid
    }
    else
    {
        // Iterate over the characters of the string starting from index 1
        for (int index = 1; index < input.size(); ++index)
        {
            if (index != input.size() - 1)
            {
                // For characters in the middle of the string (excluding the last character)
                // Check if the character is '0'
                if (input[index] == '0')
                {
                    isValid = false; // If '0' is found, the string is not valid
                    break;
                }
            }
            else
            {
                // For the last character of the string
                // Check if it is greater than '8'
                if (input[index] > '8')
                {
                    isValid = false; // If greater than '8', the string is not valid
                    break;
                }
            }
        }
    }

    // Output the result based on the validity of the string
    if (isValid)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        checkString(); // Process each test case
    }
    return 0;
}
