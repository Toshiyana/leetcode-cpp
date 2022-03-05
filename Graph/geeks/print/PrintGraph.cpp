// A simple reporesentation of graph using STL
#include <bits/stdc++.h>

using namespace std;

// A utility function to add an edge in an undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            cout << "->" << x;
        printf("\n");
    }
}

int main()
{
    int V = 5; // the number of nodes
    vector<int> adj[V];

    // according to addEdge(), don't have to call addEdge(adj, 1, 0) if you called addEdge(adj, 0, 1)
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    addEdge(adj, 2, 3);

    addEdge(adj, 3, 4);

    printGraph(adj, V);

    // cout << adj[0][0] << endl; // 1
    // cout << adj[1][0] << endl; // 0

    // cout << adj[0][1] << endl; // 4
    // cout << adj[4][0] << endl; // 0
}