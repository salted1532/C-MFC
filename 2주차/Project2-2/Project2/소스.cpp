#include<iostream>
#include<iomanip> // setw setfill 가 있음

//#include"Car.h" //Car 클래스를 포함한 헤더

using namespace std;

class Car {
private:
	int speed;
	int gear;

	const int MAX_SPEED = 50;

public:

	static int count;



public:
	Car() {
		count++; //객체 개수 확인 용도
		cout << "생성자 입니다." << endl;
	}
	Car(int s, int g) : speed(s), gear(g) {

		cout << "생성자2 입니다. " << s << g << endl;
	}

	Car(int m, int s, int g) : speed(s), gear(g), MAX_SPEED(m) {

		cout << "생성자3 입니다. " << s << g << MAX_SPEED << endl;
	}

public:
	void view();
};

void Car::view() {
	cout << "speed = " << speed << endl;
	cout << "gear = " << gear << endl;
	cout << "MAX_SPEED = " << MAX_SPEED << endl;

	cout << "count = " << count << endl;
}

int Car::count = 0;


void main() {
	//클래스 사용 방법은 정적과 동적이 있다.
	//정적
	Car c1;
	c1.view(); //숫자를 초기화 해주지 않으면 null값이 나옴

	Car c4;//count++ 시켜주는 용도
	c4.view();

	Car c5;//count++ 시켜주는 용도
	c5.view();

	//동적 
	Car *c2 = new Car(100, 3); //포인터가 붙음
	c2->view(); //포인터는 -> 화살표로 작동

	cout << "프로그램 종료" << endl;

	//동적
	Car* c3 = new Car(2000, 300, 4);
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