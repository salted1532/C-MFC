#include<iostream>

using namespace std;

class Point {
	int x, y;
	int point;
public: 
	Point(int p, int x, int y) : point(p), x(x), y(y) {

	}

	void print() {
		cout << "point"<< point <<" x : " << x << " point" << point << " y : " << y << endl;
	}
};

class Rectangle { //사각형 만들기 (x,y) (x+@,y+@) 값 필요
	int x1, y1, x2, y2; //이런식으로 선언 가능 (x1,y1) (x2,y2)
	Point p1, p2; //클래스 안에 클래스 선언 가능 포인트 클래스를 이용하여 (x,y)를 2개 생성

public:
	Rectangle(int p1, int x1, int y1, int p2, int x2, int y2) : p1(p1, x1, y1), p2(p2, x2, y2) {

	}

	void view() {
		p1.print();
		p2.print();
	}
};


void main() {
	Rectangle rect(1, 100, 100, 2, 200, 200);
	rect.view();

	Rectangle* Rect = new Rectangle(1, 10, 10, 2, 20, 20);
	Rect->view();
}