// Print DFS traversal from a given vertex in a given graph
#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=lbp

// Approach:
// Depth-first search is an algorithm for traversing or searching tree or graph data structures.
// The algorithm starts at the root node (selecting some arbitrary node as the root node
// in the case of a graph) and explores as far as possible along each branch before backtracking.
// So the basic idea is to start from the root or any arbitrary node and mark the node and
// move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node.
// Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.

// Algorithm:
// Create a recursive function that takes the index of the node and a visited array.
// 1. Mark the current node as visited and print the node.
// 2. Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.

// Graph class represents a directed graph
// using adjacency list.
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the verticles reachable from v
    void DFS(int v);

    void printDirectedGraph(map<int, list<int>> adj);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    // cout << v << " ";
    cout << v << "=>";

    // Recur for all the verticles adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        cout << *i << " ";
        if (!visited[*i])
        {
            DFS(*i);
        }
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
    int v_start = 1; // start vertex number

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // g.printDirectedGraph(g.adj);
    g.DFS(v_start);
}