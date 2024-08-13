/*
*  �н� ��ǥ : ù Ŭ���� ����. �Լ� �����ε��� �����ڿ� ���� ����
*  �ۼ��� : 2024-08-13
*  �ۼ��� : ������
*/

#include "lectures.h"

/*
*  Ŭ���� ����
*  Ŭ����(class) : ��ü - ���α׷��� ���� ���� �����ϴ� ��� ����� ǥ���ϴ� ��
*/

// 1. ��ü�� �Լ��� �����ϴ� ���� �� ���⿡ �������̴�.
// struct ����ü �Լ��� ���ο� ������ �� �� �������ϴ�.
// Ŭ���� ���ο� �Լ��� �����ؼ� ����� �� �� �ֽ��ϴ�.

class Dog 
{
private:
	int happy;
	int hungry;
	char name[30];

public:
	Dog();
	Dog(int happy,int hungry);
	void Play(); // ù ��° ������� class �ȿ� �����ϴ� ����� ������ �ʹ� ������� �ٸ� ����� �����
	void Feed();
	void ShowStatus();
	void MakeDog();
};

// ���� ������ �̸����� :: // namespace�ȿ� �ִ� �Լ��� ����ϰڴ�.
// Ŭ���� :: �Լ� �̸� // Ŭ���� �ȿ� �ִ� �Լ��� ����ϰڴ� ��� ���̵ȴ�.

Dog::Dog() // ������ 
{
	happy = 100;
	hungry = 100;
	strcpy_s(name, 30, "�ǻ�");
}

Dog::Dog(int happy, int hungry) // ���ڷ� �޴� �� �տ� '_'�� ���̰ų� this->�� ����ϱ� // ������ �����ε�
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
	std::cout << "���� �̸� : " << name << std::endl;
	std::cout << "���� �ູ�� : " << happy << std::endl;
	std::cout << "���� ��� : " << hungry << std::endl;
}
/// <summary>
/// Dog�� �ʱ�ȭ �Լ��̹Ƿ� �ݵ�� ������ ����� �Բ� ���Ǿ��Ѵ�.
/// </summary>
void Dog::MakeDog()
{
	std::cin >> happy;
	std::cin >> hungry;
	std::cin >> name;
}

/*
*  �Լ� �����ε�(overloading) : 1. �����ϴ�. 2. �����Ͽ� �ɸ��� �ϴ�.
*  
*  void Add(int a,int b); a + b;
*  void Add(float a, floatb); a + b;
*  void Add(double a,double b);
*  void Add(char a, char b);
*  void Add(Dog dog1,Dog dog2); dog1.happy + dog2.happy
*/

/*
*  �Լ� �����ε� ���ÿ� �����ؾ��� ����
*  1. �����Ϸ��� �Լ��� �����ϴ� ����� (1) �Լ��� �̸� (2) �̳��� ������ Ÿ��
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
*  Ŭ���� ������ : Ŭ������ ������ �Ŀ� �ʱ�ȭ �Լ��� ������ ȣ���Ű�� ���
*  
*  Dog dog1; // default �����ڰ� ȣ��˴ϴ�.
* 
*  default : ���� �����͵��� 0���� �ʱ�ȭ ��Ų��. int* �ּ� �����͵��� nullPtr;
*/


void lecture4()
{
	// Play(); C���� �Լ� ȣ�� ��� X
	// Dog::Play(); Ư���� ���� static�� ������� �ʴ� �̻� X
	
	// ������, ����ü ó�� ������ �����ϰ� ���� �����͸� �ʱ�ȭ���� ������ �̻��� �����Ͱ� ��µǴ� ������ �ִ�.
	// MakeDog �ʱ�ȭ �Լ��� �ݵ�� ���� ���� ������ ������Ѵ�.

	Dog dog1;
	//dog1.MakeDog(); // ���������� �ݵ�� �����ϴ� ����� �������̴�.
	dog1.ShowStatus();

	
	// case1. �Լ� �����ε��� ���ڸ� ������� Ÿ��
	int a = 1;
	char b = 'b';
	double c = 1.1;
	Print(a);
	Print(b);
	Print(c);
	// case2. �Լ� �����ε��� ���� ����
	short s1 = 2;
	float f1 = 2.2f;
	Print(s1);
	Print(f1);

	// �Լ��� �̸��� �����ϴµ�, ������ Ÿ���� ���� ���.
	// �����Ϸ��� ��� �ൿ�ϴ°� ?
	// 1. ������ Ÿ���� ������ ����ȭ�� �õ��Ѵ�.
	// 2. ����� ����ȯ, ������ ����ȯ�� �ִµ� ������ ����ȯ�� �߻��ϰ� �ִ�.
	// 3. ������ ������ Ÿ�� -> int������ ��ȯ�� �õ��Ѵ�. �Ǽ��� ������ Ÿ�� ->double������ ��ȯ �õ�, float ������ ��ȯ�õ�
	// 4. ������ ������ Ÿ���� ���� ��쿡 �Ǽ��� ������ Ÿ���� ���������� �ٲپ �� ��ȯ�� �õ��Ѵ�.

	// float -> ������ ������ Ÿ������ ��ȯ�� �ؾ��ϴµ�..  int�� �޴� �Լ�, char�� �޴� �Լ� �� �� ������ �����ؾ� ���� �𸣱� ������ ������ �߻�
	// �����ε�� �Լ��� �ν��Ͻ� �� �ΰ� �̻��� �μ� ��ϰ� ��ġ�Ѵ�.

	// ���� 
	// �����Ϸ��� �츮�� �˰� �𸣰� �߸��� �ڵ嵵 ���������� ó���ǵ��� ���� �ϰ� �־���.
	// 1. ������ Ÿ���� ���ǵ��� �ʾҴµ� ����ߴ�. = Ÿ���� �����ε����� ���� ���� �ʾҾ ����� �����ϴ�.
	// 2. �Ǽ��� ������ Ÿ���� �������� �ʰ� ������ ������ Ÿ���� �� �� �̻� �����ߴ�.

	// �������� ���� 
	Dog dog2;          // ����Ʈ �����ڰ� ȣ��ȴ�.
	dog2.ShowStatus();
	Dog dog3 = Dog();  // ����Ʈ �����ڰ� ȣ��ȴ�.
	dog3.ShowStatus();

	int doghappy;
	std::cin >> doghappy;
	int doghungry;
	std::cin >> doghungry;
	
	Dog dog4 = Dog(doghappy,doghungry);
	dog4.ShowStatus();
	

	// �Ʒ� �ڵ�� ���� ������ �ִ� �ڵ�������, �ۼ����Ͽ� �����غ�����
	Dog dog5 = dog4;
	dog5.ShowStatus();

	Dog* dogs[100];
	dogs[0] = new Dog();
	dogs[0]->ShowStatus();
	delete dogs[0];
	dogs[1] = dogs[0];
	dogs[1]->ShowStatus();

}