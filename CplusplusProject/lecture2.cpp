/*
*  학습 목표 : C언어 포인터 C++에서 활용버, 참조자(Reference)에 대한 이해
*  작성일 : 2024-08-09
*  작성자 : 박종현
*/

#include "lectures.h"
#include <cstdio>
#include <cstring>

/*
*  C언어에서 포인터를 사용하는 이유?
*  함수를 사용하면서 함수 안에서 데이터를 변경하려면 포인터를 인자로 념겨줘야했다.
*/

/*
*  함수를 사용할 때 포인터가 아닌 참조자를 사용하면 인자로 &(주소연산자를) 사용하지 않을 수 있다.
*  주소 선언 : int*
*  참조자 선언 : int& 참조자 이름 = 참고하고자 하는 변수;
*  int a;
*  int& AnotherA = a;
*/


void SwapInt(int* a, int* b)
{
	int temp;
	temp = *a;
	 *a = *b;
	 *b = temp;
}


// 함수 오버로딩 : c언어는 함수의 이름으로 함수를 구별한다. 그런데 C++는 함수의 이름 + (매게변수, 인자)로 구별한다

void SwapInt(int& a,int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ChangeValue(int& p)
{
	// p의 값을 10으로 변경하는 코드로 
	p = 10;
}

int Function() // int 를 반환하는 함수
{
	int a = 2;
	return a;
}

// 참조자를 리턴하는 함수
// 지역변수를 리턴하지 않도록 해야한다.
int& Function2()
{
	int a = 2;
	return a;

}

int& Function3(int& a)
{
	a = 2;
	return a;
}

// 정수형 레퍼런스를 반환하는 함수를 하나 만들어 주세요.
// Human구조체를 레퍼런스로 반환하는 함수를 하나 만들어주세요ㅕ
// 
// Human 데이터를 받는 함수
// Human& AddHumanInfo(Human& Human)	
// Void PrintHumanInfo

typedef struct Human
{
	char name[30];
	int age;
}Human;

/*void AddHumanInfo(Human& human)
{
	std::cout << "이름을 입력해주세요. : ";
	std::cin >> human.name;
	std::cout << "나이를 입력해주세요. : ";
	std::cin >> human.age;
}
void PrintHumanInfo(Human& human)
{
	std::cout << human.name << " " << human.age << "살" << std::endl;
}
*/
Human& AddHumanInfo(Human& human)
{
	strcpy_s(human.name, 30, "이순신");
	human.age = 30;
	return human;
}
Human& PrintHumanInfo(Human& human)
{
	std::cout << human.name << " " << human.age << "살" << std::endl;
	return human;
}
/*
void AddHumanInfo(Human* human)
{
	printf("이름 : ");
	scanf_s("%s", human->name,30);
	scanf_s("%d", human->age);
}
void PrintHumanInfo(Human* human)
{
	printf("%s %d", human->name, human->name);
}
*/


void lecture2()
{
	// C언어 포인트

	int num = 10; // num변수 10이라는 정수, 주소
	int* numPtr=&num; // 포인터(변수);

	// C언어와 비교했을 때 C++는 데이터와 형태를 명시하지 않아도 작동한다.편리하다.

	std::cout << "포인트의 주소 : " << numPtr << std::endl;
	std::cout << "포인트가 가르키는 값 : " << *numPtr << std::endl;

	// 변수의 이름 규칙
	int number_of_people; // 단어와 단어사이를 '_' 표현하고 있다 // snake방식 (뱀)
	int NumberOfPeople;  // 띄어쓰기를 할 때 대문자로 표현한다.  // camel방식 (낙타)

	// 주의해야할 사항. 두방식을 같이 혼동해서 쓰지 말 것
	// 1. 변수의 이름 규칙을 하나로 통일해서 쓰는 것
	// 2. 두 방식을 섞어서 쓰지 말 것

	int num1 = 1, num2 = 2;

	SwapInt(&num1, &num2);

	std::cout << "num1의 값 : " << num1 << std::endl << "num2의 값 : " << num2 << std::endl;

	// 참조자 만드는 법
	// 참조자 : 변수의 별명

	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1; // AnotherA1은 a1의 별명이다.

	std::cout << "AnotherA1의 값 : " << AnotherA1 << std::endl;

	// 참조자 왜 써야하나?
	// -> Primitive type
	// 구조체의 크기는 사용자 정의형이기 때문에 작성자에 따라서 크기가 달라진다.
	// 참조자도 마찬가지로, 참조자가 가르키는 주소를 한번 복사하면 8바이트(64비트 시스템에서) 만으로 구조체를 복사해서 쓸 수 있다.

	// 참조자와 포인터가 다른 부분
	// 포인터는 주소 연산자를 인자로 받게 해야된다. 사용자가 함수와 포인터에 대한 이해도가 있어야한다.
	// 참조자는 주소 연산자를 인자로 받는가? 안받는다. 사용자가 더 편리한 문법이다.

	

	int c_num2;
	std::cin >> c_num2;
	std::cout << "c_num2의 값 : " << c_num2 << std::endl;

	// 참조자 (Reference) 함수에서 사용하는 방법 

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num_1의 값 : " << d_num1 << std::endl << "d_num2의 값 : " << d_num2 << std::endl;

	// 참조자는 반드시 선언과 동시에 초기화를 해야 한다.
	// 참조자는 선언할 때 상대의 주소를 가져와서 복사한다
	int& AnotherDNum1=d_num1;

	// int& Literal = 100; // 참조자는 리터럴 상수를 가르키지 못한다.

	const int& Litteral = 100; // 참조자는 const 키워드를 통해서 상수를 가르킬 수 있다.

	int p=4;
	ChangeValue(p);

	std::cout << "ChangeValue의 값 : " << p << std::endl;

	// 참조자(레퍼런스)를 리턴하는 함수 

	int p2 = 5;

	int tempA = Function(); // tempA function안에 있는 a의 값을 복사해서 대입한다.
	int tempB = Function3(p2);

	// ★★ 레퍼런스 타입을 리턴할 때는 반드시 지역변수를 반환하지 않도록 주의 해야한다.★★

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	// int& AnotherTemp = Function(); // 안됨
	const int& AnotherTemp = Function();
	// int& AnotherTemp2 = Function2(); // 컴파일러마다 환경이 다르지만, 컴파일에러가 발생한다.

	// 함수에서 값을 리턴할 때
	// int a = Function(); a=2; 2라는 값을 a에 대입한다. 값의 복사가 이루어젔다. 사용 가능 
	// int& a = Function(); 참조자 타입으로 리터럴 상수를 가르킬 수 없다. 컴파일러 에러가 사용한다.
	// const int& a =Function(); 참조자가 리터럴을 가르키게 하고 싶으면  const 키워드를 사용한다.
	// 단, const 수식받는 a 참조자는 가능하다.

	// (2) 함수가 참조자를 리턴할 때 int& Function();
	// ★★ 레퍼런스 타입을 리턴할 때는 반드시 지역변수를 반환하지 않도록 주의 해야한다.★★


	Human human;

	AddHumanInfo( human);
	PrintHumanInfo(human);



}