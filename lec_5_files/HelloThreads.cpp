#include <iostream>
#include <thread>

void hello_threads() {
    std::cout << "Hello Concurrent World\n";
}

int
main() {
    // Print in a different thread
    std::thread t(hello_threads);
    t.join(); // Wait for that thread to complete
}
