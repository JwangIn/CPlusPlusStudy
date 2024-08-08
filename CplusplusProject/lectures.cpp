/*
*  �н� ��ǥ : C++ ��� �н�. C���� ��� ������ �����Ѵ�.
*  �ۼ��� : 2024-08-08
*  �ۼ��� : ������
*/

/*
*  Hello World ��� ���ִ� �Լ� <- ����� �Լ� : <stdio.h> printf, scanf
*  Hello World ��� ���ִ� �Լ� <- ����� �Լ� : <iostream> cout, cin
*  cout : ��� �Լ�
*  ���� : std::cout << "Hello World"<< std:: endl
*  cin : �Է� �Լ�
*  int num;
*  ���� std::cin>> num ;
*/

/*
*  1. std::cout << "  " �� ���¸�  �����ϱ� ���켭 �տ������� ���캸��
*  std:: ������ �����غ���
*  namespace �̸� ������ �����ΰ�? � ���ǵ� ��ü�� ��� �ҼӵǾ� �ִ��� �˷��ִ� ��
*  std�� c++ standard library�� ��ϵ� �Լ��� C++ ǥ�� ���̺귯���� ��� �Լ��� ���ǵ� �̸� ����
*/

/*
*  �Լ�, ������ �ۼ��� �ϴµ�, �ٸ� ����� �� �ڵ带 ���Ǵ� ���鼭 ������ �̸��� ���� �Լ��� ����� Ȯ���� �������ϴ�.
*  C++ �������� �̸� �����ϱ� ���ؼ� namespace��� ������ �����մϴ�.
*  ���� namespace (�̸�����)�̸�{ } : �̸�����.-�̸� �̸�����-�̸�
*/

/*
*  ���� ���� ������ '::'
*  ���� : �̸����� :: ���� �Ǵ� �Լ�;
*  �̸� �����ȿ� �ִ� ���� �Ǵ� �Լ��� ����� �� �ִ�.
*  ���࿡ namespace�� �ʹ� ��, ���ϰ� ���� ���
*  using Ű���� 
*  using TodaysIsThursDay :: num;
*/

/* 
*  1. ���� : int, char, float, double
*  2. �ݺ���, ���ǹ� : for�ݺ���, while�ݺ���, if, switch���ǹ�
*  3, ������(����) : int*, char*, &num, &a1, *num,* a1
*/


#include "lectures.h"
#include "cstring"
 //using TodaysIsThursDay::num; // num �̸��� �̸� �������� ����Ѵ�
 //using namespace TodaysIsThursDay; // ��� ���� �Ǵ� �Լ��� �̸� �������� ��������.
// �� �������ȿ��� ����ϴ� ��� ���� �Ǵ� �Լ��� using namespace �̸��� ����ض�.
// ���� : �̸��� �� namespace�� ���� �Է¾��ص��ȴ�.
// ���� : namespace �ȿ� ������ �Լ��� ���� ����, �ٸ� �Լ� �Ǵ� ������ �̸��� ��ġ�� ��찡 �����.

// ��� ��õ��
// usingnamespace�� �̿��ؼ� ��� ������ �����ϴ� ����� �����ض�
// �ʿ��� �Լ��� �ʿ��� ������ �����ؼ� ����ض�

// std:: cout -> cout ����� �� �ְԲ� using���� ����ؼ� ������

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
		std::cout << "�� �̸��� " << name << "�Դϴ�.\n";
	}
}

namespace TodaysIsThursDay
{
	int num;
	int num2;
}

// std::in namespace����غ���
// ���� ���߱� ������ �����غ���


void lecture1()
{
	cout << "Hello World!" <<  endl;
	cout << "Hello World!\n";

	CPP::Sample();

	// ::�� �տ� �̸��� ������ namespace �̴�
	// std�� namespace�̴�. : c++ ǥ�� ���̺귯���� namespace�̴�

	strcpy_s(JH::name, 30, "������");
	JH::PrintName();
	cout << "������\n";

	int a1;
	// scanf_s("%d",&a1); :: c�𿡾 �Է¹��� ���
	cout << "�Է� ���� ���� �Է����ּ��� : ";
	std::cin >> a1;
	std::cout << "�Է¹��� �� : " << a1<<endl;

	// int�� ���� LuckyNumber ���� = 5
	// c++ ��� �Լ� "���� ���ڸ� ���߾� ������"<<std::endl;
	// int UserInput ������ ���ݴϴ�
	// c++ �Է��Լ� UserInput�� �����͸� �޾��ּ���

	// if�Լ��� ����ؼ� luckyNumber�� UserInput�� ������
	// c++ ��� �Լ� "������ ���߾����ϴ�." �������߰�
	// if �Լ��� �Ἥ �ٸ��ٸ� 
	// c++ ����Լ� "�����Դϴ�. �ٽ� �Է����ּ���."

	int LuckyNumber = 4;
	int UserInput;
	cout << "���� ���ڸ� ���߾� ������" << endl;
	
	while (1)
	{
		std::cin >> UserInput;

		if (LuckyNumber == UserInput)
		{
			cout << "������ ���߾����ϴ�."<<endl;
			break;
		}
		if (LuckyNumber != UserInput)
		{
			cout << "���� �Դϴ�. �ٽ� �Է����ּ���." << endl;
		}
	}

}
