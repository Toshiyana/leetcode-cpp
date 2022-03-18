#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// use sort function in stdl.
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }

        return anagrams;
    }
};

// use my sort
// this sort can be used when strs contains only lower-case alphabets
class Solution2
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
            mp[strSort(s)].push_back(s);

        vector<vector<string>> anagrams;
        for (auto p : mp)
            anagrams.push_back(p.second);

        return anagrams;
    }

private:
    string strSort(string str)
    {
        string t;
        int counter[26] = {0};
        for (char c : str)
            counter[c - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            t += string(counter[i], i + 'a'); // 文字数couter[c], 全ての要素をc+'a'で初期化
        }

        return t;
    }
};

int main()
{
    Solution sol;
    Solution2 sol2;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // print2dVector(sol.groupAnagrams(strs));
    print2dVector(sol2.groupAnagrams(strs));
}
