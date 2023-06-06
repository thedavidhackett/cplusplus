#include<string>
#include<memory>
#include<iostream>
using namespace std;

template <class T>
struct Animal {
    string get_name() {
        return static_cast<T*>(this) -> name();
    };

    string get_eats() {
        return static_cast<T*>(this) -> eats();
    };
};

struct Cat : public Animal<Cat> {
    string name() { return "cat"; }
    string eats() { return "delicious mice"; }
};
// More animals...

int main() {
    unique_ptr<Animal<Cat>> a = make_unique<Cat>();
    cout << "A " << a->get_name() << " eats " << a->get_eats();
}
