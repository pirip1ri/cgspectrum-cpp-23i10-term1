#include <iostream>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;

    // Function to add a link to the graph
    void addLink(int v, int w);

    // DFS traversal to neighbouring nodes w of the vertices reachable from starting node v
    void DFS(int v);
};

int main() 
{
    // Create a graph given in the above diagram
    Graph g;
    g.addLink(0, 1);
    g.addLink(0, 2);
    g.addLink(2, 0);
    g.addLink(1, 2);
    g.addLink(2, 3);
    g.addLink(3, 4);
    g.addLink(2, 5);
    g.addLink(5, 6);
    g.addLink(2, 6);
    g.addLink(6, 5);

    cout << "Following is Depth First Traversal (starting from vertex 2)" << endl;

    // Function call for a DFS
    g.DFS(2);
}

void Graph::addLink(int v, int w)
{
    // Here, adj[v] accesses the adjacency list for vertex v, and push_back(w) adds vertex w to that list, indicating that there is an edge from vertex v to vertex w.
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and output that value on the console
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex. If the value has not been visited, the DFS function will repeat, and print out that 'neighbour' value
    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor);
        }
    }
}