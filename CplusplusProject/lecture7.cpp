#include "lectures.h"

/*
*  학습목표 : 연산자 오버로딩
*  작성일 : 2024-08-19
*  작성자 : 박종현 
*/

/*
*  #include <iostream>
*  istream(입력 스트림), out stream(출력 스트림)
*  콘솔 창에 입출력을 구현하였다.
*  cout << : c언어에서 비트 연산자로 사용되었는데, cout << 비트 연산과 관련이 있나요?
*  cin >> : c언어에서 비트연산자로 사용되었는데, cin >> 비트 연산과 관련이 있나요?
*/

/*
*  구조체, 클래스 : 사용자 정의형 자료형
*  클래스와 클래스 사이에 산술연산자가 사용이 가능한가?
*  에러 -> 해당하는 피연산자가 없습니다.
*  해결 : 해당하는 연산자를 만들어주면된다. -> 연산자 오버로딩으로 클래스에 직접 정의하는 것이다.
*/

/*
*  연산자 오버로딩 : 기본 연산자들 (+,-,*,/,[],<<,>>)들을 사용자가 클래스에 직접 정의하는 것이다.
*  (반환값)(키워드)(연산자)()
*  예시 : void operator+();
*/

/*
*  전역 함수 오버로딩 : 
*  - 멤버 함수를 통한 오버로딩 : 객체.operator+(피연산자) : 객체 + 피연산자 식으로 이루어저 있다.
*  - 연산자 기준으로 객체가 반드시 왼쪽에 있어야한다.
*  p1 + 10; ( o )
*  10 + p1; ( x )
*  전역 함수 오버로딩은 operator+(피연산자, 피연산자) 피연산자 + 피연산자 식으로 객체가 뒤에 위치해도 정상적인 결과를 출력합니다.
*  피연산자 + 피연산자 = operator+(피연산자, 피연산자)
*/

/*
*  friend 함수 
*  클래스의 멤버 함수가 아니면서 해당 클래스의 private 데이터를 접근할때 사용하는 함수입니다.
*  클래스에 속하지 않지만, 이 클래스 안에 있는 데이터를 사용하고 싶었을 때 사용하는 키워드
*  단점 : private,public -> private을 이용해서 외부에서 수정을 못하게 하기 위해서 정보 은닉 무시하는 문법.
*  장점 : 연산자 오버로딩을 사용해서 범용적인 함수를 만들 수 있다.
*  결론 : 연산자 오버로딩 이외에 friend 키워드를 사용하는 것은 지양한다.
*/

/*
*  단황 연산자 오버로딩 : 증감 연산자
*  ++ : num + 1;
*  -- : num - 1;
*  ++num : 전위 증가 연산
*  num++ : 후위 증가 연산
*/


class Point
{
private:
	int posX, posY;
public:
	Point(){}            // 디폴트 생성자
	Point(int x, int y)  // 생성자 오버로딩
	{
		posX = x;
		posY = y;
	}
	void ShowPosition()
	{
		std::cout << "posX : " << posX << ", posY : " << posY << std::endl;
	}
	Point operator+(Point& ref)
	{
		return Point(posX + ref.posX, posY + ref.posY);
	}
	Point operator-(Point& ref)
	{
		return Point(posX - ref.posX, posY - ref.posY);
	}

	Point operator+(int value)
	{
		return Point(posX + value, posY + value);
	}

	friend Point operator+(int num, Point ref);  // 전역 함수 연산자 오버로딩

	Point operator++()   // 전위 증가 연산자 ++p1;
	{
		posX += 1;
		posY += 1;
		return *this;  // 자기 자신을 객체로 변환한다.
	}
	Point operator++(int) // 후위 증가 연산자 p1++;
	{
		Point temp(*this); // 복사 생성자 : 얕은 복사로 데이터가 이동한다.
		posX += 1;
		posY += 1;
		return temp;
	}
};

Point operator+(int num, Point ref)
{
	ref.posX += num;
	ref.posY += num;
	return ref;
}



// 이름과 성적이 포함되어 있는 클래스를 만들겁니다.
// Math + English -> 수함점수 : m1 영어점수 : e1;

class Eng; // Eng 클래스가 존재한다고 명시해주기위해
class Math
{
	char name[15];
	int score;

	friend int Add(Math m1, Eng e1);
public:
	Math(){} // 생성자를 직접 정의하면 디폴트 생성자가 자동으로 생성되지 않기 때문에 명시적으로 생성
	Math(const char* _name, int _score)
	{
		strcpy_s(name, 15, _name);
		score = _score;
	}
};

class Eng
{
	char name[15];
	int score;

	friend int Add(Math m1, Eng e1);
public:
	Eng() {}
	Eng(const char* _name, int _score)
	{
		strcpy_s(name, 15, _name);
		score = _score;
	}
};

/*
int Add(Math m1, Eng e1)
{
	std::cout << "이름 : " << m1.name << ", 수학 점수 : " << m1.score << ", 영어 점수 : " << e1.score << std::endl;
}
*/
int Add(Math m1, Eng e1)
{
	return m1.score + e1.score;
}

// <iostream> istream ostream
/*
*  ostream& operator<<(std::ostream& out,int& val);
*  {
*      printf("%d",val);
*      return out;
*  }
*  
*  ostream& operator<<(std::ostream& out, const char* val)
*  {
*      printf("%s",val;
*  }
* 
*  ostream& operator<< (std::ostream& out)
*  {
*      printf('\n');
*  }
*/

/*
*  istream& operator>>(std::istream& in, int& val)
*  {
*      int some;
*      scanf(val, some);
*      return in;
*  }
*/

// c언어 int -> printf("%d",num);



void lecture7()
{
	Point p1(1, 1);
	Point p2(2, 3);
	
	Point result = p1 + p2; // 연산자와 일치하는 "+" 연산자가 없습니다.
	// Point p1 + Point p2 => p1.operator+(Point& ref);
	Point minus = p1 - p2;
	// p1-p2 => p1.operator-(p2);

	p1.ShowPosition();
	p2.ShowPosition();
	result.ShowPosition();
	minus.ShowPosition();

	Point plusWithNum = p1 + 10; // (p1.posX + 10,p1.posY +10);
	// p1.operator+(int value =10)
	plusWithNum.ShowPosition();

	Point NumPlusPoint = 10 + p1;
	// (int + Point) 10 + p1 -> Point operator(int num,Point p1);
	// 10.operator+(Point& p1);
	NumPlusPoint.ShowPosition();

	Point p3(3, 3);
	++p3;
	p3.ShowPosition();
	
	Point p4(5, 5);
	p4++;
	p4.ShowPosition();

	system("cls");
	std::cout << "예제 문제 풀이 " << std::endl;

	Math m1("수학", 90), m2("수학", 80);
	Eng e1("영어", 70), e2("영어", 99);
	Add(m1, e1);

	std::cout << "수학 + 영어 총합 : " << Add(m1, e1);

	// 만약에 연산자 오버로딩 문법을 지원해주지 않는다면?
	// Add(m1,e1)
	

}