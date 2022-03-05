// Print DFS traversal from a given vertex in a given graph
#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=lbp

// Solution:
// This will happen by handling a corner case.
// The above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex, as in a Disconnected graph. To do a complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS.
// The recursive function remains the same.

// Algorithm:
// Create a recursive function that takes the index of the node and a visited array.
// Mark the current node as visited and print the node.
// Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
// Run a loop from 0 to the number of vertices and check if the node is unvisited in the previous DFS, call the recursive function with the current node.

// Complexity Analysis:
// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), since an extra visited array of size V is required.

// Graph class represents a directed graph
// using adjacency list.
class Graph
{

    // A function used by DFS
    void DFSUtil(int v);

public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the verticles reachable from v
    void DFS();

    void printDirectedGraph(map<int, list<int>> adj);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    // cout << v << " ";
    cout << v << "=>";

    // Recur for all the verticles adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // cout << *i << " ";
        if (!visited[*i])
        {
            DFSUtil(*i);
        }
    }
}

void Graph::DFS()
{
    for (auto i : adj)
    {
        if (!visited[i.first])
            DFSUtil(i.first);
    }
}

void Graph::printDirectedGraph(map<int, list<int>> adj)
{
    for (auto &x : adj)
    {
        cout << x.first << "=>";

        list<int>::iterator i;
        for (i = x.second.begin(); i != x.second.end(); i++)
            cout << *i << " ";

        cout << endl;
    }
}

int main()
{
    // Input: n = 4, e = 6
    // 0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    // g.printDirectedGraph(g.adj);
    g.DFS();
}