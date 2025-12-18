#include <iostream>

using namespace std;

class A {
	int* data;
	//int* data2 = new int[100];
public:
	A() {
		data = new int[100];
		cout << "자원을 획득함!"
			<< endl;
	}
	~A() {
		cout << "소멸자 호출!" << endl;
		delete[] data;
	}
	void view() {
		cout << "스마트한 포인터 입니다..." << endl;
	}
};

//일반 포인터
//int main() {
//	try {
//		A* pa = new A();
//		
//		throw 1;
//
//		delete pa;
//	}
//	catch (int e) {
//		cout << "예외 발생" << endl;
//	}
//
//	return 0;
//}

//스마트 포인터:unique_ptr
//int main() {
//
//	unique_ptr<A> pa(new A());
//	pa->view();
//
//	//delete pa; //유니크로 만들어서 해제할 필요가 없음
//
//	return 0;
//}

//스마트 포인터에서 다른 포인터를 참조하기 X 안됨
//int main() {
//	unique_ptr<A> pa(new A());
//	// pb 도 객체를 가리키게 할 수 있을까?
//	unique_ptr<A> pb = pa;
//
//	return 0;
//}

//소유권 이전 가능한가? 스마트 포인터
int main() {
	unique_ptr<A> pa(new A());
	cout << "pa : ";
	pa->view();
	cout << pa << endl; //주소나옴

	// pb 에 소유권을 이전.
	unique_ptr<A> pb = move(pa); //move() 를 사용하여 소유권 이전
	cout << "pb : ";
	pb->view();
	cout << pa << endl; //삭제되서 null(00000000)로 바뀜
	cout << pb.get() << endl; //pa의 이전된 주소가 나옴

	return 0;
}
