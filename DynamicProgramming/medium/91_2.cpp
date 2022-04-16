#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// easier to understand than 91_1.cpp
// https://leetcode.com/problems/decode-ways/discuss/30358/Java-clean-DP-solution-with-explanation

// algorithm
// * use a dp array of size (n+1) to save subproblem solutions.
// * dp[0] means that empty string will have one way to decode.
// * dp[1] means the way to decode a string of size (1).
// * then check one digit and two digit combination and save the results along the way.
// * In the end, dp[n] will be the end result;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 0)
            return 0;

        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++)
        {
            int first = stoi(s.substr(i - 1, 1));
            int second = stoi(s.substr(i - 2, 2));
            if (first >= 1 && first <= 9)
                dp[i] += dp[i - 1];

            if (second >= 10 && second <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
}