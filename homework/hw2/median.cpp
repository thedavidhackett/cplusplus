#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


vector<double> inputDoubles;

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


// uses sort, works with even length vectors
double findMedian(vector<double> values) {
    int idx = values.size() / 2;
    sort(values.begin(), values.end());
    if (values.size() % 2 == 0)
        return (values[idx] + values[idx - 1]) / 2;

    return values[idx];
}

// uses partial sort, works with even length vectors
double findMedianPartialSort(vector<double> values) {
    int idx = values.size() / 2;
    partial_sort(values.begin(), values.begin()+(idx+1), values.end());
    if (values.size() % 2 == 0)
        return (values[idx] + values[idx - 1]) / 2;

    return values[idx];
}

// uses nth element will not work with even length vectors
double findMedianNthElement(vector<double> values) {
    int idx = values.size() / 2;
    nth_element(values.begin(), values.begin()+idx, values.end());
    return values[idx];
}

// template version
auto findMedianTemplate(vector<auto> values) {
    int idx = values.size() / 2;
    sort(values.begin(), values.end());
    if (values.size() % 2 == 0)
        return (values[idx] + values[idx - 1]) / 2;

    return values[idx];
}

int main() {
    cout << "Enter numbers" << endl;
    readValues(cin);
    double med1 = findMedian(inputDoubles);
    cout << "Median using sort: " << med1 << endl;
    double med2 = findMedianPartialSort(inputDoubles);
    cout << "Median using partial sort: " << med2 << endl;
    double med3 = findMedianNthElement(inputDoubles);
    cout << "Median using nth element: " << med3 << endl;
    double med4 = findMedianTemplate(inputDoubles);
    cout << "Median using template function: " << med4 << endl;

    return 0;
}
