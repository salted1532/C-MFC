#include <iostream>
using namespace std;

//포인터 int영역 할당
int main() {
	//int num;
	//int* p = &num; //스택 영역으로 주소값을 가리키는 포인터 변수명 있음

	int* p = new int; //변수명도 없이 hip 힙영역에서 가리키는 포인터
	//4byte 영역이 자동으로 지워지지 않음
	*p = 10;
	cout << *p << endl; 
	delete p; //클래스 소멸자와 같이 메모리를 직접 죽여서 메모리 누수를 막아야함
	//delete p 는 메모리와 연결을 해제
	p = nullptr; // p가 가리키는 주소값 해제

	//소멸자 지워진걸 또 지우면 오류 발생
	if (p) {
		delete p;
	}

	return 0;
}

