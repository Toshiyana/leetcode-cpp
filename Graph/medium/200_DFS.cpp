#include <bits/stdc++.h>

using namespace std;

void print2dVector(vector<vector<char>> vec)
{
    int height = vec.size();
    int width = vec[0].size();

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

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int h = grid.size(), w = grid[0].size(), num = 0;
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (grid[y][x] == '1')
                {
                    num++;
                    eraseIslands(grid, y, x);
                    // print2dVector(grid);
                }
            }
        }
        return num;
    }

private:
    void eraseIslands(vector<vector<char>> &grid, int y, int x)
    {
        int h = grid.size(), w = grid[0].size();
        if (y < 0 || y == h || x < 0 || x == w || grid[y][x] == '0')
            return;

        grid[y][x] = '0';
        // print2dVector(grid);
        eraseIslands(grid, y - 1, x);
        eraseIslands(grid, y + 1, x);
        eraseIslands(grid, y, x - 1);
        eraseIslands(grid, y, x + 1);
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << sol.numIslands(grid) << endl;
}