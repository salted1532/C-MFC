//#pragma once
//
//#include<iostream>
//#include<iomanip> // setw setfill 가 있음
//
//using namespace std;
//
//class Car {
//private:
//	int speed = 0;
//	int gear = 0;
//	string color = "red";
//
//public:
//	Car() {
//		cout << "생성자 입니다." << endl;
//	}
//	Car(int s) {
//		speed = s;
//		cout << "생성자2 입니다." << s << endl;
//	}
//	Car(int s, int g) {
//		gear = g;
//		cout << "생성자3 입니다." << endl;
//	}
//	Car(string c) {
//		color = c;
//		cout << "생성자4 입니다." << endl;
//	}
//
//	~Car() {
//		cout << "소멸자 입니다." << speed << endl;
//	}
//
//public:
//	void view();
//
//	void setGear(int gear);
//};
//
//void Car::setGear(int gear) {
//	this->gear = gear;
//}
//
//void Car::view() {
//	cout << "speed = " << speed << endl;
//	cout << "gear = " << gear << endl;
//	cout << "color = " << color << endl;
//}