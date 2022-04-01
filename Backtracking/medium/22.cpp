#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generateParenthesis(res, "", n, 0);
        return res;
    }

private:
    void generateParenthesis(vector<string> &res, string str, int l, int r)
    {
        if (r == 0 && l == 0)
        {
            res.push_back(str);
            return;
        }

        if (l > 0)
            generateParenthesis(res, str + "(", l - 1, r + 1);
        if (r > 0)
            generateParenthesis(res, str + ")", l, r - 1);
    }
};

int main()
{
    Solution sol;
    print1dVector(sol.generateParenthesis(2));
}