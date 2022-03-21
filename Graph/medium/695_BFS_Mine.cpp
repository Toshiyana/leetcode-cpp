#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int h = grid.size(), w = grid[0].size();
        vector<int> offsets = {0, -1, 0, 1, 0};
        int num = 0, maxNum = 0;

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (grid[y][x] == 1)
                {
                    grid[y][x] = 0;
                    num = 1;

                    queue<pair<int, int>> todo;
                    todo.push({y, x});

                    while (!todo.empty())
                    {
                        pair<int, int> p = todo.front();
                        todo.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int i = p.first + offsets[k], j = p.second + offsets[k + 1];
                            if (i >= 0 && i < h && j >= 0 && j < w && grid[i][j] == 1)
                            {
                                grid[i][j] = 0;
                                num++;
                                todo.push({i, j});
                            }
                        }
                    }
                }
                maxNum = max(maxNum, num);
            }
        }
        return maxNum;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    cout << sol.maxAreaOfIsland(grid) << endl;
}