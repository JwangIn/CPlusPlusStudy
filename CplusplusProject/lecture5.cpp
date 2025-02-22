#include "lectures.h"

/*
*  학습 목표 : 클래스(객체지향 프로그래밍)의 특징
*  작성일 : 2024-08-14
*  작성자 : 박종현
*/

// 클래스 복습
// 클래스 생성자, 함수 오버로딩

// 프로그래머를 제한하는 것이 클래스가 갖고 있는 특징이다.
// 프로그래머 실수를 원천적으로 방지할 수 있다.

// 1. 생성자 : 프로그래머가 실수로 초기화하지 않고 데이터를 사용하는 것을 원천적으로 막기 위한 문법이다.
// 2. 정보은닉 : 접근지정자를 통해서 프로그래머가 데이터를 안전하게 보장할 수 있는 기능이다.(숨기는 기능을 통해서)
// 멤버 변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서 안전한 형태로 멤버 변수의 접근을 유도하는 것을 의미한다.
// 좋은 클래스를 작성하기 위한 기본 조건 : 정보은닉(은닉성), 캡슐화
// 3. 캡슐화 : 캡슐은 여러가지 성분이 혼합되어 있는 것을 보관하는 것
// 확인 하려면 캡슐을 뜯어서 분석해야한다.
// 코드를 캡슐화 시켰다. -> 코드를 함수로 변경했다. 함수를 코드로 작성을 해서 , 이 기능이 필요한 사람은 이 함수를 호출만 하면 되게끔 작성하는 것
// (1) 사용자(유저)가 그 함수가 무엇을 하는지 알 필요가 없다.
// (2) 작성자(프로그래머) 입장에서 코드를 작성하는데 필요한 함수를 그냥 호출만 하면 된다.
// 예) Play(); 행복도,허기 등등의 변화
//     패키지 상품을 만들다. Play, Feed, Shower등등을 한번에 실행되는 기능
//     Package1(){Play(); Feed(); Shower();}


class Date
{
private:
	int day;   // 만들 때 생각. 30, 31
	int month; // 1 ~ 12
	int year; // 2024 초기화 값
public:
	// private가 아닌  public에 작성한다면
	Date();
	Date(int _day, int _month, int _year);
	void ChangeDay(int x); // day를 변경하는 함수
	void ChangeMonth(int x);
	void ChangeYear(int x);
	void ChangeDate(int _year, int _month, int _day);
	void ShowDate(); // 오늘 날짜를 출력하는 함수

};

Date::Date() // 디폴트 생성자의 재정의
{
	day = 14;
	month = 8;
	year = 2024;
}

Date::Date(int _day, int _month, int _year)
{
	day = _day; // this->day=day;
	this->month = _month;
	this->year = _year;

}

void Date::ChangeDay(int x)
{
	if (x > 31)
	{
		std::cout << "일은 31을 넘을 수 없습니다." << std::endl;
		std::cout << "해당 기능을 실시 할 수 없습니다." << std::endl;
		return;
	}
	day=x;
}

void Date::ChangeMonth(int x)
{
	month = x;
}

void Date::ChangeYear(int x)
{
	year = x;
}

void Date::ChangeDate(int _year, int _month, int _day)
{
	year = _year;
	month = _month;
	day = _day;
}

void Date::ShowDate()
{
	std::cout << "오늘은 " << year << "년 " << month << "월 " << day << "일입니다"<< std::endl;
}

class SinivelCap
{
public:
	void Take()
	{
		std::cout << "콧물약을 복용했습니다." << std:: endl;
	}
};
class SneezCap
{
public:
	void Take()
	{
		std::cout << "감기약을 복용했습니다." << std::endl;
	}
};

class Capsule100
{
private:
	SinivelCap sc;
	SneezCap sz;
public:
	void Take()
	{
		sc.Take();
		sz.Take();
	}
};

