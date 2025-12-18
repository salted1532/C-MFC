#include<iostream>
using namespace std;

class Car {
    int speed = 100;
    int gear = 3;

public:
    Car() {
        cout << "Car 생성자 입니다." << endl;
    }
    Car(int s) : speed(s) {
        cout << s << "값을 받은 Car 생성자 입니다." << endl;
    }
    ~Car() {
        cout << "Car 소멸자 입니다." << endl;
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
    //SportCar(int t) : turbo(t) {
    //    cout << t << "값을 받은 SportCar 생성자 입니다." << endl;
    //}
    SportCar(int t, int s) : turbo(t), Car(s) {
        cout << t << "와" << s << "값을 받은 SportCar 생성자 입니다." << endl;
    }
    SportCar(int s) : Car(s) {
        cout << s << "값을 받은 SportCar 생성자 입니다." << endl;
    }
    ~SportCar() {
        cout << "SportCar 소멸자 입니다." << endl;
    }
    void show() {
        cout << "turbo : " << turbo << endl;
    }
};

int main() {
    SportCar s1(100);
    SportCar c1(500, 200);
    
    
    c1.show();
    c1.view();

    return 0;
}
