#include"DistributedCounter1.h"
#include<thread>
#include<iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace mpcs;
using namespace std;
size_t const reps{100'000};
size_t const threadCount{10};
DistributedCounter c;

void countALot()
{
  for (size_t s = 0; s < reps; s++)
    c++;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    std::jthread jt;
    for (size_t s = 0; s < threadCount; s++)
        jt = std::jthread(countALot);
        jt.join();
    auto end = chrono::high_resolution_clock::now();
    cout << "Count is " << c.get() << endl;
    cout << "Elapsed time is " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    return 0;
}
