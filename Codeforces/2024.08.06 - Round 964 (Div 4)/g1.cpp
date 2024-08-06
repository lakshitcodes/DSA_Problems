#include <bits/stdc++.h>
using namespace std;

/*
G1. Ruler (easy version)
time limit per test1 second
memory limit per test256 megabytes
This is the easy version of the problem. The only difference between the two versions is that in this version, you can make at most 10 queries.

This is an interactive problem. If you are unsure how interactive problems work, then it is recommended to read the guide for participants.

We have a secret ruler that is missing one number x (2≤x≤999). When you measure an object of length y, the ruler reports the following values:

If y<x, the ruler (correctly) measures the object as having length y.
If y≥x, the ruler incorrectly measures the object as having length y+1.

The ruler above is missing the number 4, so it correctly measures the first segment as length 3 but incorrectly measures the second segment as length 6 even though it is actually 5.

You need to find the value of x. To do that, you can make queries of the following form:

? a b
 — in response, we will measure the side lengths of an a×b rectangle with our ruler and multiply the results, reporting the measured area of the rectangle back to you. For example, if x=4
 and you query a 3×5 rectangle, we will measure its side lengths as 3×6 and report 18 back to you.Find the value of x. You can ask at most 10 queries.

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤1000) — the number of test cases.

Interaction
There is no initial input for each test case. You should begin the interaction by asking a query.

To make a query, output a single line of the form ? a b (1≤a,b≤1000). In response, you will be told the measured area of the rectangle, according to our secret ruler.

When you are ready to print the answer, output a single line of the form ! x (2≤x≤999). After that, proceed to process the next test case or terminate the program if it was the last test case. Printing the answer does not count as a query.

The interactor is not adaptive, meaning that the answer is known before the participant asks the queries and doesn't depend on the queries asked by the participant.

If your program makes more than 10 queries for one set of input data, makes an invalid query, or prints the wrong value of x, then the response to the query will be −1. After receiving such a response, your program should immediately terminate to receive the verdict Wrong Answer. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you may get Idleness limit exceeded verdict. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
Hacks

To make a hack, use the following format.

The first line should contain a single integer t (1≤t≤1000) — the number of test cases.

The only line of each test case should contain a single integer x (2≤x≤999) — the missing number on the ruler.
*/

#define ll long long
#define flush cout.flush()

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l = 2, r = 999;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            cout << "? " << m << " " << m << endl;
            flush;

            ll reported_area;
            cin >> reported_area;

            ll expected_area = (ll)m * m;

            if (reported_area == expected_area)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << "! " << l << endl;
        flush;
    }

    return 0;
}
