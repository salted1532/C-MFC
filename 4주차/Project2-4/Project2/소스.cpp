#include <iostream>
using namespace std;

//참조자
int main() {
	int num1 = 5;
	int num2 = 4;
	int& other = num1; //정의 시에 반드시 변수를 연결시켜주어야함
	//한번 연결하면 다른것과 연결 불가능

	//&other = num2; // 다른 변수를 참조자로 설정 불가능

	other = 3; //num1과 같이 변함

	cout << "num1 : " << num1 << endl;
	cout << "other : " << other << endl;
	cout << "&num1 : " << &num1 << endl;
	cout << "&other : " << &other << endl;
	return 0;
}

//레퍼런스는 정의 시에 반드시 누구의 별명인지 명시 해야
//불가 : int& another_a;
//가능 : int* p;
//레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없음

int main() {
	int num1 = 5;
	int& other = num1; 
	int& other2 = other;

	cout << num1 << other << other2 << endl;
	cout << &num1 << &other << &other2 << endl;

	return 0;
}