#include "PSMatrix.h"
#include <iostream>
#include <chrono>
using namespace mpcs51044;
using namespace std;

int main()
{
    cout << "Testing Determinant with Partial Specialization" << endl;

    auto start1 = chrono::system_clock::now();
    Matrix<double, 2, 2> matrix1 = {
            {1, 2},
            {3, 4}
    };
	static double total1;
	for (int i = 0; i < 100'000'000; i++) {
		matrix1(1, 1) = i;
		total1 += matrix1.determinant();
	}
	cout << chrono::duration<double>(chrono::system_clock::now() - start1).count() << " seconds\n";

}
