#include <iostream>
using namespace std;

template  <class T>

class rectangle {
    T a;
    T b;

public:

    void set_value(T x, T y);
};

template <class T>
void rectangle<T>::set_value(T x, T y)
{
    a = x;
    b = y;
}

int main()
{
    rectangle<int> r;
    r.set_value(3,6);
    std::cout << "Hello world\n";
}
