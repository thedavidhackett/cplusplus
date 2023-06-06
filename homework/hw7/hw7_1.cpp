#include <future>
#include <iostream>
#include <thread>
#include"TestFuncs.h"

using namespace std;

template<typename Func, typename ...Args>
auto my_async(Func f, Args... args)
{
    packaged_task<invoke_result_t<Func&&,Args&&...>(Args&&...)> pt(f);
    auto value = pt.get_future();
    jthread t(move(pt), args...);
    t.detach();
    return value;
}

int main()
{

    auto i = my_async(stupid_functions::count_really_high);
    cout << stupid_functions::count_not_that_high() << endl;
    cout << i.get() << endl;
}
