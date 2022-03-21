#include <bits/stdc++.h>

using namespace std;

/ https : // leetcode.com/problems/max-area-of-island/discuss/108533/JavaC%2B%2B-Straightforward-dfs-solution

          class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int h = grid.size(), w = grid[0].size();
        int maxNum = 0;

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (grid[y][x] == 1)
                    maxNum = max(maxNum, AreaOfIsland(grid, y, x));
            }
        }
        return maxNum;
    }

private:
    int AreaOfIsland(vector<vector<int>> &grid, int y, int x)
    {
        int h = grid.size(), w = grid[0].size();
        if (y >= 0 && y < h && x >= 0 && x < w && grid[y][x] == 1)
        {
            grid[y][x] = 0;
            return 1 + AreaOfIsland(grid, y - 1, x) + AreaOfIsland(grid, y + 1, x) + AreaOfIsland(grid, y, x - 1) + AreaOfIsland(grid, y, x + 1);
        }
        return 0;
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