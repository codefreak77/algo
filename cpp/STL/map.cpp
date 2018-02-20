#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    map <int, int> gmap;
    map <int, int> :: iterator it;

    gmap.insert(pair <int, int> (1, 40));
    gmap.insert(pair <int, int> (3, 30));
    gmap.insert(pair <int, int> (10, 50));
    gmap.insert(pair <int, int> (2, 70));
    gmap.insert(pair <int, int> (5, 80));

    cout << "\n";
    for (it=gmap.begin(); it != gmap.end(); it++) {
        cout << it->first << "  ";
        cout << it->second;
        cout << "\n";
    }
}
