// find the number of distinct islands where a group of connected 1s

// Algo-> we take set and put the identical array inside that,  then we get distinct no. of array automatically

// time complexity -> fun-> nx m x log(nxm)->set(insert) + (nxmx4);
// space complexity-> n x m  ;

#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0)
{
    vis[row][col] = 1;
    // pushing the base-col/row to vector

    vec.push_back({row - row0, col - col0});

    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    // going all 4 direction
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // checking condition(not outofbound and not visited and grid[row][col]==1)
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    // fetching row and col
    int n = grid.size();
    int m = grid[0].size();

    // visited 2d array
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // creating Set for island -> to get distinct numbers
    set<vector<pair<int, int>>> st;

    // traversing whole 2d grid

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if not visited island row-col -> then apply DFS

            if (!vis[i][j] and grid[i][j] == 1)
            {
                // we declare vec here as we need fresh array always
                vector<pair<int, int>> vec;
                dfs(i, j, grid, vis, vec, i, j);

                // put the island in SET
                st.insert(vec);
                // cout << st.size() << " -> "
                //      << " i=" << i << " "
                //      << "j=" << j << endl;
            }
        }
    }
    // return size of SET -> distinct island
    return st.size();
}

int main()
{

    // vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};

    cout << countDistinctIslands(grid) << endl;
}
