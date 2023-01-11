#include <iostream>
#include <string>
#include <vector>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
using namespace std;
using namespace fmt;


vector<vector<int>> pascalTriangle(int rows) {
    vector<vector<int>> v = {{1}};

    for (int i = 1; i < rows; i++) {
        vector<int> r = {1};
        vector<int> prev = v[i - 1];

        for (int j = 1; j < i; j++) {
            r.push_back(prev[j-1] + prev[j]);
        }

        r.push_back(1);
        v.push_back(r);
    }

    return v;
}

void printVec(vector<int> v, int w) {
    string row = "";
    for (int j = 0; j < v.size(); j++) {
        row += to_string(v[j]) + " ";
    }
    cout << format("{:^{}}", row, w) + "\n";
}

int main()
{
    vector<vector<int>> pascal = pascalTriangle(8);
    int w = pascal.back().size() * 2 + 3;
    for (int i = 0; i < pascal.size(); i++) {
        printVec(pascal[i], w);
    }
    return 0;
}
