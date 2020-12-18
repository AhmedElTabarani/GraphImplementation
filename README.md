# Graph Implementation Project
##### **The Project started on 2020/12/3**

* ### Graph Class:
    * **functions to handle for(:) *`// Needs some test cases`***
      * `begin()`
      * `end()`
    * `addEdge(T from, T to)`
    * `size()`
    * `operator[](index)`
    * `countConnectedComponents()`
    * `getPath(T from, T to) // Shorties Path`
    * `getNodeColors()`
    * `getTopologicalSort()` 
    * ### List Class:
      * **Iterator Class to handle for(:)**
      * `add(val) // add to tail, O(1)`
      * `addFront(val) // add to head, O(1)`
      * `size()`
      * `begin() // return Iterator`
      * `end() // return Iterator`
      * `operator[](index) // O(n), Needs improvement and optimization (will be changed)`

## How is it used ? 
```c++
#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    // Create object from graph with size n and type int
    // You can use only Numerical types
    int n = 5;
    Graph<int> graph(n); // 

    // To add an edge
    graph.addEdge(0, 1); // O(1), or graph[0].add(1) is also O(1)
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(4, 3);
    graph.addEdge(3, 2);
   
   /* Visualization
         0
       /   \
      1     4
       \   /
         3
         |
         2
   */
    // You can use for range
    cout <<"Print Graph :  Adjacency List\n";
    for(int node = 0; node < n; ++node){
        cout << node <<" -> ";
        for(auto child : graph[node]) // operator[] is O(1)
            cout << child <<' ';
        cout <<'\n';
    }
     /// This may cause the program to stop for an unknown reason
     /// We are trying to find the cause in the future
    /* 
     for(auto list : graph){
        for(auto child : list)
            cout << child <<' ';
        cout <<'\n';
    }
   */
    // To get number of components
    cout <<"No. of Components is: " << graph.countConnectedComponents() <<'\n';
    
    // To get color of nodes
    auto arr = graph.getNodeColors(); // it returns array

    if (arr[0] == arr[3]) // useful to check if two nodes in the same component, O(1)
        cout << "Nodes: 0, 3 are in the same Component\n";
    else
        cout << "Nodes: 0, 3 are not in the same Component\n";

    // To get path from 0 to 3 (shorties path)
    auto path = graph.getPath(0, 3); // it returns list
    if (path.size() > 0) // if path.size() is 0 then there is no path between 0, 3
    {
        cout << "The Shorties Path between 0, 3 is:\n";
        for (auto i : path) // you can use for range with list
            cout << i << ' ';
    }
    else
        cout << "There is No Path";
    
    path.clear(); // To clear list
    cout <<'\n';
    // To get Topological Sort
    auto top = graph.getTopologicalSort(); // it returns list
    if (top.size() > 0) // if top.size() is 0 then there is no graph
    {
        cout <<"The Topological Sort is:\n";
        for (auto i : top)
            cout << i << ' ';
    }
    else
        cout <<"There is No Graph";

    top.clear(); // To clear list
}
```
### Output
```
Print Graph :  Adjacency List
0 -> 1 4
1 -> 3
2 ->
3 -> 2
4 -> 3
No. of Components is: 1
Nodes: 0, 3 are in the same Component
The Shorties Path between 0, 3 is:
0 1 3
The Topological Sort is:
0 4 1 3 2
```
## Solve : Romania Map Graph
### From Arad to Bucharest (Unweighted Graph)

```c++
#include <iostream>
#include "graph.h"
using namespace std;

// To store index of each edges
struct Edges{
    int src;
    int dest;
};
int main()
{
    int n = 20, // Number of nodes
        e = 23; // Number of edges

   // Representation the cities in array to use it by index
    string city[n] = {
            "Arad", "Bucharest", "Craiova", "Dobreta", "Eforie", "Fagaras", "Giurglu",
            "Hirsova", "Lasi", "Lugoj", "Mehadia", "Neamt", "Oradea", "Pitesti",
            "RimnicuVilcea", "Sibiu", "Timisoara", "Urziceni", "Vaslui", "Zerind"
        };

    int src = 0, // Index of "Arad"
        dest = 1; // Index of "Bucharest"

   // Edges' Input
    Edges edges[e] = {
            {0, 19}, {0, 15}, {0, 16}, {19, 12}, {12, 15}, {16, 9}, {15, 5}, {15, 14},
            {9, 10}, {5, 1}, {14, 13}, {14, 2}, {10, 3}, {1, 13}, {1, 17}, {1, 6},
            {13, 2}, {2, 3}, {17, 7}, {17, 18}, {7, 4}, {18, 8}, {8, 11}
        }; 
   // Create our graph with size n
    Graph<int> graph(n);
    
   // Store all edges in Graph
    int from, to;
    for (int i = 0; i < e; ++i)
    {
        from = edges[i].src,
        to = edges[i].dest;

        graph[from].add(to); // or graph.addEdge(from, to);
    }
    
    auto path = graph.getPath(src, dest); // To get the  shorties path from src to dest
    cout <<"The Shorties Path from "<< city[src] <<" to "<< city[dest] <<"\nPath: ";
   // Print the Path
    if(path.size() != 0)
        for(auto node : path)
            cout << city[node] <<' ';
   // Print the distance between src ro dest (number of path's edges)
   cout <<"\nDistance is: "<< path.size() - 1 <<'\n';
}
```
### Output
```
The Shorties Path from Arad to Bucharest
Path: Arad Sibiu Fagaras Bucharest
Distance is: 3
```
## What is Next ?

* ### Functions
  * **Longies Path between Two Nodes** *`// Path and Distance`*
  * **Weighting Graph**
    * **Dijkstra's algorithm** *`// Shorties Path`* 
  * **Maze(Grid)** 
