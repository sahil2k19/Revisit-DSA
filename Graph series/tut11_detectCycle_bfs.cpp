
// time complexity -> O ( N + 2E ) -> vertices(node) + summation of all degree of Node
// space complexity -> O(n)

// Main Algo-> using bfs we start from Point 1-> and go to both adjacent part 2 and 3 .....and we take both parent and Node with us ....

// suppose 2 go clockwise
// and 3 go anticlockwise

// if a node is visited and that Node is not our parent then the GRAPH is cycle

// if both collide then we have a Cycle

//       2 _ 5
//       /    \
//       1      7
//         \   /
//          3-6

// Note in above case suppose 7 is visited by clockwise first and when anticlockwise try to visit it ... it shown visited already then it is cycle

#include <bits/stdc++.h>

using namespace std;

// this function will only check if the graph create a cycle
bool detect(int src, vector<int> adj[], int vis[])
{
    // src -> where it initially start (root);
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    // applying BFS
    while (!q.empty()) //-> v
    {
        // geting node and parents
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // traversing all adjacent Node
        for (auto adjacentNode : adj[node]) // v*adjacent_node
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
    }
    return false;
}

// generalise way to check connected or non connected components of graph

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        // not visited
        if (!vis[i])
        {
            if (detect(i, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};

    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}