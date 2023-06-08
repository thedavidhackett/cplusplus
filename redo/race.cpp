#include <iostream>
#include <thread>
#include <mutex>
#include <thread>
using namespace std;

struct Race {
 Race(int m) : miles(m) {};
  bool start = false;
  int miles;
  mutex mtx;
  condition_variable cv;
  void start_race() {
    start = true;
    cv.notify_all();
  }

};

struct Car {
    shared_ptr<Race> race;
    virtual void drive(int const miles) = 0;
    virtual double mpg() = 0;
    void start_race() {
        unique_lock lck(race->mtx);
        race->cv.wait(lck, [&] {return race->start;});
        drive(race->miles);
    }
};

struct Sedan : public Car {
    Sedan(Race &r) : race(make_shared<Race>(r)){};
    shared_ptr<Race> race;
    double gallons_gas = 15.0;
    double average_speed = 65;
    void goToWork() {cout << "off to work\n";}
    void drive(int const miles) {
        goToWork();
        int i = 0;
        while (i < miles) {
            this_thread::sleep_for(60ms/average_speed);
            gallons_gas = gallons_gas - 1 / mpg();
            if (gallons_gas < 0.0) {
                cout << "The sedan needs gas";
                this_thread::sleep_for(600ms);
            }

            if (rand() % 10 + 1 > 9) {
                cout << "The sedan hit a pot hole!";
                this_thread::sleep_for(1000ms);
            }

            i++;
        }

        cout << "The sedan finished\n";
    }
    double mpg() {
        return 31.5;
    }
};

struct SUV : public Car {
    SUV(Race &r) : race(make_shared<Race>(r)){};
    shared_ptr<Race> race;
    double gallons_gas = 25;
    int average_speed = 55;

    void takeKidsToSoccer(int kids) {
        cout << "I hope we win\n";
    }

    void drive(int const miles) {
        takeKidsToSoccer(4);

        int i = 0;

        while (i < miles) {
            this_thread::sleep_for(60ms/average_speed);
            gallons_gas = gallons_gas - 1 / mpg();
            if (gallons_gas < 0.0) {
                cout << "The suv needs gas";
                this_thread::sleep_for(600ms);
            }

            if (rand() % 10 + 1 > 8) {
                cout << "The suv hit a pot hole!";
                this_thread::sleep_for(1000ms);
            }

            i++;
        }
        cout << "The suv finished";
    }

    double mpg() {
        return 25.75;
    }
};

struct SportsCar : public Car {
    SportsCar(Race &r) : race(make_shared<Race>(r)){};
    shared_ptr<Race> race;
    double gallons_gas = 15;
    int average_speed = 90;

    int topSpeed() {return 150;}
    void compete() {

    }
    void drive(int const miles) {
        cout << "My top speed is " + topSpeed();

        int i = 0;

        while (i < miles) {
            this_thread::sleep_for(60ms/average_speed);
            gallons_gas = gallons_gas - 1 / mpg();
            if (gallons_gas < 0.0) {
                cout << "The sports car needs gas";
                this_thread::sleep_for(600ms);
            }

            if (rand() % 10 + 1 > 8) {
                cout << "The sports car hit a pot hole!";
                this_thread::sleep_for(1000ms);
            }

            i++;
        }
        cout << "The sports car finished\n";
    };
    double mpg() {
        return 15.0;
    }
};

int main() {
    Race race{100};
    SUV suv(race);
    SportsCar sportscar(race);
    Sedan sedan(race);

    jthread j1(suv.start_race());
    jthread j2(sportscar.start_race());
    jthread j3(sedan.start_race());

    race.start_race();
}
