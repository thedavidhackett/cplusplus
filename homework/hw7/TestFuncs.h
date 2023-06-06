#include <iostream>
#include <thread>
using namespace std;

namespace stupid_functions {
int count_not_that_high()
{
    this_thread::sleep_for(10ms);
    cout << "Count to 1000 Started" << endl;
    int i = 0;
    while (i < 1000) {
        i++;
    };

    cout << "Finished counting to 1000" << endl;

    return i;
}

int count_really_high()
{
    cout << "Count to 1000000 Started" << endl;
    this_thread::sleep_for(1s);
    int i = 0;
    while (i < 1000000) {
        i++;
    };

    cout << "Finished counting to 1000000" << endl;

    return i;
}
}
