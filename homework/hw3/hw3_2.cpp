#include <iostream>
using namespace std;

struct StaticPrinter {
    StaticPrinter(string msg) { cout << msg << endl;}
};

StaticPrinter printer("Hello World");

int main()
{
    return 0;
}
