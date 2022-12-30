

// Time complexity -> O(n) + (2*E)

// Space complexity - O(n)

#include <bits/stdc++.h>

using namespace std;

//     1
//    / \
//   2    3
//  /\   / \
// 4  5  6   7
// suppost adj_list

// adj[1] = {2,3}
// adj[2] = {1,4,5}
// adj[3] = {1,6,7}
// adj[4] = {2}
// adj[5] = {2}
// adj[6] = {3}
// adj[7] = {3}

// start from 0;
// vector<int> ls  = {1,2,4,5,3,6,7}

void dfs(int node, vector<int> *adj, int *vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    int vis[v] = {0};
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}