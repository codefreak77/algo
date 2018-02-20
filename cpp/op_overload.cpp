#include <iostream>
using namespace std;

class vector {
    int a;
    int b;

public:

    vector();
    vector(int x, int y);
    void set_value(int x, int y);
    int area();
    vector operator+(const vector& v);
};

vector vector::operator+(const vector& v)
{
    vector tmp;
    tmp.a = a + v.a;
    tmp.b = b + v.b;

    return (tmp);
}


vector::vector()
{
    std::cout << "constructor with NO rg called \n";
}

vector::vector(int x, int y)
{
    std::cout << "constructor with arg called \n";
}

void vector::set_value(int x, int y)
{
    a = x;
    b = y;
}

int vector::area()
{
    std::cout << "area is: " << (a*b);
    return (a*b);
}

int main()
{
    vector r1;
    vector r2;
    vector r;
    r1.set_value(3,6);
    r2.set_value(4,5);

    r = r1 + r2;
    std::cout << "Hello world\n";
    std::cout << "calling object r :" << r.area();
}
