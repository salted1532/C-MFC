#include<iostream>
using namespace std;

class Car {
    int speed = 100;
    int gear = 3;
    int turbo = 150;
public:
    Car() {
        cout << "Car 생성자 입니다." << endl;
    }
    ~Car() {
        cout << "Car 소멸자 입니다." << endl;
    }

    int getHp() {
        return turbo;
    }

    void view() {
        cout << "speed : " << speed << endl;
        cout << "gear : " << gear << endl;
    }
};

class SportCar : public Car {
    int turbo = 300;

public:
    SportCar() {
        cout << "SportCar 생성자 입니다." << endl;
    }
    ~SportCar() {
        cout << "SportCar 소멸자 입니다." << endl;
    }
    int getHp() {
        return turbo;
    }
    void show() {
        cout << "turbo : " << turbo << endl;
        cout << Car::getHp() << endl;
    }
};

int main() {
    SportCar s1;
    cout << s1.SportCar::getHp() << endl;
    
    cout << s1.Car::getHp() << endl;

    s1.show();

    return 0;
}
