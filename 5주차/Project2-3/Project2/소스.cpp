#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;

//추상 클래스 예제

class RemoteControl {
public:
	// 순수가상함수정의
	virtual void turnOn() = 0; // 가전제품을켠다.
	virtual void turnOff() = 0; // 가전제품을끈다.
};

class Television : public RemoteControl {
	int vol;

public:
	void turnOn()
	{
		// 실제로TV의전원을켜기위한코드가들어간다.
		cout << "TV ON" << endl;
	}
	void turnOff()
	{
		// 실제로TV의전원을끄기위한코드가들어간다.
		cout << "TV OFF" << endl;
	}
	void volCh() {
		vol += 10;
		cout << "볼륨 : " << vol << endl;
	}
};

int main() {
	RemoteControl* r1 = new Television();
	r1->turnOn();
	r1->turnOff();

	((Television*)r1)->volCh();

	delete r1;

	return 0;
}