#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &num)
    {
        vector<vector<int>> result;

        permuteRecursive(num, 0, result);

        return result;
    }

private:
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result)
    {
        if (begin == num.size() - 1)
        {
            result.push_back(num);
            return;
        }
        for (int i = begin; i < num.size(); i++)
        {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            swap(num[begin], num[i]); // backtrack
        }
    }
};

void print2dVector(vector<vector<int>> vec)
{
    int height = vec.size();
    int width = vec[0].size();

    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;

    cout << endl;

    cout << "{" << endl;

    for (int y = 0; y < height; y++)
    {
        cout << "   { ";
        for (int x = 0; x < width; x++)
        {
            cout << vec[y][x];
            if (x == (width - 1))
                cout << " ";
            else
                cout << ", ";
        }
        cout << "}," << endl;
    }

    cout << "}" << endl;
}

int main()
{
    Solution sol;
    vector<int> vec = {0, 1, 2};

    print2dVector(sol.permute(vec));
}