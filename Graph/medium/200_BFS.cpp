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
        vector<int> offsets = {0, 1, 0, -1, 0};
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (grid[y][x] == '1')
                {
                    num++;
                    grid[y][x] = '0';

                    queue<pair<int, int>> todo;
                    todo.push({y, x});
                    // cout << todo.front().first << ", " << todo.front().second << endl;

                    while (!todo.empty())
                    {
                        pair<int, int> p = todo.front();
                        todo.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int i = p.first + offsets[k], j = p.second + offsets[k + 1];
                            if (i >= 0 && i < h && j >= 0 && j < w && grid[i][j] == '1')
                            {
                                grid[i][j] = '0';
                                todo.push({i, j});
                            }
                        }
                    }
                }
            }
        }
        return num;
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