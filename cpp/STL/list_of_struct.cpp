#include <iostream>
#include <list>
using namespace std;

typedef struct node {
    int to;
    int from;
} node_t;

list<node_t *> glist;

void add_node(int to, int from)
{
    node_t *n = new node_t();
    n->to = to;
    n->from = from;

    glist.push_front(n);
}

int main()
{
    list<node_t *> :: iterator it;
    cout << "\nHello World\n";
    add_node(2,3);
    add_node(4,5);

    cout << "\nBeginning iterator\n";
    for (it=glist.begin(); it != glist.end(); it++) {
        cout << "\n list element:";
        cout << (*it)->to << " ";
        cout << (*it)->from << "\n";
        delete (*it);
    }
}

