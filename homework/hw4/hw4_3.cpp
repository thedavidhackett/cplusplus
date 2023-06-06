#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct maxlenftn {
    maxlenftn() { maxlen = 0; }

    void operator()(string s) {
        maxlen = max(maxlen,s.size());
    }
    string::size_type maxlen;
};

int main() {
    vector<string> names{"Smith", "Jones", "Johnson", "Grant"};
    maxlenftn maxf1;
    for_each(names.begin(),names.end(), ref(maxf1));
    cout << maxf1.maxlen << endl;
    maxlenftn maxf2;
    maxlenftn maxf3 = for_each(names.begin(),names.end(), maxf2);
    cout << maxf3.maxlen << endl;
    return 0;
}
