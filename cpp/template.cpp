#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b)
{
    return (a + b);
}

int main()
{
    std::cout << "Hello world\n";
    std::cout << sum<int>(2,5) << endl;
}
