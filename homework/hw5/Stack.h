#ifndef STACK_H
#  define STACK_H
// Implement a thread safe stack.

#include<mutex>
#include<shared_mutex>
#include<stack>
#include<numeric>

namespace mpcs {
template<class T>
class stack {
private:
    std::stack<T> stk;
    std::shared_mutex mutable mtx;
public:
    stack() : stk{} {};
    stack(std::initializer_list<T> init_list) : stk(init_list) {};
    void push(T value) {
        std::lock_guard lock(mtx);
	    stk.push(value);
    }

    void pop() {
        std::lock_guard lock(mtx);
	    stk.pop();
    }

    T top() {
        std::lock_guard lock(mtx);
        return stk.top();
    }

};

}
#endif
