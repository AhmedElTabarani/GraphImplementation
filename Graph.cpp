#include <iostream>
using namespace std;

template <typename T>
class Graph
{
    class List
    {
        struct Node
        {
            T info;
            Node *next;
            Node(T val) : info(val), next(NULL) {}
        };

        class Iterator
        {
            Node *ptr;

        public:
            Iterator(Node *p) : ptr(p) {}

            Iterator &operator=(Iterator &Np)
            {
                return Np;
            }

            bool operator!=(Iterator &it)
            {
                return this->ptr != it.ptr;
            }

            Iterator &operator++()
            {
                if (ptr)
                {
                    ptr = ptr->next;
                    return *this;
                }
            }

            Iterator &operator++(int)
            {
                Iterator it = *this;
                ++(*this);
                return it;
            }

            T operator*()
            {
                return ptr->info;
            }
        };

        // member data of list class
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

        Iterator begin()
        {
            return Iterator(head);
        }

        Iterator end()
        {
            return Iterator(NULL);
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
    }; // end list class

    // member data of graph class
    long long n; // Number of nodes
    List *Heads; // Adjacency List
public:
    Graph(long long nodes) : n(nodes)
    {
        Heads = new List[nodes]; // create Adjacency List
    }

    // functions to handle for(:)
    // Needs some test cases
    List *begin()
    {
        return &Heads[0];
    }

    List *end()
    {
        return &Heads[n];
    }

    friend List *begin(Graph<T> &g)
    {
        return &g.Heads[0];
    }

    friend List *end(Graph<T> &g)
    {
        return &g.Heads[g.n];
    }

    void addEdge(T from, T to) // O(1)
    {
        Heads[from].add(to);
    }

    long long size()
    {
        return n;
    }

    List &operator[](long long i) // need try catch exception (out of the range)
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

        // add in O(1)
        g.addEdge(from, to);
        g.addEdge(to, from); // for undirected graph

        // add in o(n)
        //	g[from].add(to);
        //	g[to].add(from);	// for undirected graph
    }

    // print Graph
    cout << "Graph : Adjacency List\n";
    for (int node = 0; node < g.size(); ++node)
    {
        cout << node << " -> ";
        for (int child = 0; child < g[node].size(); ++child)
            cout << g[node][child] << ' ';
        cout << '\n';
    }

    cout << '\n';

    // print Graph using for range for(:)
    cout << "Graph : Adjacency List\n";
    for (auto node : g)
    {
        for (auto child : node)
            cout << child << ' ';
        cout << '\n';
    }
}