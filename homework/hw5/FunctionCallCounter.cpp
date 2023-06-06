#include <iostream>
#include <functional>
#include <cstring>
using namespace std;


template <typename T, typename... Args>
class Counter {
    typedef T return_type;
    typedef T function_type(Args...);
    public:
        std::function<function_type> callable;
        int count = 0;
        Counter(function_type f){
            callable = f;
        };
        return_type operator()(Args... args){
            count++;
            return callable(forward<Args>(args)...);
        };
};

void hello_world() {
    cout << "Hello World!" << endl;
};

int add(int x, int y){
    return x + y;
}

void modify(string &str, string addition) {
    str = str + addition;
}


template <typename Func, typename Func2, typename Func3>
void run_functions(Func &f1, Func2 &f2, Func3 &f3) {
    f1();
    f1();
    f2(1, 2);
    string my_name = "David";
    f3(my_name, " No Middle Name");
    f3(my_name, " Hackett");
    cout << my_name << endl;
}

int main(int argc, char** argv) {
    // enter no-count to switch to not counting
    if (argc > 1) {
        if (strcmp(argv[1], "no-count") == 0) {
            run_functions(hello_world, add, modify);
            return 0;
        }
    }

    Counter cf_hello_world(hello_world);
    Counter cf_add(add);
    Counter cf_modify(modify);

    run_functions(cf_hello_world, cf_add, cf_modify);
    cout << "Hello world was called " << cf_hello_world.count << " times" << endl;
    cout << "Add was called " << cf_add.count << " times" << endl;
    cout << "Modify was called " << cf_modify.count << " times" << endl;

}
