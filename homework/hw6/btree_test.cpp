#include <iostream>
#include <memory>
#include "btree.h"
using namespace std;


int main() {
    btree b;
    b.insert(10);
    b.insert(14);
    b.insert(6);
    cout << b;
    int r = b.search(6);
    cout << r << endl;
    btree b2 = b;
    int r2 = b2.search(6);
    cout << r2 << endl;
    return 0;
}
