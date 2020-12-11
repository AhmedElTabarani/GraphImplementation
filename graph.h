#include <iostream>
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

                if (!visited[child])
                {
                    visited[child] = true;
                    que.add(child);
                    parent[child] = node;
                }
            }
            if (isThere)
                break;
        }
        List path;
        if (isThere)
        {
            T tmp = to;
            long long i = n;
            while (tmp != -1)
            {
                List.add(tmp);
                tmp = parent[tmp];
            }
        }
        return path.begin();
    }
    ~Graph()
    {
        delete[] Heads;
    }
};