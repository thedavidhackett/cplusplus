#include <iostream>
using namespace std;

int f(){
    return 1;
}

char * f2(char * c1, char * c2) {
    return c1;
}


class Animal {
    public:
        string name;
        int *legs;
        int f(int * i) { return 1;}
        int f2(double (*)(float &g)){ return 1;}
};

//void (*p[10]) (void(*)())
void v() {
    string n = "Nothing";
};
void vv(void (*v)()) {
    string n = "also nothing";
}

void vvv() {
    void (*p[10])(void(*)());
    p[0] = vv;
}


int main() {

    //int *
    int *ip = new int;
    cout << typeid(ip).name() << endl;
    //int &
    int i = 2;
    int& ir = i;
    cout << typeid(ir).name() << endl;
    //double
    double d = 2;
     cout << typeid(d).name() << endl;
    //A *
    Animal *ar = new Animal;
    cout << typeid(ar).name() << endl;
    //char const *
    char const *cp = new char;
    cout << typeid(cp).name() << endl;
    // char const &
    char c = 'a';
    char const &cr = c;
    cout << typeid(cr).name() << endl;
    //long[7]
    long la[7] = {1, 2, 3, 4, 5, 6, 7};
    cout << typeid(la).name() << endl;
    //int **
    int **ipp = &ip;
    cout << typeid(ipp).name() << endl;
    //int *&
    int *&ipr = ip;
    cout << typeid(ipr).name() << endl;
    //float &
    float fl = 2.0;
    float& flr = fl;
    cout << typeid(flr).name() << endl;
    //int (*)()
    int (*fp)() = &f;
    cout << typeid(fp).name() << endl;
    //int (*&)()
    int (*&fpr)() = fp;
    //char *(*)(char * char *)
    char *(*f2p)(char *, char *) = *f2;
    cout << typeid(f2p).name() << endl;
    //A::*
    Animal a;
    a.legs = ip;
    cout << typeid(a.legs).name() << endl;
    //int (A::*)(int *)
    int (Animal::*mfp)(int *) = &Animal::f;
    //int (A::**)(int *)
    int (Animal::**mfpp)(int *) = &mfp;
    //int (A::*&)(int *)
    int (Animal::*&mfpr)(int *) = mfp;
    //int (A::*)(double (*) (float &))
    int (Animal::*mf2p)(double (*)(float &)) = &Animal::f2;

}
