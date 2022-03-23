#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/376363/CPP-Solution-for-beginners-or-O(n)-time-or-Longest-Substring-without-repeating-characters

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;

        int start = 0, end = 0, n = s.size(), ans = 0;

        while (start < n && end < n)
        {
            cout << "start: " << start << endl;
            cout << "end: " << end << endl;
            printUnorderedSet(set);
            cout << endl;

            if (set.find(s[end]) == set.end()) // If the character does not in the set
            {
                set.insert(s[end++]);        // Insert the character in set and update the j counter
                ans = max(ans, end - start); // Check if the new distance is longer than current answer
            }
            else
            {
                set.erase(s[start++]);
                /*If character does exist in the set, ie. it is a repeated character,
                we update the left side counter i, and continue with the checking for substring. */
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    // s = "abcabcbb"; // 3
    // s = "bbbbb"; // 1
    s = "pwwkew"; // 3

    sol.lengthOfLongestSubstring(s);
}