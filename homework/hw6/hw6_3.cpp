#include <iostream>
using namespace std;


int double_num(int &i) {
    return i * 2;
}

int triple_num(int &i) {
    return i * 3;
}

int change_number(int &i, int (*f)(int &)) {
    return f(i);
}

int main() {
    string num;
    cout << "Pick a number" << endl;
    cin >> num;
    int n = stoi(num);
    string choice;
    cout << "Double it or Triple it?\n[1] Double it! \n[2] Triple it!" << endl;
    cin >> choice;
    int *new_num = new int;
    int cho_num = stoi(choice);
    if (cho_num == 1){
        cout << "Doubling it!" << endl;
        *new_num = change_number(n, &double_num);
    }

    if (cho_num == 2){
        cout << "Tripling it!" << endl;
        *new_num = change_number(n, &triple_num);
    }

    cout << "Number is now " << *new_num << endl;
}
