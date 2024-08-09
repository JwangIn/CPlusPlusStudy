/*
*  �н� ��ǥ : C��� ������ C++���� Ȱ���, ������(Reference)�� ���� ����
*  �ۼ��� : 2024-08-09
*  �ۼ��� : ������
*/

#include "lectures.h"
#include <cstdio>
#include <cstring>

/*
*  C���� �����͸� ����ϴ� ����?
*  �Լ��� ����ϸ鼭 �Լ� �ȿ��� �����͸� �����Ϸ��� �����͸� ���ڷ� �������ߴ�.
*/

/*
*  �Լ��� ����� �� �����Ͱ� �ƴ� �����ڸ� ����ϸ� ���ڷ� &(�ּҿ����ڸ�) ������� ���� �� �ִ�.
*  �ּ� ���� : int*
*  ������ ���� : int& ������ �̸� = �����ϰ��� �ϴ� ����;
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


// �Լ� �����ε� : c���� �Լ��� �̸����� �Լ��� �����Ѵ�. �׷��� C++�� �Լ��� �̸� + (�ŰԺ���, ����)�� �����Ѵ�

void SwapInt(int& a,int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ChangeValue(int& p)
{
	// p�� ���� 10���� �����ϴ� �ڵ�� 
	p = 10;
}

int Function() // int �� ��ȯ�ϴ� �Լ�
{
	int a = 2;
	return a;
}

// �����ڸ� �����ϴ� �Լ�
// ���������� �������� �ʵ��� �ؾ��Ѵ�.
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

// ������ ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ����� �ּ���.
// Human����ü�� ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ������ּ����
// 
// Human �����͸� �޴� �Լ�
// Human& AddHumanInfo(Human& Human)	
// Void PrintHumanInfo

typedef struct Human
{
	char name[30];
	int age;
}Human;

/*void AddHumanInfo(Human& human)
{
	std::cout << "�̸��� �Է����ּ���. : ";
	std::cin >> human.name;
	std::cout << "���̸� �Է����ּ���. : ";
	std::cin >> human.age;
}
void PrintHumanInfo(Human& human)
{
	std::cout << human.name << " " << human.age << "��" << std::endl;
}
*/
Human& AddHumanInfo(Human& human)
{
	strcpy_s(human.name, 30, "�̼���");
	human.age = 30;
	return human;
}
Human& PrintHumanInfo(Human& human)
{
	std::cout << human.name << " " << human.age << "��" << std::endl;
	return human;
}
/*
void AddHumanInfo(Human* human)
{
	printf("�̸� : ");
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
	// C��� ����Ʈ

	int num = 10; // num���� 10�̶�� ����, �ּ�
	int* numPtr=&num; // ������(����);

	// C���� ������ �� C++�� �����Ϳ� ���¸� ������� �ʾƵ� �۵��Ѵ�.���ϴ�.

	std::cout << "����Ʈ�� �ּ� : " << numPtr << std::endl;
	std::cout << "����Ʈ�� ����Ű�� �� : " << *numPtr << std::endl;

	// ������ �̸� ��Ģ
	int number_of_people; // �ܾ�� �ܾ���̸� '_' ǥ���ϰ� �ִ� // snake��� (��)
	int NumberOfPeople;  // ���⸦ �� �� �빮�ڷ� ǥ���Ѵ�.  // camel��� (��Ÿ)

	// �����ؾ��� ����. �ι���� ���� ȥ���ؼ� ���� �� ��
	// 1. ������ �̸� ��Ģ�� �ϳ��� �����ؼ� ���� ��
	// 2. �� ����� ��� ���� �� ��

	int num1 = 1, num2 = 2;

	SwapInt(&num1, &num2);

	std::cout << "num1�� �� : " << num1 << std::endl << "num2�� �� : " << num2 << std::endl;

	// ������ ����� ��
	// ������ : ������ ����

	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1; // AnotherA1�� a1�� �����̴�.

	std::cout << "AnotherA1�� �� : " << AnotherA1 << std::endl;

	// ������ �� ����ϳ�?
	// -> Primitive type
	// ����ü�� ũ��� ����� �������̱� ������ �ۼ��ڿ� ���� ũ�Ⱑ �޶�����.
	// �����ڵ� ����������, �����ڰ� ����Ű�� �ּҸ� �ѹ� �����ϸ� 8����Ʈ(64��Ʈ �ý��ۿ���) ������ ����ü�� �����ؼ� �� �� �ִ�.

	// �����ڿ� �����Ͱ� �ٸ� �κ�
	// �����ʹ� �ּ� �����ڸ� ���ڷ� �ް� �ؾߵȴ�. ����ڰ� �Լ��� �����Ϳ� ���� ���ص��� �־���Ѵ�.
	// �����ڴ� �ּ� �����ڸ� ���ڷ� �޴°�? �ȹ޴´�. ����ڰ� �� ���� �����̴�.

	

	int c_num2;
	std::cin >> c_num2;
	std::cout << "c_num2�� �� : " << c_num2 << std::endl;

	// ������ (Reference) �Լ����� ����ϴ� ��� 

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num_1�� �� : " << d_num1 << std::endl << "d_num2�� �� : " << d_num2 << std::endl;

	// �����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �ؾ� �Ѵ�.
	// �����ڴ� ������ �� ����� �ּҸ� �����ͼ� �����Ѵ�
	int& AnotherDNum1=d_num1;

	// int& Literal = 100; // �����ڴ� ���ͷ� ����� ����Ű�� ���Ѵ�.

	const int& Litteral = 100; // �����ڴ� const Ű���带 ���ؼ� ����� ����ų �� �ִ�.

	int p=4;
	ChangeValue(p);

	std::cout << "ChangeValue�� �� : " << p << std::endl;

	// ������(���۷���)�� �����ϴ� �Լ� 

	int p2 = 5;

	int tempA = Function(); // tempA function�ȿ� �ִ� a�� ���� �����ؼ� �����Ѵ�.
	int tempB = Function3(p2);

	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� ���� �ؾ��Ѵ�.�ڡ�

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	// int& AnotherTemp = Function(); // �ȵ�
	const int& AnotherTemp = Function();
	// int& AnotherTemp2 = Function2(); // �����Ϸ����� ȯ���� �ٸ�����, �����Ͽ����� �߻��Ѵ�.

	// �Լ����� ���� ������ ��
	// int a = Function(); a=2; 2��� ���� a�� �����Ѵ�. ���� ���簡 �̷���. ��� ���� 
	// int& a = Function(); ������ Ÿ������ ���ͷ� ����� ����ų �� ����. �����Ϸ� ������ ����Ѵ�.
	// const int& a =Function(); �����ڰ� ���ͷ��� ����Ű�� �ϰ� ������  const Ű���带 ����Ѵ�.
	// ��, const ���Ĺ޴� a �����ڴ� �����ϴ�.

	// (2) �Լ��� �����ڸ� ������ �� int& Function();
	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� ���� �ؾ��Ѵ�.�ڡ�


	Human human;

	AddHumanInfo( human);
	PrintHumanInfo(human);



}