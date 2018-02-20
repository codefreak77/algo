#include <iostream>
#include <stack>
using namespace std;

void show_stack(stack <int> g)
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
    stack <int> gstack;

    for (int i=0; i<10; i++) {
        gstack.push(20 - i);
    }

    show_stack(gstack);

}

