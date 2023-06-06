#include <future>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include"TestFuncs.h"
using namespace std;

template<typename T>
struct value_holder {
    shared_ptr<T> value = nullptr;
    mutex m;
    condition_variable cv;
    void set_value(T i)  {
        lock_guard<mutex> lk(m);
        value = make_unique<T>(i);
        cv.notify_all();
    };

    T get_value() {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this] {return value != nullptr;});
        return *value;
    };

};

template<typename T>
class my_future {
    public:
        my_future(shared_ptr<value_holder<T>> val) {
            value = val;
        }

        T get() {
            return value->get_value();
        }
    private:
        shared_ptr<value_holder<T>> value;
};

template<typename T>
class my_promise {
    public:
        void set_value(T v) {
            value->set_value(v);
        };
        my_future<T> get_future() {
            my_future f(value);
            return f;
        }
    private:
        shared_ptr<value_holder<T>> value = make_shared<value_holder<T>>();
};



int main()
{
    my_promise<int> p;
    my_future<int> f = p.get_future();
    jthread j1([&p]{p.set_value(3);});
    jthread j2([&f]{cout << f.get() << endl;});

}
