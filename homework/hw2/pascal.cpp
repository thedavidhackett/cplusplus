#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
using namespace std;
using namespace fmt;

struct Row {
    Row(vector<int> init_nums) : numbers(init_nums) {}
    vector<int> numbers;

    void printRow(ostream& os, int eltSize) {
        for (auto elt : numbers) {
            os << format("{:^{}}", elt, eltSize) << " ";
        }
        os << endl;
    }
};

// typedef vector<int> Row;  // Old-fashioned version you might see sometimes
struct Triangle {
    Triangle(int num_rows) : rows({Row({1})}) {
        for (int i = 0; i < num_rows; i++) {
            Row nextRow = createNextRow();
            rows.push_back(nextRow);
        }
    }
    vector<Row> rows;

    int numDigits(int i) const {
        return std::to_string(i).size();
    }

    int getEltSize() const {
        Row lastRow = rows[rows.size() - 1];
        int maxElement = *max_element(lastRow.numbers.begin(), lastRow.numbers.end());
        return numDigits(maxElement);
    }

    Row createNextRow() {
        Row previousRow = rows[rows.size() - 1];
        Row result({});
        int previous = 0;
        for (auto elt : previousRow.numbers) {
            result.numbers.push_back(previous + elt);
            previous = elt;
        }
        result.numbers.push_back(previous);
        return result;
    }

};

int constexpr rows = 10;

ostream& operator <<(ostream& os, Triangle triangle) {

    int eltSize = triangle.getEltSize();
    for (int i = 0; i < triangle.rows.size(); i++) {
        string spaces((triangle.rows.size() - i - 1) * (eltSize + 1) / 2, ' ');
        os << spaces;
        triangle.rows[i].printRow(os, eltSize);
    }
    return os;
}


int main() {
    Triangle triangle(rows);
    cout << triangle;
    return 0;
}
