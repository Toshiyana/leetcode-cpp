#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int h = grid.size(), w = grid[0].size(), nums = 0;
        int maxNum = 0;

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (grid[y][x] == 1)
                {
                    int num = 0;
                    countIsland(num, grid, y, x);
                    maxNum = max(maxNum, num);
                }
            }
        }
        return maxNum;
    }

private:
    void countIsland(int &num, vector<vector<int>> &grid, int y, int x)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] == 0)
            return;

        grid[y][x] = 0;
        num++;

        countIsland(num, grid, y - 1, x);
        countIsland(num, grid, y + 1, x);
        countIsland(num, grid, y, x - 1);
        countIsland(num, grid, y, x + 1);
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