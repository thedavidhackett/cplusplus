#include <utility>
#include <iostream>
#include <string>
#include <format>
using namespace std;

template<typename T>
class Counter {
public:
  Counter(string name, T t) : name(name), t(t) {}
  template<typename ...Ts>
  auto operator()(Ts&& ...ts) {
    count++;
    return t(forward<Ts>(ts)...);
  }
  ~Counter() {
    cout << format("{} was called {} times\n", name, count);
  }
  unsigned count{};
private:
  string name;
  T t;
};

int f_impl(double d)
{
  return static_cast<int>(2 * d);
}

// auto f = f_impl; // Uncomment for unwrapped
auto f = Counter("f", f_impl); // Uncomment for wrapped

int main()
{
  f(1.3); f(2.4);
}
