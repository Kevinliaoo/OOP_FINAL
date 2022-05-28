#include "Counter.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int myints[] = {1, 2, 3, 3, 2, 1, 2};
    vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
    Counter<int> c(a);
    cout << c[99] << endl;
    for (auto i : c)
    {
        cout << i.first << ", " << i.second << std::endl;
    }
}