class Patient
{

public:
	void TakeCapsule(Capsule100& capsule)
	{
		capsule.Take();
	}
};

// Point (int x, int y) 좌표를 출력하는 개체를 생성해보세요
// 사각형 객체를 생성해보세요
// 사각형의 넓이를 구하는 함수
// 사각형의 정보를 출력하는 함수 구현
// leftdown 과 upright의 좌표를 변경하는 함수 추가

class Point
{
private:
	int x;
	int y;
public:
	Point();
	int GetX() const;
	int GetY() const;
	void ShowPoint() const;
};
Point::Point()
{
	std::cout << "x의 좌표를 입력 : ";
	std::cin >> x;
	std::cout << "y의 좌표를 입력 : ";
	std::cin >> y;	
}

// const 함수에 대한 설명
// (반환값) 함수이름() const; 형식으로 작성한다.
// const keyword 수식받는 멤버 변수의 값이 변경되지 않음을 보장하는 키워드 입니다.

int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}

void Point::ShowPoint() const
{
	std::printf("(%d, %d)\n", x, y);
	//std::cout << "(" << x <<"," << y << ")" << std::endl;
}


class Rectangle
{
private:
	Point leftDown;
	Point rightUp;
	int areaSize;
public:
	Rectangle();
	int CalculateArea();
	void ShowRectinfo();
};

// 멤버 이니셜라이저를 이용한 멤버 초기화 방법
// 멤버 이니셜라이저는 멤버변수로 선언된 객체의 생성자 호출을 활용하는 방법입니다.

Rectangle::Rectangle() :leftDown(), rightUp() 
{
	areaSize = CalculateArea();
}

int Rectangle::CalculateArea()
{
	int row =rightUp.GetX() - leftDown.GetX(); // 가로 길이
	int col = rightUp.GetY() - leftDown.GetY(); // 세로 길이

	std::cout << "사각형의 넓이 : " << row * col << std::endl;
	return row * col;
}

void Rectangle::ShowRectinfo()
{
	leftDown.ShowPoint();
	rightUp.ShowPoint();
	std::cout << "사각형의 넓이 : " << areaSize << std::endl;

}

// Circle 클래스를 직접 설계해보세요
// 반지름 radius, const float PI=3.14f, 원점 좌표 Point
// 원의 호의 길이와, 원의 넓이를 생성자로 생성하고
// showCircleinfo(); 원점 좌표, 반지름 길이, 호의 길이, 넓이를 출력하는 함수를 만들어라

class Circle
{
private:
	const float PI = 3.14f;
	int radius;
	int ArcLength;
	int CircleArea;
	Point CirclePoint;
public:
	Circle();
	void ShowCircleinfo();
};

Circle::Circle():CirclePoint()
{
	std::cout << "반지름의 길이 : ";
	std::cin >> radius;
	ArcLength = 2 * PI * radius;
	CircleArea = radius * radius * PI;
}

void Circle::ShowCircleinfo()
{

	std::cout << "반지름의 길이 : " << radius << std::endl;
	std::cout << "원의 넓이 : " << CircleArea << std::endl;
	std::cout << "호의 길이 : " << ArcLength << std::endl;

}

void lecture5()
{
	Date date1; // 디폴트 생성자의 초기화
	date1.ShowDate();

	Date date2 = Date(15, 8, 2024);
	// 2024-08-16
	date2.ChangeDay(16);
	date2.ShowDate();
	
	Date date3;
	date3.ChangeDate(2024, 4, 18);
	date3.ShowDate();
	// 함수를 이용해서 멤버의 값을 변경하는 것과 
	// 멤버 변수에 직접 접근해서 변경하는 것은 크게 차이점이 없지 않나요?

	Patient pa; // 환자 한명을 선언합니다.
	Capsule100 capsule;
	pa.TakeCapsule(capsule);

	// 사각형 클래스 호출
	Rectangle rect1;
	rect1.ShowRectinfo();






}
