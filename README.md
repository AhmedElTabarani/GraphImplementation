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
    // Create object from graph with size n and type int
    // You can use only Numerical types
    Graph<int> graph(n);

    // To add an edge
    graph.addEdge(0, 1); // O(1)
    // or
    graph[1].add(2); // O(1)
    
    // You can use for range
    cout <<"Print Graph :  Adjacency List\n";
    for(auto node : graph){
        for(auto child : graph[node]) // operator[] is O(1)
            cout << child <<' ';
        cout <<'\n';
    }
    // To get number of components
    cout << graph.countConnectedComponents() <<'\n';
    
    // To get color of nodes
    auto arr = graph.getNodeColors(); // it returns array


    if (arr[0] == arr[5]) // useful to check if two nodes in the same component, O(1)
        cout << "Nodes: 0, 5 are in the same Component\n";
    else
        cout << "Nodes: 0, 5 are not in the same Component\n";

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
    
    path.clear() // To clear list
```

## What is Next ?

* ### Functions
  * **Longies Path between Two Nodes** *`// Path and Distance`*
  * **Weighting Graph**
  * **Maze(Grid)** 
