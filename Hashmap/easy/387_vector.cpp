#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> res(26); // the number of alphabet "a~z" is 26.

        for (int i = 0; i < s.size(); i++)
            res[s[i] - 'a']++;

        for (int i = 0; i < s.size(); i++)
        {
            if (res[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    // string s = "loveleetcode";
    string s = "aabb";

    cout << sol.firstUniqChar(s) << endl;
}