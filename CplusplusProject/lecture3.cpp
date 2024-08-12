/*
*  학습 목표 : C++로 구조체 및 구조체 포인터 복습하기
*  Pet Management Game
*  작성일 : 2024-08-12
*  작성자 : 박종현
*/
#include "lectures.h"
#include <cstdio>

// typedef : 다음에 작성되는 데이터 타입을 뒤에 이름으로 별명으로 지어주는 것

// 구조체 변수를 사용해서
// cin 함수를 사용해서 개의 이름을 받아와서 만들어진 구조체에 복사하는 방법 (난이도 :1 )

// 1. 펫 생성하기
// userInput을 받으면 동적 할당으로 새로운 개를 생성


// Dog는 이름, Happy(int), Hungry(int) : 수치들은 각각 100이 최대치이다.
// Dog 구조체를 사용하는 함수를 만들어보세요

// play(Dog& dog)
// Happy + 10; Hungry -5 ;

// Feed(Dog& dog);
// Happy + 5 Hungry + 10;

// DayEnd(Dog& dog);
// Happy Hungry;

// ShowStatus(Dog& dog);

// 게임 시작 화면 -> 개를 생성 -> 이름입력

// 메인 플레이 화면 -> 1일차 -> 현재 개의 상태 -> 플레이의 입력
// 1. 놀아주기 2. 먹이주기

// 이 프로그램에서 새, 고양이 이 두 구조체를 추가해보아라.

// 새는 공중을 비행과 관련된 함수
// 고양이는 Play할 경우 실패할 확률이 있음

typedef struct Dog
{
	char name[30];
	int happy;
	int hungry;
}Dog;

typedef struct Bird
{
	char name[30];
	int happy;
	int hungry;
	int Free;
}Bird;

typedef struct Cat
{
	char name[30];
	int happy;
	int hungry;
	int curious;
}Cat;




void GameStartMenu(int& UserPick)
{
	std::cout << "1.게임을 시작합니다."<<std::endl;
	std::cout << "2.게임을 종료합니다." << std::endl;
	std::cout << "1 또는 2를 입력해주세요." << std::endl;
	std::cin >> UserPick;
	if (UserPick == 1)
	{
		std::cout << "함께할 동물을 선택해주세요." << std::endl;
		std::cout << "1. 강아지  2. 고양이  3. 새" << std::endl;
		std::cin >> UserPick;
	}
	else if (UserPick == 2)
	{
		exit(1);
	}


}


// Pet(dog,cat,bird ...) C++플러스


void ShowStatus(Dog& dog,int& CurrentDay)
{
	std::cout << "진행 날짜 : " << CurrentDay << std::endl;

	std::cout << "개의 이름 : " << dog.name << std::endl;
	std::cout << "행복도 : " << dog.happy << std::endl;
	std::cout << "허기 : " << dog.hungry << std::endl;
}

void ShowStatus(Bird& bird, int& CurrentDay)
{
	std::cout << "진행 날짜 : " << CurrentDay << std::endl;

	std::cout << "새의 이름 : " << bird.name << std::endl;
	std::cout << "행복도 : " << bird.happy << std::endl;
	std::cout << "허기 : " << bird.hungry << std::endl;
	std::cout << "자유도 : " << bird.Free << std::endl;
}


void Play(Dog& dog)
{
	dog.happy += 10;
	dog.hungry -= 5;
}

void Feed(Dog& dog)
{
	dog.happy += 5;
	dog.hungry += 5;
}

void DayEnd(Dog& dog, int& CurrentDay)
{
	dog.happy -= 10;
	dog.hungry -= 10;
	CurrentDay++;
}


void Feed(Bird& bird)
{
	bird.hungry += 15;
}

void DayEnd(Bird& bird, int& CurrentDay)
{
	srand(time(NULL)); // 시드를 만들어 주는 함수
	int randomNumber = rand() % 100;  // 1~100 랜덤 숫자 받아오도록

	bird.happy -= 30;
	bird.hungry -= 10;
	bird.Free += randomNumber;
	CurrentDay++;
}

