#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    // member
    int val;
    vector<Node *> neighbors;

    // constructor
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// To clone a graph, you will need to traverse it.
// Both BFS and DFS are for this purpose.
// To clone a graph, you need to have a copy of each node and avoid copying the same node
// for multiple times.
// So you need a mapping from an original node to its copy.

// BFS
// Runtime: 9 ms, faster than 48.73% of C++ online submissions for Clone Graph.
// Memory Usage: 8.5 MB, less than 93.98% of C++ online submissions for Clone Graph.
class Solution2
{
private:
    unordered_map<Node *, Node *> orig2copy;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        orig2copy[node] = new Node(node->val);
        queue<Node *> todo;
        todo.push(node);

        while (!todo.empty())
        {
            Node *cur = todo.front();
            todo.pop();

            for (Node *neighbor : cur->neighbors)
            {
                if (orig2copy.find(neighbor) == orig2copy.end()) // stil not copy neighbor
                {
                    orig2copy[neighbor] = new Node(neighbor->val); // make copy, neighbor is stil not connected with cur
                    todo.push(neighbor);
                }
                orig2copy[cur]->neighbors.push_back(orig2copy[neighbor]); // neighbor is connected with cur
            }
        }
        return orig2copy[node];
    }
};
// DFS
// Runtime: 11 ms, faster than 36.18% of C++ online submissions for Clone Graph.
// Memory Usage: 8.8 MB, less than 48.08% of C++ online submissions for Clone Graph.
class Solution
{
private:
    unordered_map<Node *, Node *> orig2copy; // key: *original node, value: *copy node>

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        if (orig2copy.find(node) == orig2copy.end()) // not found the node
        {
            orig2copy[node] = new Node(node->val);
            for (Node *neighbor : node->neighbors) // traverse adjacecy nodes using recuring (DFS)
                orig2copy[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return orig2copy[node];
    }
};

int main()
{
}