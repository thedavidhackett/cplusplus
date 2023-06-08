namespace mpcs {
    //Don't use the c style header
    #include <cmath>
    #include <iostream>

    //don't use an entire namespace like std, it'll leak the whole thing
    using std::ostream;

    // since the type is multiplied and is expected to return a double it should be a number
    template<typename T>
    struct Point {
        Point(T X, T Y) : x(X), y(Y) {}
        double length() {return sqrt(x*x + y*y);}
        T x;
        T y;
    };


    template<typename T>
    class ECP : public Point<T> {
        ECP(T X, T Y) : Point(X, Y) {};
        ECP(const ECP &b) : Point(b.x, b.y);
        //Should define a copy assignment operator
        ECP& operator=(ECP b){Point(b.x, b.y)};
        // The += operator should be a method
        void operator+=(ECP<T> const &b) {
            ECP<T> result = this + b;
            x = result.x;
            y = result.y;
        };
        bool isValid() { return y*y == x*x*x - 5*x + 8;}

    };

    //addition operator should not be a method
    template<typename T>
    ECP<T> &operator+(ECP<T> const &a, const ECP<T> &b){
        // we don't actually know that T will be an int, better to convert to whatever T is
        ECP<T> result(T{0}, T{0});
        // The &a(*this) was definitely bad, but I don't think we need it any more

        //all that other stuff

        return result;

    }

    template<typename T>
    ostream &
    operator<<(ostream &os, const Point<T> p){
        os << format("({} {})", p.x, p.y);
        return os;
    }

}
