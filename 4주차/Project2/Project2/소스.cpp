#include <iostream>
using namespace std;

int main() {
	int num = 0; // 정수형 변수 정수값을 가짐
	int* p; // *p 포인터 변수는 주소만 가질 수 있음

	num = 100;
	p = &num; // & = 주소값 
	*p = 50;
	//p = 10; // p는 주소값만 저장가능

	cout << "num : " << num << endl; //*p = 50;으로 인해 num 주소값의 정수값이 변경됨
	cout << "&num : " << &num << endl;
	cout << "p : " << p << endl; //p안에 들어가있는 (주소)값
	cout << "*p : " << *p << endl; //p의 주소값이 가리키는 곳의 값 (여기선 num을 가리키는데 해당값이 50으로 변경됨)
	cout << "&p : " << &p << endl; //p의 주소값
	//cout << "*num : " << *num << endl; //정수형이라 포인터를 출력 못함 (가리키진 못함)


	return 0;
}