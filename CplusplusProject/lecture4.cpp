/*
*  학습 목표 : 첫 클래스 선언. 함수 오버로딩과 생성자에 대한 이해
*  작성일 : 2024-08-13
*  작성자 : 박종현
*/

#include "lectures.h"

/*
*  클래스 선언
*  클래스(class) : 객체 - 프로그래밍 언어로 세상에 존재하는 모든 대상을 표현하는 것
*/

// 1. 객체가 함수를 실행하는 것이 더 보기에 직관적이다.
// struct 구조체 함수를 내부에 포함할 수 가 없었습니다.
// 클래스 내부에 함수를 포함해서 사용을 할 수 있습니다.

class Dog 
{
private:
	int happy;
	int hungry;
	char name[30];

public:
	Dog();
	Dog(int happy,int hungry);
	void Play(); // 첫 번째 방법으로 class 안에 선언하는 방법이 있으나 너무 길어저서 다른 방법을 사용함
	void Feed();
	void ShowStatus();
	void MakeDog();
};

// 범위 지정자 이름공간 :: // namespace안에 있는 함수를 사용하겠다.
// 클래스 :: 함수 이름 // 클래스 안에 있는 함수를 사용하겠다 라는 뜻이된다.

Dog::Dog() // 생성자 
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "뽀삐");
}

Dog::Dog(int happy, int hungry) // 인자로 받는 것 앞에 '_'를 붙이거나 this->를 사용하기 // 생성자 오버로드
{
	std::cin >> name;

	this->happy = happy;
	this->hungry = hungry;
}

void Dog::Play()
{
	happy += 10;
	hungry -= 5;
}

void Dog::Feed()
{
	happy += 5;
	hungry += 5;
}

void Dog::ShowStatus()
{
	std::cout << "개의 이름 : " << name << std::endl;
	std::cout << "개의 행복도 : " << happy << std::endl;
	std::cout << "개의 허기 : " << hungry << std::endl;
}
/// <summary>
/// Dog의 초기화 함수이므로 반드시 변수의 선언과 함께 사용되야한다.
/// </summary>
void Dog::MakeDog()
{
	std::cin >> happy;
	std::cin >> hungry;
	std::cin >> name;
}

/*
*  함수 오버로딩(overloading) : 1. 과적하다. 2. 과부하에 걸리게 하다.
*  
*  void Add(int a,int b); a + b;
*  void Add(float a, floatb); a + b;
*  void Add(double a,double b);
*  void Add(char a, char b);
*  void Add(Dog dog1,Dog dog2); dog1.happy + dog2.happy
*/

/*
*  함수 오버로딩 사용시에 주의해야할 사항
*  1. 컴파일러가 함수를 구별하는 방식은 (1) 함수의 이름 (2) 이낮의 데이터 타입
*     void Add(int a);
*     void Add(int b);
*     void Add();
*  2. void Print(int x);
*     void Print(char x);
*     void Print(double x);
*/

void Print(int x)
{
	std::cout << "int x : " << x << std::endl;
}
void Print(char x)
{
	std::cout << "char x : " << x << std::endl;
}
void Print(double x)
{
	std::cout << "double x : " << x << std::endl;
}


/*
*  클래스 생성자 : 클래스를 선언한 후에 초기화 함수를 강제로 호출시키는 기능
*  
*  Dog dog1; // default 생성자가 호출됩니다.
* 
*  default : 숫자 데이터들은 0으로 초기화 시킨다. int* 주소 데이터들을 nullPtr;
*/


void lecture4()
{
	// Play(); C언어에서 함수 호출 방법 X
	// Dog::Play(); 특별한 문법 static을 사용하지 않는 이상 X
	
	// 생성자, 구조체 처음 변수를 선언하고 나서 데이터를 초기화하지 않으면 이상한 데이터가 출력되는 문제가 있다.
	// MakeDog 초기화 함수를 반드시 가장 먼저 실행을 해줘야한다.

	Dog dog1;
	//dog1.MakeDog(); // 문법적으로 반드시 강제하는 기능이 생성자이다.
	dog1.ShowStatus();

	
	// case1. 함수 오버로딩에 인자를 만들어준 타입
	int a = 1;
	char b = 'b';
	double c = 1.1;
	Print(a);
	Print(b);
	Print(c);
	// case2. 함수 오버로딩에 없는 인자
	short s1 = 2;
	float f1 = 2.2f;
	Print(s1);
	Print(f1);

	// 함수의 이름은 존재하는데, 데이터 타입은 없는 경우.
	// 컴파일러가 어떻게 행동하는가 ?
	// 1. 데이터 타입이 없으면 형변화를 시도한다.
	// 2. 명시적 형변환, 묵시적 형변환이 있는데 묵시적 형변환이 발생하고 있다.
	// 3. 정수형 데이터 타입 -> int형으로 변환을 시도한다. 실수형 데이터 타입 ->double형으로 변환 시도, float 형으로 변환시도
	// 4. 정수형 데이터 타입이 없을 경우에 실수형 데이터 타입을 정수형으로 바꾸어서 형 변환을 시도한다.

	// float -> 정수형 데이터 타입으로 변환을 해야하는데..  int를 받는 함수, char를 받는 함수 둘 중 무엇을 선택해야 될지 모르기 때문에 에러가 발생
	// 오버로드된 함수가 인스턴스 중 두개 이상의 인수 목록과 일치한다.

	// 정리 
	// 컴파일러는 우리가 알게 모르게 잘못된 코드도 정상적으로 처리되도록 일을 하고 있었다.
	// 1. 데이터 타입이 정의되지 않았는데 사용했다. = 타입이 오버로딩으로 정의 되지 않았어도 사용이 가능하다.
	// 2. 실수형 데이터 타입을 선언하지 않고 정수형 데이터 타입을 두 개 이상 선언했다.

	// 생성자의 선언 
	Dog dog2;          // 디폴트 생성자가 호출된다.
	dog2.ShowStatus();
	Dog dog3 = Dog();  // 디폴트 생성자가 호출된다.
	dog3.ShowStatus();

	int doghappy;
	std::cin >> doghappy;
	int doghungry;
	std::cin >> doghungry;
	
	Dog dog4 = Dog(doghappy,doghungry);
	dog4.ShowStatus();
	

	// 아래 코드는 현재 문제가 있는 코드이지만, 작성을하여 실행해보세요
	Dog dog5 = dog4;
	dog5.ShowStatus();

	Dog* dogs[100];
	dogs[0] = new Dog();
	dogs[0]->ShowStatus();
	delete dogs[0];
	dogs[1] = dogs[0];
	dogs[1]->ShowStatus();

}