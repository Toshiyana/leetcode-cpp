#include <bits/stdc++.h>

using namespace std;

// Function to print permutations of string
// This function takes three parameters
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string

// Algorithm Paradigm: Backtracking

// Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.

// Auxiliary Space: O(r – l)

// Note: The above solution prints duplicate permutations if there are repeating characters in the input string.
// Please see the below link for a solution that prints only distinct permutations even if there are duplicates in input

void permute(string a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r);

            // backtrack
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string s = "ABC";
    // string s = "AAB"; // include duplicates
    permute(s, 0, s.size() - 1);
}