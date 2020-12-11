#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    Graph<int> g(nodes);

    int from, to;
    while (edges--)
    {
        cin >> from >> to;

        // add in O(1)
        g.addEdge(from, to);
        g.addEdge(to, from); // for undirected graph

        // add in o(1)
        //	g[from].add(to);
        //	g[to].add(from);	// for undirected graph
    }

    // print Graph
    cout << "Graph : Adjacency List\n";
    for (int node = 0; node < g.size(); ++node)
    {
        cout << node << " -> ";
        for (int child = 0; child < g[node].size(); ++child)
            cout << g[node][child] << ' '; // access child by brackets index [child] is O(n) (will be improvement)
        cout << '\n';
    }

    cout << '\n';

    cout << "Graph : Adjacency List\n";
    for (auto node : g)
    {
        for (auto child : node)
            cout << child << ' ';
        cout << '\n';
    } 
}