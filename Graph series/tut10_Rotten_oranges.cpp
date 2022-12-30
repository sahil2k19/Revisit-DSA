// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

// Example 1:

// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0)
// will rot oranges at (0,1), (1,1), (2,2) and
// (2,1) in unit time.

// time complexity -> nXm
// space complexity-> nXm

#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // queue-> {{row,colum},time}
    queue<pair<pair<int, int>, int>> q;

    // visited array
    int vis[n][m];
    int cntFresh = 0;

    // traversing the grid and get rotten oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if rotten
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            // if not rotten
            else
            {
                vis[i][j] = 0;
            }
            // count fresh oranges
            if (grid[i][j] == 1)
            {
                cntFresh++;
            }
        }
    }
    int tm = 0;
    // delta row and colum <- ->
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};
    int cnt = 0;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // check for valid cell and
            // then for unvisited fresh oranges
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
            {
                // push in queue with timer increased
                q.push({{nrow, ncol}, t + 1});
                // mark as rotten
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    // if all oranges are not rotten
    if (cnt != cntFresh)
        return -1;
    return tm;
}

int main()
{
    vector<vector<int>> grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    int ans = orangesRotting(grid);
    cout << ans << endl;
    return 0;
}