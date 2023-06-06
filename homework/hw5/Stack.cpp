#include"Stack.h"
#include<thread>
#include<iostream>
using namespace mpcs;
using namespace std;

mpcs::stack<int> s{1, 2};

void add_num(int num) {
    s.push(num);
};

void remove_num() {
    s.pop();
}


int main()
{
    std::thread t1(add_num, 12);
    std::thread t2(remove_num);
    t1.join();
    t2.join();

    cout << s.top();
    return 0;
}
