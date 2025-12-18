#include <iostream>
using namespace std;

//template <typename T, typename U>
//T get_sum(T x, U y)
//{	
//	T sum = x + y;
//	return sum;
//}
//int main()
//{
//	double num1 = 10.67f;
//	int num2 = 3;
//	cout << get_sum(num1, num2) << endl;
//	return 0;
//}

//template <typename T>
//T get_sum(T x)
//{
//	T sum = x;
//}
//
//template <typename T, typename U>
//T get_sum(T x, U y)
//{
//	T sum = x + y;
//}
//
//int main()
//{
//	double num1 = 10.67f;
//	int num2 = 3;
//	cout << get_sum(num1, num2) << endl;
//	return 0;
//}


//클래스 응용
template <typename T>
class Box {
	T data; // T는 타입(type)을 나타낸다.

public:
	Box() { }

	void setData(T value) {
		data = value;
	}

	T getData() {
		return data;
	}
};

int main()
{
	Box<int> b1;

	b1.setData(100);
	cout << b1.getData() << endl;

	Box<double> b2;

	b2.setData(3.14159);
	cout << b2.getData() << endl;
	return 0;
}

