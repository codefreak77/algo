#include <iostream>
using namespace std;

class rectangle {
    int a;
    int b;

public:

    rectangle();
    rectangle(int x, int y);
    void set_value(int x, int y);
    int area();
};

rectangle::rectangle()
{
    std::cout << "constructor with NO rg called \n";
}

rectangle::rectangle(int x, int y)
{
    std::cout << "constructor with arg called \n";
}

void rectangle::set_value(int x, int y)
{
    a = x;
    b = y;
}

int rectangle::area()
{
    std::cout << "area is: " << (a*b);
    return (a*b);
}

int main()
{
    rectangle r;
    r.set_value(3,6);
    std::cout << "Hello world\n";
    std::cout << "calling object r :" << r.area();
}
