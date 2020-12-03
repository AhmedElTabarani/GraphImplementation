#include<iostream>
using namespace std;

template<typename T>
class List{
	struct Node{
		T info;
    	Node* next;
    	Node(T val):info(val), next(NULL){}
	};
	
    Node* head = NULL;
    Node* tail = NULL;
    public:
        void add(T);
        void printList();
};
template<typename T>
void List<T>::add(T val){
    Node* temp = new Node(val);
    
    if(!head){
    	head = temp;
    	tail = temp;
    	return;
    }
    
    tail->next = temp;
    tail = temp;
}
template<typename T>
void List<T>::printList(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->info <<' ';
        temp = temp->next;
    }
}

template<typename T>
class Graph{
	long long n; // Number of nodes
	List<T> *Heads; // Adjacency List
	
	
	public:
		Graph(long long nodes):n(nodes){
			Heads = new List<T> [nodes]; // create Adjacency List
		}
		
		void addEdge(T from, T to){
			Heads[from].add(to);
		}
		
		void showGraph(){
			cout << "Graph : Adjacency List " << '\n';
			for(int node = 0; node < n; ++node){
    			cout << node <<" -> ";
        		Heads[node].printList();
        		
        	cout << '\n';
    		}
		}
};

int main(){
	int nodes, edges;
	cin >> nodes >> edges;
	Graph<int> g(nodes + 1);
	
	int from, to;
	while(edges--){
		cin >> from >> to;
		
		g.addEdge(from, to);
		g.addEdge(to, from); // for undirected graph
	}
	
	 // print Graph
	 g.showGraph();
    
}