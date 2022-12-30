#include <bits/stdc++.h>

using namespace std;

int rotten(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int cntFresh = 0;
    int visited[n][m];
    queue<pair<pair<int, int>, int>> q;
    // traversing whole grid to get count of rotten and non rotten oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 2)
            {
                // mark visited and push to queue
                visited[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                visited[i][j] = 0;
            }
            if (grid[i][j] == 1)
            {

                cntFresh++;
            }
        }
    }
    //---------- now we apply bfs-------------------------

    int time = 0;

    // we use delta to check all 4 direction
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    // counting the converted oranges
    int cnt = 0;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and visited[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                cnt++;
                visited[nrow][ncol] = 2;
            }
        }
    }
    if (cnt != cntFresh)
    {
        return -1;
    }
    return time;
}

int main()
{
    vector<vector<int>> grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    int ans = rotten(grid);
    cout << ans << endl;
    // return 0;
}