
// space complexity- recusion stack space O(n) + visited array O(n)

// time complexity- O(n+2E)-> dfs traversal + O(n) -> for loop
// TC -> O(n+2E) + O(n);

// algo-> go recursively each node and hunt for visited and not parent then we get ans

#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;
    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj) == true)
            {
                return true;
            }
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = isCycle(4, adj);
    if (ans)
    {
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}