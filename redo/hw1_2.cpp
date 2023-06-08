#include <vector>
#include <iostream>
#include <format>
using namespace std;

vector<vector<int>> pascal{{1}};
int constexpr rows = 8;

int main()
{

    for (int i = 1; i < rows; i++) {
        vector<int> prev_row = pascal.back();
        vector<int> next_row{1};
        for (int j = 1; j < i; j++) {
            next_row.push_back(prev_row[j - 1] + prev_row[j]);
        }
        next_row.push_back(1);
        pascal.push_back(next_row);
    }

    for (auto v : pascal) {
        for (int i : v) {
            cout << format("{} ", i);
        }
        cout << endl;
    }
}
