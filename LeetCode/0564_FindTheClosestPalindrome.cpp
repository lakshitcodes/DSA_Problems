#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-the-closest-palindrome/

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long number = stoll(n);
        if (number <= 10)
        {
            return to_string(number - 1);
        }
        if (number == 11)
            return "9";

        long long nearestPalindrome = 0;
        long long minDiff = LLONG_MAX;

        int size = n.length();
        int i = 0;
        int j = size - 1;

        // Copying the left portion to the right
        string currNum = n;
        while (i < j)
        {
            currNum[j--] = currNum[i++];
        }
        long long currPalindrome = stoll(currNum);
        if (abs(currPalindrome - number) < minDiff)
        {
            minDiff = abs(currPalindrome - number);
            nearestPalindrome = currPalindrome;
        }
        else if (abs(currPalindrome - number) == minDiff &&
                 currPalindrome < nearestPalindrome)
        {
            nearestPalindrome = currPalindrome;
        }

        if (minDiff == 0)
        {
            minDiff = LLONG_MAX;
        }

        // Decrementing the central number
        currNum = n;
        i = 0, j = size - 1;
        int mid = (i + j) / 2;
        if (currNum[mid] == '0')
        {
            currNum[mid] = '9';
            // Taking Borrow
            for (int k = mid - 1; k >= 0; --k)
            {
                if (currNum[k] == '0')
                {
                    currNum[k] = '9';
                }
                else
                {
                    currNum[k] -= 1;
                    break;
                }
            }
        }
        else
        {
            currNum[mid] -= 1;
        }
        while (i < j)
        {
            currNum[j--] = currNum[i++];
        }
        currPalindrome = stoll(currNum);
        if (abs(currPalindrome - number) < minDiff)
        {
            minDiff = abs(currPalindrome - number);
            nearestPalindrome = currPalindrome;
        }
        else if (abs(currPalindrome - number) == minDiff &&
                 currPalindrome < nearestPalindrome)
        {
            nearestPalindrome = currPalindrome;
        }

        // Incrementing the central number
        currNum = n;
        i = 0, j = size - 1;
        mid = (i + j) / 2;
        if (currNum[mid] == '9')
        {
            currNum[mid] = '0';
            // Carry case
            for (int k = mid - 1; k >= 0; --k)
            {
                if (currNum[k] == '9')
                {
                    currNum[k] = '0';
                }
                else
                {
                    currNum[k] += 1;
                    break;
                }
            }
            // If all are zero
            if (currNum[0] == '0')
            {
                currNum = "1" + currNum;
            }
        }
        else
        {
            currNum[mid] += 1;
        }
        while (i < j)
        {
            currNum[j--] = currNum[i++];
        }
        currPalindrome = stoll(currNum);
        if (abs(currPalindrome - number) < minDiff)
        {
            minDiff = abs(currPalindrome - number);
            nearestPalindrome = currPalindrome;
        }
        else if (abs(currPalindrome - number) == minDiff &&
                 currPalindrome < nearestPalindrome)
        {
            nearestPalindrome = currPalindrome;
        }

        // All nines
        currPalindrome = pow(10, size - 1) - 1;
        if (abs(currPalindrome - number) < minDiff)
        {
            minDiff = abs(currPalindrome - number);
            nearestPalindrome = currPalindrome;
        }
        else if (abs(currPalindrome - number) == minDiff &&
                 currPalindrome < nearestPalindrome)
        {
            nearestPalindrome = currPalindrome;
        }

        // Combination of 1's and 0's
        currPalindrome = pow(10, size) + 1;
        if (abs(currPalindrome - number) < minDiff)
        {
            minDiff = abs(currPalindrome - number);
            nearestPalindrome = currPalindrome;
        }
        else if (abs(currPalindrome - number) == minDiff &&
                 currPalindrome < nearestPalindrome)
        {
            nearestPalindrome = currPalindrome;
        }

        return to_string(nearestPalindrome);
    }
};
