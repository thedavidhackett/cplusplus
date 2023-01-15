#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// squares a number
double square(double n) {
    return n * n;
}

// squares number and adds it to another
double square_acc(double init, double n) {
    return init + n * n;
}

vector<double> inputDoubles;
vector<double> outputDoubles;

istream& readValues(istream& is) {
    for (;;) {
        string userInput;
        is >> userInput;

        if (userInput == "done")
            break;

        try {
            inputDoubles.push_back(stod(userInput));
        }
        catch(invalid_argument e) {
            cout << "not a number, try again" << endl;
        }

    }

    return is;
}

// gets distance of already transformed vector
double distance(vector<double> values) {
    return sqrt(accumulate(values.begin(), values.end(), 0));
}

// uses inner prod to get distance
double distance_inner_prod(vector<double> values) {
    return sqrt(inner_product(values.begin(), values.end(), values.begin(), 0));
}

// use accumulate and transform in same step to get distance
double distance_accumulate(vector<double> values) {
    return sqrt(accumulate(values.begin(), values.end(), 0, square_acc));
}

int main() {
    cout << "Enter Numbers to Square, enter done when done." << endl;
    readValues(cin);
    cout << "Squared Numbers are..." << endl;
    outputDoubles.resize(inputDoubles.size());
    transform(inputDoubles.begin(), inputDoubles.end(), outputDoubles.begin(), square);

    for (double num : outputDoubles) {
        cout << num << ", ";
    }

    cout << endl;

    cout << "Distance calculated using just accumulate:" << endl;
    cout << distance(outputDoubles) << endl;
    cout << "Distance calculated using inner prod:" << endl;
    cout << distance_inner_prod(inputDoubles) << endl;
    cout << "Distance calculated using accumulate and transform same step:" << endl;
    cout << distance_accumulate(inputDoubles) << endl;

}
