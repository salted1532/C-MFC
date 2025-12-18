#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;

class Animal {
	int x;
public:
	virtual void speak() = 0;

	Animal() {
		cout << "Animal 생성자 입니다." << endl;
	}
	 virtual ~Animal() {
		cout << "Animal 소멸자 입니다." << endl;
	}
};

class Dog : public Animal {
	int x;
public: 
	void speak() {
		cout << "개소리 멍멍" << endl;
	}
	Dog() {
		cout << "Dog 생성자 입니다." << endl;
	}
	~Dog() {
		cout << "Dog 소멸자 입니다." << endl;
	}
};

class Cat : public Animal {
	int x;
public:
	void speak() {
		cout << "고양이 냥냥" << endl;
	}
	Cat() {
		cout << "Cat 생성자 입니다." << endl;
	}
	~Cat() {
		cout << "Cat 소멸자 입니다." << endl;
	}
};

//상향 형변환 하향 형변환
//int main() {
//	Animal* a1 = new Dog();  // 동적 바인딩 상향 형변환
//	a1->speak();
//
//	((Dog*)a1)->speak(); //하향 형변환
//
//	Dog* d1 = (Dog*)a1;
//	d1->speak();
//
//	delete d1;  // 동적 메모리 할당 후 해제
//
//	return 0;
//}

//가상함수
//int main() {
//	Animal* d1 = new Dog();
//	d1->speak();
//
//	return 0;
//}

////참조자
//int main() {
//	Dog d1;
//	Animal& a1 = d1;
//
//	a1.speak();
//	d1.speak();
//
//	Cat* c1 = new Cat();
//	Animal& a2 = *c1;
//	c1->speak(); //포인터변수면 ->
//	a2.speak(); //그냥 이면 ~.~~();
//	
//	return 0;
//}

//가상 소멸자
int main() {
	Animal* d1 = new Dog(); //부모만 delete하고 끝남 그래서 가상 소멸자 사용

	delete d1;

	return 0;
}