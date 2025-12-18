#include<iostream>

using namespace std;

//무드등 만들기

//추상 클래스 사용
class RemoteControl {
public:
	// 순수가상함수정의
	virtual void turnOn() = 0; // 전등을 켠다.
	virtual void turnOff() = 0; // 전등을 끈다.
};

class Mood_Light : public RemoteControl {
	int brightnesslevel; // 밝기 조절은 0 ~ 100으로 제한
	string color; 

public:
	//생성자
	Mood_Light() {
		brightnesslevel = 0;   // 꺼진 상태
		color = "white";       //기본 색상은 흰색
		cout << "무드등 객체 생성자입니다." << endl;
	}

	//소멸자
	~Mood_Light() {
		cout << "무드등 객체 소멸자입니다." << endl;
	}

	//무드등 켜기
	void turnOn()
	{
		// 실제 무드등이 켜질때 필요한 코드가 들어가면됨
		brightnesslevel = 10; // 무드등이 켜질때 기본 밝기는 10
		cout << "Mood Light ON" << endl;
	}
	//무드등 끄기
	void turnOff()
	{
		// 실제 무드등이 꺼질때 필요한 코드가 들어가면됨
		brightnesslevel = 0; // 무드등이 꺼질때 밝기는 0으로 초기화
		cout << "Mood Light OFF" << endl;
	}

	//밝기 조절 메소드
	void brightnessUpCh() {
		brightnesslevel += 10;

		if (brightnesslevel >= 100) {
			brightnesslevel = 100;
			cout << "최대 밝기에 도달했습니다."<< endl;
			cout << "밝기 : " << brightnesslevel << endl;
		}
		else {
			cout << "밝기 : " << brightnesslevel << endl;
		}
	}
	
	void brightnessDownCh() {
		brightnesslevel -= 10;

		if (brightnesslevel <= 0) {
			brightnesslevel = 0;
			cout << "최소 밝기에 도달했습니다." << endl;
			cout << "밝기 : " << brightnesslevel << endl;
		}
		else {
			cout << "밝기 : " << brightnesslevel << endl;
		}
	}

	//색상 변경 메소드
	void colorCh(string col) {
		color = col;
		cout << "조명 색상 : " << col << endl;
	}
};

int main() {
	Mood_Light* m1 = new Mood_Light();
	m1->turnOn(); //무드등 켜기

	m1->brightnessUpCh(); //밝기 올리기 

	m1->brightnessDownCh(); //밝기 내리기

	m1->colorCh("red"); // 조명 색상 변경

	m1->turnOff(); //무드등 끄기

	delete m1; // 메모리 해제

	return 0;
}