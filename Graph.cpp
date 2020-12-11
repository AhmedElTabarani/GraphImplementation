#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    int n = 4;
    Graph<int> g(n);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    
    auto path =  g.isTherePath(0, 3);

    for(auto i : path)
        cout << i <<' ';
}