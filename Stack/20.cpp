#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/discuss/728304/C%2B%2B-Easiest-solution-fully-Explained-takes-0ms-beats-100-49

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.empty() || (st.top() == '(' && c != ')') || (st.top() == '{' && c != '}') || (st.top() == '[' && c != ']'))
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution sol;
    // string s = "()[]{}"; // true
    // string s = "(([]{}))"; // true
    string s = "({)}"; // false

    cout << sol.isValid(s) << endl;
}