/*
*  학습 목표 : C++ 언어 학습. C언어에서 배운 내용을 복습한다.
*  작성일 : 2024-08-08
*  작성자 : 박종현
*/

/*
*  Hello World 출력 해주는 함수 <- 입출력 함수 : <stdio.h> printf, scanf
*  Hello World 출력 해주는 함수 <- 입출력 함수 : <iostream> cout, cin
*  cout : 출력 함수
*  사용법 : std::cout << "Hello World"<< std:: endl
*  cin : 입력 함수
*  int num;
*  사용법 std::cin>> num ;
*/

/*
*  1. std::cout << "  " 이 형태를  이해하기 위헤서 앞에서부터 살펴보자
*  std:: 문법을 이해해보자
*  namespace 이름 공간이 무엇인가? 어떤 정의된 객체가 어디에 소속되어 있는지 알려주는 것
*  std는 c++ standard library에 등록된 함수들 C++ 표준 라이브러리의 모든 함수가 정의된 이름 공간
*/

/*
*  함수, 변수를 작성을 하는데, 다른 사람이 쓴 코드를 가쪄다 쓰면서 증복된 이름을 가진 함수를 사용할 확률이 높아집니다.
*  C++ 문법에서 이를 구분하기 위해서 namespace라는 문법을 제공합니다.
*  사용법 namespace (이름공간)이름{ } : 이름공간.-이름 이름공간-이름
*/

/*
*  범위 지정 연산자 '::'
*  사용법 : 이름공간 :: 변수 또는 함수;
*  이름 공간안에 있는 변수 또는 함수를 사용할 수 있다.
*  만약에 namespace가 너무 길어서, 편리하게 쓰는 방법
*  using 키워드 
*  using TodaysIsThursDay :: num;
*/

/* 
*  1. 변수 : int, char, float, double
*  2. 반복문, 조건문 : for반복문, while반복문, if, switch조건문
*  3, 포인터(변수) : int*, char*, &num, &a1, *num,* a1
*/


#include "lectures.h"
#include "cstring"
 //using TodaysIsThursDay::num; // num 이름만 이름 공간에서 사용한다
 //using namespace TodaysIsThursDay; // 모든 변수 또는 함수를 이름 공간에서 가져간다.
// 이 페이지안에서 사용하는 모든 변수 또는 함수는 using namespace 이름을 사용해라.
// 장점 : 이름이 긴 namespace를 굳이 입력안해도된다.
// 단점 : namespace 안에 변수와 함수가 많을 수록, 다른 함수 또는 변수와 이름이 겹치는 경우가 생긴다.

// 사용 추천안
// usingnamespace를 이용해서 모든 변수를 참조하는 방식은 지양해라
// 필요한 함수만 필요한 변수만 지정해서 사용해라

// std:: cout -> cout 사용할 수 있게끔 using문을 사용해서 만들어라

using std::cout;
using std::endl;

namespace CPP
{
	void Sample()
	{
		std::cout << "Sample!" << endl;
	}
}
namespace CPP2
{
	void Sample()
	{
		std::cout << "Sample2!" << endl;
	}
}
namespace JH
{
	char name[30];
	void PrintName()
	{
		std::cout << "제 이름은 " << name << "입니다.\n";
	}
}

namespace TodaysIsThursDay
{
	int num;
	int num2;
}

// std::in namespace사용해보기
// 숫자 맞추기 간단히 구연해보기


void lecture1()
{
	cout << "Hello World!" <<  endl;
	cout << "Hello World!\n";

	CPP::Sample();

	// ::의 앞에 이름이 나오면 namespace 이다
	// std는 namespace이다. : c++ 표준 라이브러리의 namespace이다

	strcpy_s(JH::name, 30, "박종현");
	JH::PrintName();
	cout << "박종현\n";

	int a1;
	// scanf_s("%d",&a1); :: c언에어서 입력받은 방법
	cout << "입력 받을 수를 입력해주세요 : ";
	std::cin >> a1;
	std::cout << "입력받은 수 : " << a1<<endl;

	// int형 변수 LuckyNumber 선언 = 5
	// c++ 출력 함수 "나의 숫자를 맞추어 보세요"<<std::endl;
	// int UserInput 선언을 해줍니다
	// c++ 입력함수 UserInput에 데이터를 받아주세요

	// if함수를 사용해서 luckyNumber와 UserInput이 같으면
	// c++ 출력 함수 "정답을 맞추었습니다." 개행기능추가
	// if 함수를 써서 다르다면 
	// c++ 출력함수 "오답입니다. 다시 입력해주세요."

	int LuckyNumber = 4;
	int UserInput;
	cout << "나의 숫자를 맞추어 보세요" << endl;
	
	while (1)
	{
		std::cin >> UserInput;

		if (LuckyNumber == UserInput)
		{
			cout << "정답을 맞추었습니다."<<endl;
			break;
		}
		if (LuckyNumber != UserInput)
		{
			cout << "오답 입니다. 다시 입력해주세요." << endl;
		}
	}

}
