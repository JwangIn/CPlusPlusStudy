/*
*  �н� ��ǥ : C++�� ����ü �� ����ü ������ �����ϱ�
*  Pet Management Game
*  �ۼ��� : 2024-08-12
*  �ۼ��� : ������
*/
#include "lectures.h"
#include <cstdio>

// typedef : ������ �ۼ��Ǵ� ������ Ÿ���� �ڿ� �̸����� �������� �����ִ� ��

// ����ü ������ ����ؼ�
// cin �Լ��� ����ؼ� ���� �̸��� �޾ƿͼ� ������� ����ü�� �����ϴ� ��� (���̵� :1 )

// 1. �� �����ϱ�
// userInput�� ������ ���� �Ҵ����� ���ο� ���� ����


// Dog�� �̸�, Happy(int), Hungry(int) : ��ġ���� ���� 100�� �ִ�ġ�̴�.
// Dog ����ü�� ����ϴ� �Լ��� ��������

// play(Dog& dog)
// Happy + 10; Hungry -5 ;

// Feed(Dog& dog);
// Happy + 5 Hungry + 10;

// DayEnd(Dog& dog);
// Happy Hungry;

// ShowStatus(Dog& dog);

// ���� ���� ȭ�� -> ���� ���� -> �̸��Է�

// ���� �÷��� ȭ�� -> 1���� -> ���� ���� ���� -> �÷����� �Է�
// 1. ����ֱ� 2. �����ֱ�

// �� ���α׷����� ��, ����� �� �� ����ü�� �߰��غ��ƶ�.

// ���� ������ ����� ���õ� �Լ�
// ����̴� Play�� ��� ������ Ȯ���� ����

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
	std::cout << "1.������ �����մϴ�."<<std::endl;
	std::cout << "2.������ �����մϴ�." << std::endl;
	std::cout << "1 �Ǵ� 2�� �Է����ּ���." << std::endl;
	std::cin >> UserPick;
	if (UserPick == 1)
	{
		std::cout << "�Բ��� ������ �������ּ���." << std::endl;
		std::cout << "1. ������  2. �����  3. ��" << std::endl;
		std::cin >> UserPick;
	}
	else if (UserPick == 2)
	{
		exit(1);
	}


}


// Pet(dog,cat,bird ...) C++�÷���


void ShowStatus(Dog& dog,int& CurrentDay)
{
	std::cout << "���� ��¥ : " << CurrentDay << std::endl;

	std::cout << "���� �̸� : " << dog.name << std::endl;
	std::cout << "�ູ�� : " << dog.happy << std::endl;
	std::cout << "��� : " << dog.hungry << std::endl;
}

void ShowStatus(Bird& bird, int& CurrentDay)
{
	std::cout << "���� ��¥ : " << CurrentDay << std::endl;

	std::cout << "���� �̸� : " << bird.name << std::endl;
	std::cout << "�ູ�� : " << bird.happy << std::endl;
	std::cout << "��� : " << bird.hungry << std::endl;
	std::cout << "������ : " << bird.Free << std::endl;
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
	srand(time(NULL)); // �õ带 ����� �ִ� �Լ�
	int randomNumber = rand() % 100;  // 1~100 ���� ���� �޾ƿ�����

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
		std::cout << "���� Ż���߽��ϴ�.";
		exit(1);
	}

	bird.happy += 10;
	bird.hungry -= 5;
}

void makepet(Dog& dog)
{
	std::cout << "���� �̸��� �Է����ּ���. : ";
	std::cin >> dog.name;
	dog.happy = 100;
	dog.hungry = 100;
}

void makepet(Bird& bird)
{
	std::cout << "���� �̸��� �Է����ּ���. : ";
	std::cin >> bird.name;
	bird.happy = 100;
	bird.hungry = 100;
	bird.Free = 50;
}

void lecture3()
{
	// ����ü ����
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
			system("cls"); // �ܼ� Ŭ���� ��ɾ�
			ShowStatus(dog, currentday);
			int userinput;
			std::cout << "�ൿ�� �������ּ���." << "��" << std::endl;
			std::cout << "1.����ֱ�." << std::endl;
			std::cout << "2.�����ֱ�." << std::endl;

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
			system("cls"); // �ܼ� Ŭ���� ��ɾ�
			ShowStatus(bird, currentday);
			int userinput;
			std::cout << "�ൿ�� �������ּ���." << "��" << std::endl;
			std::cout << "1.����ֱ�." << std::endl;
			std::cout << "2.�����ֱ�." << std::endl;
			std::cout << "3.�������ֱ�" << std::endl;

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






	// ����ü ������
	Dog* dogPtr = &dog; // ù��° ���. ����ü �����͸� ������ �Ŀ� ������ �ּҿ����ڷ� �Ҵ��ϱ�.

	// ���� �Ҵ� (memory allocation : �޸� �Ҵ�)
	// C++�� ���� �Ҵ� : new ������Ÿ��();
	// ���� �Ҵ� ���� : delete �������̸� ;
	Dog* dogPtr2 = new Dog();
	dogPtr2->name;   // (*dogPtr2).name ���� �ڵ�� ���� ��
	strcpy_s((dogPtr2->name), 30, "ġ��");
	std::cout << "����ü �����Ͱ� ����Ű�� �̸� : " << dogPtr2->name << std::endl;

}

// Play, Feed, ShowStatus�Լ� ���� Dog, Cat
// Dog hungry, Happy �������ִ� �Լ�, dog ��ü�� �Լ��� �����Ų��.
// dog.play(); dog.feed();

// ���� 
// 1. Dog ����ü�� ��� �Լ��� ǥ���� �� ������. -> Dog,Cat,Bird ����� ����ü�� �ϳ��� ǥ���ϴ� ����� ������
// 2. ���ο� ����� �߰��ϱ� ���ؼ��� Dog,Bird,Cat �Լ��� �����ε� => Play(pet& pet);
// 3. pet.play(); ǥ���� �ϴ� ����� �� �ڿ�������.
// 4. struct �������� ���� �ʱ�ȭ �Լ��� �ʿ��ϴ�. �ʱ�ȭ �Լ��� ���� ������ �ʰ� ���������� ���������� ������?
// Ŭ���� ������ ���� �˾ƺ���!

