#include <iostream>
#include <new>

using namespace std;

int main()
{

    int *p = new int [5];

    p[1] = 25;

    std::cout << "Hello world\n";
    std::cout << "2nd integer: " << p[1] << endl;

    delete [] p;
}
