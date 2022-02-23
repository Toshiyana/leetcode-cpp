#include <bits/stdc++.h>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

// Approach1: Brute Force

// Complexity Analysis
// Time complexity : O(n). We scan all the numbers from 1 to n.
// Space complexity : O(1). No extra space is used.

// class Solution
// {
// public:
//     int guessNumber(int n)
//     {
//         for (int i = 1; i < n; i++)
//         {
//             if (guess(i) == 0)
//                 return i;
//         }
//         return n;
//     }
// };

// Approach2: Binary Search

// Complexity Analysis
// Time complexity : O\big(\log_2 n\big). Binary Search is used.
// Space complexity : O(1). No extra space is used.

class Solution
{
public:
    int guessNumber(int n)
    {
        int s = 1, e = n, mid, res;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            res = guess(mid); // reservation
            if (res == 0)
                return mid;
            else if (res < 0)
            {
                // n <= mid
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
};

// Approach3: Tenary Search

// class Solution
// {
// public:
//     int guessNumber(int n)
//     {
//         int s = 1, e = n, mid1, mid2, res1, res2;
//         while (s <= e)
//         {
//             mid1 = s + (e - s) / 2;
//             mid2 = s - (e - s) / 2;

//             res1 = guess(mid1);
//             res2 = guess(mid2);

//             if (res1 == 0)
//                 return mid1;
//             if (res2 == 0)
//                 return mid2;
//             else if (res1 < 0)
//             {
//                 // n <= mid1
//                 e = mid1 - 1;
//             }
//             else if (res2 > 0)
//             {
//                 // n > mid2
//                 s = mid2 + 1;
//             }
//             else
//             {
//                 // mid1 < n <= mid2
//                 s = mid1 + 1;
//                 e = mid2 - 1;
//             }
//         }
//         return -1;
//     }
// };

int main()
{
    Solution sol;
}