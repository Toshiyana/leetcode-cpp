#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.size() == 0)
            return false;

        unordered_set<string> dict;
        for (string w : wordDict)
            dict.insert(w);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (dict.find(word) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};

int main()
{
    Solution sol;
}