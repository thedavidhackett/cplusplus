#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct Nth_Power {
    Nth_Power(int num) : power(num) {}
    private:
        int power;
    public:
        double operator()(double x){
            return pow(x, power);
        }
};


int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    Nth_Power cube{3};
    cout << cube(7) << endl; // prints 343
    // print first five cubes
    transform(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), cube);
}
