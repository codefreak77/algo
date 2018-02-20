#include <iostream>
#include <queue>
#include <iterator>
using namespace std;

void show_queue(priority_queue <int> g)
{
    cout << "\n";
    while(!g.empty()) {
        cout << "top element: " << g.top() << "\n";
        g.pop();
    }
}

int main()
{
    //cout << "Hello world \n";
    priority_queue <int> gqueue;

    for (int i=0; i<10; i++) {
        gqueue.push(i);
    }

    show_queue(gqueue);

}

