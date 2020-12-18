#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    int n = 5;
    Graph<int> g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(3, 2);

    auto top = g.getTopologicalSort();
    if (top.size() > 0)
    {
        cout <<"The Topological Sort is:\n";
        for (auto i : top)
            cout << i << ' ';
    }
    else
        cout <<"There is No Graph";
    
    /*
         0
       /   \
      1     4
       \   /
         3
         |
         2

    topological sort: 0 4 1 3 2   
    */
}
