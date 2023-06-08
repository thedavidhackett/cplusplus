#include "elliptic.h"
#include <vector>
#include <numeric>
using namespace mpcs;

//use a shared pointer not a raw pointer
double
addLength(double acc, const std::shared_ptr<Point> &p) {
    return acc + p->length();
}

int
main()
{
    vector<shared_ptr<Point<double>>> points;
    for (double d = .5; d < 10;) {
        //using d++ in assignment is ambigous
        points.push_back(std:make_shared<Point<double>(d, d + 1));
        d++;
    }

    // use a double 0.0 not an int 0
    std::cout << "Sum of lengths : " << std::accumulate(points.begin(), points.end(), 0.0, addLength)

    vector<shared_ptr<Point<double>>> new_points;

    //better way to copy
    points.assign(new_points.begin(), new_points.end());

    ECP ecp{1, 2}
    if (!ecp.isValid) {
        throw runtime_error("bad elliptic curve point")
    }

}
