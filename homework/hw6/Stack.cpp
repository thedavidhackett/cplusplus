#include "LockFreeStack.h"
#include <iostream>
using namespace std;


mpcs51044::Stack s;


int main() {
    cout << s.pop() << endl;
    s.push(7);
    s.push(5);
    cout << s.pop() << endl;
}
