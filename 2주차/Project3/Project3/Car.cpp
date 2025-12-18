#include "Car.h"

//클래스 메소드 외부정의
void Car::view() {
	cout << "speed = " << speed << endl;
	cout << "gear = " << gear << endl;
}

int main() {

	Car c1;
	c1.view();


	return 0;
}