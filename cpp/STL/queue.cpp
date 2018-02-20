#include <iostream>
#include <queue>
#include <iterator>
using namespace std;

void show_queue(queue <int> g)
{
    cout << "\n";
    while(!g.empty()) {
        cout << "popped element: " << g.front() << "\n";
        g.pop();
    }
}

int main()
{
    //cout << "Hello world \n";
    queue <int> gqueue;

    for (int i=0; i<10; i++) {
        gqueue.push(i);
    }

    show_queue(gqueue);

}

