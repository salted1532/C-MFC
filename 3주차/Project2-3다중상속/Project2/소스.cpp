#include<iostream>
using namespace std;

class Car {
    int speed = 100;
    int gear = 3;

public:
    Car() {
        cout << "Car 생성자 입니다." << endl;
    }
    ~Car() {
        cout << "Car 소멸자 입니다." << endl;
    }

    void view() {
        cout << "speed : " << speed << endl;
        cout << "gear : " << gear << endl;
    }
};

class Part {
    int scrow = 10;
    int cargo = 1;

public:
    Part() {
        cout << "Part 생성자 입니다." << endl;
    }
    ~Part() {
        cout << "Part 소멸자 입니다." << endl;
    }

    void show() {
        cout << "scrow : " << scrow << endl;
        cout << "cargo : " << cargo << endl;
    }

    void view() {
        cout << "scrow : " << scrow << endl;
        cout << "cargo : " << cargo << endl;
    }

};

class Truck : public Car, public Part {
    int p4 = 4;

public: 
    Truck() {
        cout << "Truck 생성자 입니다." << endl;
    }
    ~Truck() {
        cout << "Truck 소멸자 입니다." << endl;
    }
    void print() {
        cout << "p4 : " << p4 << endl;
    }
};

int main() {
    Truck t1;
    t1.Car::view();
    t1.Part::view();
    t1.show();
    t1.print();

    return 0;
}
