#include<iostream>

using namespace std;
//
////무드등 만들기
//
////추상 클래스 사용
//class Mood_LightControl {
//public:
//	// 순수가상함수정의
//	virtual void turnOn() = 0; // 전등을 켠다.
//	virtual void turnOff() = 0; // 전등을 끈다.
//	virtual void brightnessUpCh() = 0; //밝기 올리기
//	virtual void brightnessDownCh() = 0; //밝기 내리기
//	virtual void colorCh(string color) = 0; //조명 색상 변경
//};
//
//class Mood_Light : public Mood_LightControl {
//	int brightnesslevel; // 밝기 조절은 0 ~ 100으로 제한
//	string color; 
//
//public:
//	//생성자
//	Mood_Light() {
//		brightnesslevel = 0;   // 꺼진 상태
//		color = "white";       //기본 색상은 흰색
//		cout << "무드등 객체 생성자입니다." << endl;
//	}
//
//	//소멸자
//	~Mood_Light() {
//		cout << "무드등 객체 소멸자입니다." << endl;
//	}
//
//	//무드등 켜기
//	void turnOn()
//	{
//		// 실제 무드등이 켜질때 필요한 코드가 들어가면됨
//		brightnesslevel = 10; // 무드등이 켜질때 기본 밝기는 10
//		cout << "Mood Light ON" << endl;
//	}
//	//무드등 끄기
//	void turnOff()
//	{
//		// 실제 무드등이 꺼질때 필요한 코드가 들어가면됨
//		brightnesslevel = 0; // 무드등이 꺼질때 밝기는 0으로 초기화
//		cout << "Mood Light OFF" << endl;
//	}
//
//	//밝기 조절 메소드
//	void brightnessUpCh() {
//		brightnesslevel += 10;
//
//		if (brightnesslevel >= 100) {
//			brightnesslevel = 100;
//			cout << "최대 밝기에 도달했습니다."<< endl;
//			cout << "밝기 : " << brightnesslevel << endl;
//		}
//		else {
//			cout << "밝기 : " << brightnesslevel << endl;
//		}
//	}
//	
//	void brightnessDownCh() {
//		brightnesslevel -= 10;
//
//		if (brightnesslevel <= 0) {
//			brightnesslevel = 0;
//			cout << "최소 밝기에 도달했습니다." << endl;
//			cout << "밝기 : " << brightnesslevel << endl;
//		}
//		else {
//			cout << "밝기 : " << brightnesslevel << endl;
//		}
//	}
//
//	//색상 변경 메소드
//	void colorCh(string col) {
//		color = col;
//		cout << "조명 색상 : " << col << endl;
//	}
//};
//
//int main() {
//	Mood_Light* m1 = new Mood_Light();
//	m1->turnOn(); //무드등 켜기
//
//	m1->brightnessUpCh(); //밝기 올리기 
//
//	m1->brightnessDownCh(); //밝기 내리기
//
//	m1->colorCh("red"); // 조명 색상 변경
//
//	m1->turnOff(); //무드등 끄기
//
//	delete m1; // 메모리 해제
//
//	return 0;
//}

class Lamp{
	bool sw = false;
	int light = 0;
	string color = "Black";
public:
	Lamp() {
		cout << "데스크 램프를 켭니다." << endl;
	}
	~Lamp() {
		cout << "전원 종료" << endl;
	}

	//스위치 1개 일때
	void swOnOff() {
		if (sw == false) {
			sw = true;
			cout << "스위치 온" << endl;
		}
		else if (sw == true) {
			sw = false;
			cout << "스위치 오프" << endl;
		}
	}

	//값을 받아올수 있는 스위치일때
	void Onoff(int n) {
		sw = n;
	}

	//스위치가 2개일때
	void swOn() {
		sw = true;
	}
	void swOff() {
		sw = false;
	}

	//밝기 값을 받아와서 처리
	void swlight(int light) {
		this->light = light;
	}

	//버튼 형식
	void lightCh() {
		light += 1;
		cout << "밝기 : " << light << endl;
	}

	//색깔을 바로 가져와 적용
	virtual void colorCh(string col) = 0;
	
	void view() {
		cout << sw << endl;
		cout << light << endl;
		cout << color << endl;
	}
};

class Change : public Lamp {
	string color = "Blue";

public:
	void colorCh(string col) {
		color = col;
	}
	void view() {
		cout << color << endl;
	}
};

int main() {

	Change* c1 = new Change();
	c1->Lamp::view();

	c1->swOnOff();
	c1->swlight(10);
	c1->colorCh("red");
	c1->view();
	c1->swOnOff();

	return 0;
}
