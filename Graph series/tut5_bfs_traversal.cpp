

// we use Queue Data Structure -> FIFO -> first in first out

// Time complexity -> whileloop runs N times + for loop run for total degree

// V = number of nodes

// Time complexity = O(V) + O(2E);
// Space Complexity = O(V)-> at worst case we need to hold all vertices in the queue

#include <bits/stdc++.h>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // visited array
    int vis[V] = {0};
    // first node visited
    vis[0] = 1;

    // create queue and push 1st node
    queue<int> q;
    q.push(0);

    // creating bfs array
    vector<int> bfs;

    // while queue is not empty
    while (!q.empty())
    {
        // storing front of queue in node
        int node = q.front();

        // poping front
        q.pop();

        // pushing node(front)
        bfs.push_back(node);

        // checking the visited in adj-list

        // adj is vector of arrays

        // adj[1] = {2,3,4}
        // adj[2] = {3,4,6}
        // adj[3] = {5,6,8}

        // adj-> 1 2 3 4 5 6 7 8 9

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
}
