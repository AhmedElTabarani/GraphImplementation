#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    int n = 8;
    Graph<int> g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.addEdge(5, 6);
    g.addEdge(2, 7);

    // get number of components
    cout <<"number of  componemts is: "<< g.countConnectedComponents() <<'\n';
    auto arr = g.getNodeColors();
    // get color of all node
    for (int i = 0; i < n; ++i)
        cout << i << " -> " << arr[i] << '\n';

    if (arr[0] == arr[5]) // useful to check if two nodes in the same component
        cout << "nodes: 0, 5 are in the same Component\n";
    else
        cout << "nodes: 0, 5 are not in the same Component\n";

    // get path from 0 to 3 (shorties path)
    auto path = g.getPath(0, 3);
    if (path.size() > 0)
    {
        cout << "The Shorties Path between 0, 3 is:\n";
        for (auto i : path)
            cout << i << ' ';
    }
    else
        cout << "There is No Path";
}