#include <future>
#include <iostream>
#include <thread>
#include"TestFuncs.h"
using namespace std;


template<typename T, typename... Args>
class my_packaged_task {
    typedef T return_type;
    typedef T function_type(Args...);
    public:
    my_packaged_task(function<function_type> t) {
        fi = p.get_future();
        callable = t;
    };
    void operator()(Args... args) {
        call(forward<Args>(args)...);
    }
    future<int> get_future() {
        return move(fi);
    }
    private:
        promise<return_type> p;
        future<return_type> fi;
        function<function_type> callable;
        void call(Args... args) {
            return_type i = callable(forward<Args>(args)...);
            p.set_value(i);
    }
};



int main()
{
    my_packaged_task<int> f(stupid_functions::count_really_high);
    auto i = f.get_future();
    thread t(move(f));
    cout << stupid_functions::count_not_that_high() << endl;
    t.join();
    cout << i.get() << endl;
}
