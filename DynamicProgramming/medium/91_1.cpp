#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp

// approach1: DP
// TC - O(n)
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else
            {
                dp[i] = dp[i + 1];
                if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                    dp[i] += dp[i + 2];
            }
        }
        return s.empty() ? 0 : dp[0];
    }
};

// approach2: Memorization
// TC - O(n)
class Solution2
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> memo(n + 1, -1);
        memo[n] = 1;
        return s.empty() ? 0 : numDecodings(0, s, memo);
    }

private:
    int numDecodings(int i, string &s, vector<int> &memo)
    {
        if (memo[i] > -1)
            return memo[i];
        if (s[i] == '0')
            return memo[i] = 0;
        int res = numDecodings(i + 1, s, memo);
        if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) // 10以上の値で'K'~'Z'にdecodeできる場合
            res += numDecodings(i + 2, s, memo);
        return memo[i] = res;
    }
};

// approach3 (TLE): Recursion
// TC - O(2^n)
class Solution3
{
public:
    int numDecodings(string s)
    {
        return s.empty() ? 0 : numDecodings(0, s);
    }

private:
    int numDecodings(int p, string &s)
    {
        int n = s.size();
        if (p == n)
            return 1;
        if (s[p] == '0')
            return 0; // sub string starting with 0 is not a valid encoding
        int res = numDecodings(p + 1, s);
        if (p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7')))
            res += numDecodings(p + 2, s);
        return res;
    }
};

int main()
{
    Solution2 sol;
    string s = "226";
    cout << sol.numDecodings(s) << endl;
}