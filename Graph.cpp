#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> // not support char and string type yet
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
            try
            {
                if (i >= _size || i < 0)
                    throw i;

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

            catch (long long _i)
            {
                cout << "OutOfRangeError: Can't access index '" << _i << "' by brackets index[..] is out of list range";
                exit(0);
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
    List *begin()
    {
        return &Heads[0];
    }

    List *end()
    {
        return &Heads[n];
    }

    void addEdge(T from, T to) // O(1)
    {
        try
        {
            if (from >= n || from < 0)
                throw from;

            Heads[from].add(to);
        }

        catch (T _from)
        {
            cout << "OutOfRangeError: In function 'addEdge', Index '" << _from << "' is out of graph range";
            exit(0);
        }
    }

    long long size()
    {
        return n;
    }

    List &operator[](long long i)
    {
        try
        {
            if (i >= n || i < 0)
                throw i;

            return Heads[i];
        }

        catch (long long _i)
        {
            cout << "OutOfRangeError: Can't access index '" << _i << "' by brackets index[..] is out of graph range";
            exit(0);
        }
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

    // print Graph using for range for(:)
    cout << "Graph : Adjacency List\n";
    for (auto node : g)
    {
        for (auto child : node)
            cout << child << ' ';
        cout << '\n';
    }
}