void FlyBird(Bird& bird, int& CurrentDay)
{
	bird.happy += 40;
	bird.hungry -= 30;
	bird.Free -= 50;
	CurrentDay += 3;
}

void Play(Bird bird)
{

	if (bird.Free >= 80)
	{
		std::cout << "새가 탈출했습니다.";
		exit(1);
	}

	bird.happy += 10;
	bird.hungry -= 5;
}

void makepet(Dog& dog)
{
	std::cout << "펫의 이름을 입력해주세요. : ";
	std::cin >> dog.name;
	dog.happy = 100;
	dog.hungry = 100;
}

void makepet(Bird& bird)
{
	std::cout << "펫의 이름을 입력해주세요. : ";
	std::cin >> bird.name;
	bird.happy = 100;
	bird.hungry = 100;
	bird.Free = 50;
}

void lecture3()
{
	// 구조체 선언
	Dog dog;
	Bird bird;
	int UserPick;

	GameStartMenu(UserPick);
	if(UserPick==1)
	{
		makepet(dog);
		int currentday = 1;
		int UserInput;

		while (true)
		{
			system("cls"); // 콘솔 클리어 명령어
			ShowStatus(dog, currentday);
			int userinput;
			std::cout << "행동을 선택해주세요." << "일" << std::endl;
			std::cout << "1.놀아주기." << std::endl;
			std::cout << "2.먹이주기." << std::endl;

			std::cin >> UserInput;
			if (UserInput == 1)
			{
				Play(dog);
			}
			else if (UserInput == 2)
			{
				Feed(dog);
			}

			DayEnd(dog, currentday);

			if (currentday >= 10)
				break;


		}
	
	}
	else if(UserPick == 3)
	{
		makepet(bird);
		int currentday = 1;
		int UserInput;

		while (true)
		{
			system("cls"); // 콘솔 클리어 명령어
			ShowStatus(bird, currentday);
			int userinput;
			std::cout << "행동을 선택해주세요." << "일" << std::endl;
			std::cout << "1.놀아주기." << std::endl;
			std::cout << "2.먹이주기." << std::endl;
			std::cout << "3.날개해주기" << std::endl;

			std::cin >> UserInput;
			if (UserInput == 1)
			{
				Play(bird);
			}
			else if (UserInput == 2)
			{
				Feed(bird);
			}
			else if (UserInput == 3)
			{
				FlyBird(bird, currentday);
			}

			DayEnd(bird, currentday);

			if (currentday >= 10)
				break;


		}
	}






	// 구조체 포인터
	Dog* dogPtr = &dog; // 첫번째 방법. 구조체 포인터를 선언한 후에 변수의 주소연산자로 할당하기.

	// 동적 할당 (memory allocation : 메모리 할당)
	// C++의 동적 할당 : new 데이터타입();
	// 동적 할당 해제 : delete 변수의이름 ;
	Dog* dogPtr2 = new Dog();
	dogPtr2->name;   // (*dogPtr2).name 앞의 코드와 같은 뜻
	strcpy_s((dogPtr2->name), 30, "치코");
	std::cout << "구조체 포인터가 가르키는 이름 : " << dogPtr2->name << std::endl;

}

// Play, Feed, ShowStatus함수 인자 Dog, Cat
// Dog hungry, Happy 변경해주느 함수, dog 객체가 함수를 실행시킨다.
// dog.play(); dog.feed();

// 정리 
// 1. Dog 구조체로 모든 함수를 표현할 수 없었다. -> Dog,Cat,Bird 공통된 구조체를 하나로 표현하는 방법이 없을까
// 2. 새로운 기능을 추가하기 위해서는 Dog,Bird,Cat 함수를 오버로딩 => Play(pet& pet);
// 3. pet.play(); 표현을 하는 방식이 더 자연스럽다.
// 4. struct 변수들은 따로 초기화 함수가 필요하다. 초기화 함수를 따로 만들지 않고 문법적으로 지원해주지 않을까?
// 클래스 문법을 통해 알아보자!

