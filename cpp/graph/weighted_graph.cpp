#include <iostream>
#include <new>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef struct edge {
    int from;
    int to;
    int wt;
} edge_t;

struct CompareEdge : public std::binary_function<edge_t*, edge_t*, bool>                                                                
{
    bool operator()(const edge_t* lhs, const edge_t* rhs) const
    {
        return rhs->wt < lhs->wt;
    }
};

class graph {
    int V; // number of vertices
    list<edge_t *>  *adj; // array of adjacency lists for each vertex
    bool *visited;
    queue<edge_t *> mst;
    priority_queue<edge_t*,vector<edge_t*>, CompareEdge > min_pq;
    queue<edge_t *> kmst;
    
private:
    void visit_node(int node);
public:
    graph(int v);
    ~graph();
    void add_edge(int from, int to, int wt);
    void show_graph();
    void mst_prim();
    void mst_kruskal();
};

graph :: graph(int v) 
{
    V = v;
    adj = new list<edge_t *> [v];
    visited = new bool [V];
    
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }
}

graph :: ~graph() 
{
    list<edge_t *> :: iterator it; 
    for (int i=0; i<V; i++) {
        cout << "\n";
        cout << "Deleting list of adj for node:" << i << " :";
        for (it=adj[i].begin(); it != adj[i].end(); it++) {
            delete (*it);
        }
    }
    
    if (V) {
        delete [] adj;
        delete [] visited;
    }
    cout << "\n";
}

void graph :: add_edge(int from, int to, int wt)
{
    // create adjacency list for both to and from
    // as it is undirected graph
    edge_t *e_from = new edge_t;
    edge_t *e_to = new edge_t;
    // error handling
    e_from->from = from;
    e_from->to = to;
    e_from->wt = wt;
    
    e_to->from = to;
    e_to->to = from;
    e_to->wt = wt;

    adj[from].push_front(e_from);
    adj[to].push_front(e_to);
}

void graph :: show_graph()
{
    list<edge_t *> :: iterator it; 
    for (int i=0; i<V; i++) {
        cout << "\nList of adj for node:" << i << " :";
        for (it=adj[i].begin(); it != adj[i].end(); it++) {
            cout << (*it)->to << ",";
            cout << (*it)->from << ",";
            cout << (*it)->wt << "  ";
        }
    }
    cout << "\n";
}

void graph :: visit_node(int node)
{
    visited[node] = true;
    list<edge_t *> :: iterator it;
    for (it=adj[node].begin(); it != adj[node].end(); it++) {
        min_pq.push(*it);
    }
    cout << "\nvisited node: " << node;
}

void graph :: mst_prim()
{
    cout << "\n" << "start of mst prim" << "\n";
    visit_node(0);
    while(!min_pq.empty()) {
        edge_t *e = min_pq.top();
        min_pq.pop();
        if (visited[e->to] && visited[e->from]) {
            continue;
        }

        mst.push(e);
        cout << "\npushed an edge to mst :" << e->to << e->from;

        if (!visited[e->to]) {
            visit_node(e->to);
        }
        
        if (!visited[e->from]) {
            visit_node(e->from);
        }
    } // while loop

    //print the MST 

    cout << "\nMST::";
    while(!mst.empty()) {
        edge_t *e = mst.front();
        mst.pop();
        cout << e->from << e->to;
        cout << "  ";
    }
}

void graph :: mst_kruskal()
{
    //print the MST 

    cout << "\nMST kruskal::";
    while(!mst.empty()) {
        edge_t *e = mst.front();
        mst.pop();
        cout << e->from << e->to;
        cout << "  ";
    }
}


int main()
{
    graph g(6);
    cout << "\nHello world of graph\n";

    // adding nodes
    g.add_edge(0,2,5);
    g.add_edge(0,1,7);
    g.add_edge(0,5,2);
    g.add_edge(1,2,3);
    g.add_edge(3,2,9);
    g.add_edge(3,4,4);
    g.add_edge(3,5,1);
    g.add_edge(4,2,8);

    g.show_graph();
    g.mst_prim();
    g.mst_kruskal();

}

