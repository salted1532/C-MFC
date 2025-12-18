#include<iostream>
#include<iomanip> // setw setfill 가 있음

#include"Car.h" //Car 클래스를 포함한 헤더


using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;

public:
	Car() {
		cout << "생성자 입니다." << endl;
	}
	Car(int s) {
		speed = s;
		cout << "생성자2 입니다." << s << endl;
	}
	Car(int s, int g) {
		gear = g;
		cout << "생성자3 입니다." << endl;
	}
	Car(string c) {
		color = c;
		cout << "생성자4 입니다." << endl;
	}

	~Car() {
		cout << "소멸자 입니다." << speed << endl;
	}

public:
	void view();

	void setGear(int gear);
};

void Car::setGear(int gear) {
	this->gear = gear;
}

void Car::view() {
	cout << "speed = " << speed << endl;
	cout << "gear = " << gear << endl;
	cout << "color = " << color << endl;
}


void main() {
	//클래스 사용 방법은 정적과 동적이 있다.
	//정적
	Car c1;
	c1.view(); //숫자를 초기화 해주지 않으면 null값이 나옴

	//동적 
	Car *c2 = new Car(2); //포인터가 붙음
	c2->view(); //포인터는 -> 화살표로 작동

	cout << "프로그램 종료" << endl;

	//동적
	Car* c3 = new Car(300);
	c3->view();

	delete c3;

	delete c2;

	int num = 123;

	printf("hello pc1 : %5d\n", num); //%5d 자리를 5칸 잡고 num 입력
	cout << "hello pc2\n";
	cout << "hello pc3 : " <<  setw(5) << num << endl; //setw(5) 자리를 5칸 잡고 num을 입력
	cout << "hello pc4 : " << setfill('0') << setw(5) << num << endl; //setfill 잡아진 자리를 원하는것으로 체울수 있음
	cout << "hello pc4 : " << setfill('a') << setw(5) << num << endl;

	cin >> num; //cout -> printf 출력 cin -> scanf 입력

	cout << "입력된 숫자는 : " << num << "입니다." << endl;

	cout << num;

}