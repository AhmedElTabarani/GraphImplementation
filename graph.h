#include <iostream>
using namespace std;

template <typename T> // not support char and string type
class Graph
{
    class List
    {
        struct Node
        {
            T info;
            Node *next;
            Node(T val, Node *nextPtr = NULL) : info(val), next(nextPtr) {}
        };

        class Iterator
        {
            Node *ptr;

        public:
            Iterator() : ptr(NULL) {}
            Iterator(Node *p) : ptr(p) {}

            Iterator &operator=(Iterator &it)
            {
                return it;
            }

            bool operator!=(Iterator &it)
            {
                return this->ptr != it.ptr;
            } 
            Iterator &operator=(Node * np)
            {   
                this->ptr = np;
                return *this;
            }

            bool operator!=(Node * np)
            {
                return this->ptr != np;
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
        void addFront(T val) // add to head, O(1)
        {
            ++_size;
            Node *tmp = new Node(val, head);
            head = tmp;
        }
        T pop() // need exception
        {
            --_size;
            T val = head->info;
            Node *tmp = head;
            head = head->next;
            delete tmp;

            return val;
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
        void clear()
        {
            Node *curr = head;
            while (curr)
            {
                head = curr->next;
                delete curr;
                curr = head;
            }
            _size = 0;
        }
        ~List()
        {
            clear();
        }
    }; // end list class

    // member data of graph class
    long long n; // Number of nodes
    List *Heads; // Adjacency List

    void dfs(T node, bool *visited, long long *colored = NULL)
    {
        for (auto child : Heads[node])
            if (!visited[child])
            {
                visited[child] = true;
                if (colored != NULL)
                    colored[child] = colored[node];
                dfs(child, visited, colored);

            }
    }
    void dfsTopSort(T node, bool *visited, List & topligicalSort)
    {
        for (auto child : Heads[node])
            if (!visited[child])
            {
                visited[child] = true;
                dfsTopSort(child, visited, topligicalSort);
                topligicalSort.addFront(child);
            }
    }

public:
    Graph(long long nodes = 0) : n(nodes)
    {
        Heads = new List[nodes]; // create Adjacency List
    }
    long long size()
    {
        return n;
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
    long long countConnectedComponents()
    {
        long long cnt = 0;
        bool visited[n];
        for (T node = 0; node < n; ++node)
        {
            if (!visited[node])
            {

                ++cnt;
                visited[node] = true;
                dfs(node, visited);
            }
        }
        return cnt;
    }
    // it maybe return a iterator in future
    List getPath(T from, T to) // Shorties Path
    {
        bool visited[n];
        T parent[n];
        bool isThere = false;
        List que;

        que.add(from);
        visited[from] = true;
        parent[from] = -1;
        T node;
        while (que.size() > 0)
        {
            node = que.pop();
            for (auto child : Heads[node])
            {
                if (to == child)
                {
                    isThere = true;
                    parent[child] = node;
                    break;
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
            while (tmp != -1)
            {
                path.addFront(tmp);
                tmp = parent[tmp];
            }
        }
        return path; // if path.size() == 0 then there is no path
    }
    List getTopligicalSort()
    {
        List topligicalSort;
        bool visited[n];
        for (T node = 0; node < n; ++node)
        {
            if (!visited[node])
            {
                visited[node] = true;
                dfsTopSort(node, visited, topligicalSort);
                topligicalSort.addFront(node);
            }
        }
        return topligicalSort;
    }
    // it maybe return a iterator in future
    // or it will return a List, but after improve operatot[] in list class
    long long *getNodeColors()
    {
        bool visited[n];
        long long *colored = new long long[n];
        long long cnt = -1;
        for (long long node = 0; node < n; ++node)
        {
            if (!visited[node])
            {
                colored[node] = ++cnt;
                visited[node] = true;
                dfs(node, visited, colored);
            }
        }
        return colored;
    }
    ~Graph()
    {
        delete[] Heads;
    }
};