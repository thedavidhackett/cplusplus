#include"LockedStack.h"
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
using namespace mpcs51044;

LockedStack ls;
LockedStack &getGlobalStack()
{
  static mutex;
  lock_guard lock(mutex);
  return ls;
}
void useStack()
{
  LockedStack &ls = getGlobalStack();
  ls.push(1);
  ls.push(3);
  ls.push(5);
  for (int i = 0; i < 3; i++)
    cout << ls.pop() << endl;
}
int main()
{
  jthread t1(useStack);
  jthread t2(useStack);
  return 0;
}