#include <iostream>
#include <new>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class graph {
    int V; // number of vertices
    list<int>  *adj; // array of adjacency lists for each vertex
    bool *visited;
    int *edge_to;
    
public:
    graph(int v);
    ~graph();
    void add_edge(int from, int to);
    void dfs(int s);
    void bfs(int s);
    void show_path(int from, int to);
    void show_graph();
    void reset_graph();
};

graph :: graph(int v) 
{
    V = v;
    adj = new list<int> [v];
    visited = new bool [V];
    edge_to = new int [V];
    
    for (int i=0; i<V; i++) {
        visited[i] = false;
        edge_to[i] = -1;
    }
}

graph :: ~graph() 
{
    if (V) {
        delete [] adj;
        delete [] visited;
        delete [] edge_to;
    }
}

void graph :: reset_graph()
{
    for (int i=0; i<V; i++) {
        visited[i] = false;
        edge_to[i] = -1;
    }
}

void graph :: add_edge(int from, int to)
{
    // create adjacency list for both to and from
    // as it is undirected graph
    adj[from].push_front(to);
    adj[to].push_front(from);
}

void graph :: dfs(int s)
{
    list<int> :: iterator it;
    visited[s] = true;
    cout << "\nVisted node: " << s << "\n";
    for (it=adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it]) {
            edge_to[*it] = s;
            dfs(*it);
        }
    }
}

void graph :: bfs(int s) 
{
    list<int> :: iterator it;
    queue<int> gq;
    int node = 0;


    visited[s] = true;
    gq.push(s);

    while(!gq.empty()) {
        node = gq.front();
        gq.pop();

        for (it=adj[node].begin(); it != adj[node].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                edge_to[*it] = node;
                cout << "\nVisted node (BFS): " << (*it) << "\n";
                gq.push(*it);
            }
        } // end of for loop
    } // end of while loop
}

void graph :: show_path(int from, int to)
{
    stack<int> path;
    int marker = to;

    while(marker != from) {
        path.push(marker);
        marker = edge_to[marker];
    }

    path.push(from);

    cout << "\nPath:  ";
    while(!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
}


void graph :: show_graph()
{
    list<int> :: iterator it; 
    for (int i=0; i<V; i++) {
        cout << "\nList of adj for node:" << i << " :";
        for (it=adj[i].begin(); it != adj[i].end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    }
   
    cout << "\nEdge to array: ";
    for (int i=0; i<V; i++) {
        cout << edge_to[i] << "  ";
    }
    
    cout << "\nVisited: ";
    for (int i=0; i<V; i++) {
        cout << visited[i] << "  ";
    }
    cout << "\n";
}

int main()
{
    graph g(6);
    cout << "\nHello world of graph\n";

    // adding nodes
    g.add_edge(0,2);
    g.add_edge(0,1);
    g.add_edge(0,5);
    g.add_edge(1,2);
    g.add_edge(3,2);
    g.add_edge(3,4);
    g.add_edge(3,5);
    g.add_edge(4,2);

    //g.show_graph();

    g.dfs(0);
    g.show_graph();
    g.show_path(0, 4);

    // resetting graph
    cout << "\nResetting graph!\n";
    g.reset_graph();
    g.show_graph();
    
    
    g.bfs(0);
    g.show_graph();
    g.show_path(0, 4);
}

