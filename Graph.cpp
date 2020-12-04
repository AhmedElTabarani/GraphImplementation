#include <iostream>
using namespace std;

template <typename T>
class List
{
    struct Node
    {
        T info;
        Node *next;
        Node(T val) : info(val), next(NULL) {}
    };
    long long _size = 0;
    Node *head = NULL;
    Node *tail = NULL;

public:
    void add(T val) // add to tail, O(1)
    {
        ++_size;
        Node *temp = new Node(val);

        if (!head)
        {
            head = temp;
            tail = temp;
            return;
        }

        tail->next = temp;
        tail = temp;
    }

    long long size()
    {
        return _size;
    }
    void printList() // may be deleted
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->info << ' ';
            temp = temp->next;
        }
    }

    T &operator[](long long i) // O(n), Needs improvement and optimization (will be changed)
    {
        Node *temp = head;
        long long cnt = 0;
        while (temp != NULL)
        {
            if (cnt == i)
                return temp->info;

            ++cnt;
            temp = temp->next;
        }
    }
};

template <typename T>
class Graph
{
    long long n;    // Number of nodes
    List<T> *Heads; // Adjacency List
public:
    Graph(long long nodes) : n(nodes)
    {
        Heads = new List<T>[nodes]; // create Adjacency List
    }

    // functions to handle for(:)
    // Needs some test cases
    List<T> *begin()
    {
        return &Heads[0];
    }
    List<T> *end()
    {
        return &Heads[n];
    }

    friend List<T> *begin(Graph<T> &g)
    {
        return &g.Heads[0];
    }
    friend List<T> *end(Graph<T> &g)
    {
        return &g.Heads[g.n];
    }
    List<T> &operator++()
    {
    }

    // add edge, may be deleted
    void addEdge(T from, T to)
    {
        Heads[from].add(to);
    }

    long long size()
    {
        return n;
    }

    List<T> &operator[](long long i)
    {
        return Heads[i];
    }

    ~Graph()
    {
        delete[] Heads;
    }
};

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    Graph<int> g(nodes);

    int from, to;
    while (edges--)
    {
        cin >> from >> to;

        g[from].add(to);
        g[to].add(from);
        //g.addEdge(from, to);
        //g.addEdge(to, from); // for undirected graph
    }

    // print Graph
    cout << "Graph : Adjacency List\n";
    for (int i = 0; i < g.size(); ++i)
    {
        cout << i << " -> ";
        for (int j = 0; j < g[i].size(); ++j)
            cout << g[i][j] << ' ';
        cout << '\n';
    }
    /**/
}