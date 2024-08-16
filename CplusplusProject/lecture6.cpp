#include "lectures.h"
/*
*  �н���ǥ : ��������ڿ� ���� ���� �� �Ҹ���
*  �ۼ��� : 2024-08-16
*  �ۼ��� : ������
*/
 
// 1. ���� Ŭ������ ������ 

// 2. Ŭ������ �Ҹ��ڿ� ���� �ս�
// - new Ű���尡 ���Ե� �����ڸ� �������� ��, newŰ����� ������ ������ �޸� ������ ���ϴ� ������
// Ŭ������ �Ҹ��ϴ� ������ ȣ��Ǵ� �Ҹ��ڸ� �����ؼ� delete Ű����� �޸𸮸� �������־���.

// 3. ��������ڸ� �̿��ؼ� Ŭ������ �����Ѵ�.
// - �ڱ��ڽ� Ŭ������ �����ؼ� �ٸ� Ŭ����(�ν��Ͻ�)�� �����ϴ� ������

// 4. ���� ����(Shallow Copy) vs ���� ����(Deep Copy)
// ���� ���� : ���縦 �� �� �ּҸ� �״�� �����ͼ� ���� �ּҸ� ����Ű�� ���� ��� 
// (�ּҸ� ������ �� �ٸ� �ּҰ� ���� �޸� ������ �Ǹ� ���� �ּҸ� ����Ű�� ������ �߻�)
// ���� ���� : ������ �� �ּ��� ��쿡 �ش� ������ ����Ȱ������ �����ؼ� ���ο� ������ �����ϴ� ���

// ���� ���縦 ���� ���� : �ϳ��� �޸𸮷� �� �̻��� ǥ���� �� �ִ�. �޸𸮸� ������ �� ������ ���� �� �ִ�.



class Marine
{
private:
	int hp;
	int attackpower;
	int posX;
	int posY;
	bool isdead;
	char* name;
public:
	Marine(int x, int y); // �跰�� ��ġ���� ������ ����
	Marine(int x, int y,const char* marinename); // Ŭ���� ����� name�� �ܺ��� marinename���� �����ϴ� ��, const�� �����ؼ� marinename�� �������ʴ� ���� �m��
	Marine(const Marine& m1); // ��������� ȣ�� ���
	~Marine();    // �Ҹ��� : �Ҹ��� �� ȣ��ȴ�.
	void Move(int x, int y);
	int Attack();
	void Damaged(int damage);
	void ShowStatus();
};

Marine::Marine(int x, int y)
{
	hp = 50;
	attackpower = 5;
	posX = x;
	posY = y;
	isdead = false;
}

Marine::Marine(int x, int y, const char* marinename)
{
	// char name[30]; 30�̻��� �̸� ũ�⸦ ������ �� ����.(������ ���� ���) 
	// ������ ���� ��� : �����ϰ��� �ϴ� ���ڿ��� ���� ��ŭ �޸� ������ �Ҵ��ؼ� �����Ѵ�.
	name = new char[strlen(marinename) + 1];  // strlen�� null�� �������� �ʱ� ������ +1 ������Ѵ�.
	strcpy_s(name, strlen(marinename) + 1, marinename);
	hp = 50;
	attackpower = 5;
	posX = x;
	posY = y;
	isdead = false;

}

Marine::Marine(const Marine& m1)
{
	name = new char[strlen(m1.name) + 1];  // strlen�� null�� �������� �ʱ� ������ +1 ������Ѵ�.
	strcpy_s(name, strlen(m1.name) + 1, m1.name);
	hp = m1.hp;
	attackpower = m1.attackpower;
	posX = m1.posX;
	posY = m1.posY;
	isdead = m1.isdead;
}

Marine::~Marine()
{
	std::cout << name << "�� �Ҹ��� ȣ��!" << std::endl;
	if(name!=NULL)
	delete[] name;  // delete[] : �迭�� ��ü �޸� �����϶�.
}

void Marine::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Marine::Attack()
{

	return attackpower;
}

void Marine::Damaged(int damage)
{
	hp -= damage;
	if (hp <= 0)
		isdead = true;

}

void Marine::ShowStatus()
{
	std::cout << "**���� ����**" << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ġ : "<<posX<<", "<<posY << std::endl;
	std::cout << "���ݷ� : " << attackpower << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl << std::endl;
}


void lecture6()
{
	Marine marine1(1, 2, "marine1");
	Marine marine2(2, 1, "marine2");
	marine1.ShowStatus();
	marine2.ShowStatus();

	
	std::cout << " ����1�� ����2�� ����" << std::endl;
	marine2.Damaged(marine1.Attack());
	marine2.ShowStatus();

	// ���� ������ ������ �ѹ��� �����غ���. -> �迭
	Marine* marines[100];

	
	marines[0] = new Marine(2, 5, "Marine3");
	marines[1] = new Marine(3, 4, "Marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];

	// int�� �� ����
	int num = 10;
	int num2 = num;
	int num3(num);  // num3(num) num ������ ���� num3�� ����

	std::cout << num3 << std::endl;

	// marine�� ��������� ȣ��(����Ʈ ���������)
	Marine marine3(0, 0,"����1");
	Marine marine4=marine1;
	Marine marine5(marine3);

	// ����Ʈ ����������� �Ѱ� : Ŭ������ ��� ������ ������ ������ �ּҸ� ����Ű�� ��쿡 ���� ����� �����Ѵ�. 
	// -> ���� ����� ���ؼ� ���� �޸� �Ҹ�� �ּҸ� ã�� �� ���� ������ �߻��Ѵ�.

	marine5.ShowStatus();

	// marine3 �Ҹ��� ȣ�� ->


	
}

// 1. ���� Ŭ���� ����
// 2. �����ڿ� �Ҹ��� ( ü�°� �̸��� �ʱ�ȭ�ϰ�, �Ҹ��� �� �����Ҵ� �� �ּҸ� �����ϰ� ���� ��.
// 3. ��������ڸ� ��������� �ۼ��ؼ�, ���� ���簡 �ƴ� ���� ���� ������� ������ �� �ְ� �ڵ� ������ ��

class Zealot
{
private:
	int hp;
	int attackpower;
	char* name;
	bool isdead;
public:
	Zealot(const char* zealotname);
	Zealot(const Zealot& Z1);
	~Zealot();
	int attack();
	void damaged(int damage);
	void showstatus();
};

Zealot::Zealot(const char* zealotname)
{
	hp = 100;
	attackpower = 10;
	
	// malloc      sizeof(Zealot) * strlen(zealotname) + 1];
	name = new char[strlen(zealotname) + 1];
	strcpy_s(name, strlen(zealotname), zealotname);
	isdead = false;
}

Zealot::Zealot(const Zealot& Z1)
{
	std::cout << "��������� ȣ��" << std::endl;
	hp = Z1.hp;
	attackpower = Z1.attackpower;
	strcpy_s(name, strlen(Z1.name), Z1.name);
	isdead = Z1.isdead;

}

Zealot::~Zealot()
{
	std::cout << "�Ҹ��� ȣ��";
	delete[] name;
}

int Zealot::attack()
{
	return attackpower;
}

void Zealot::damaged(int damage)
{
	hp -= damage;
	if (hp <= 0)
		isdead = true;

}

void Zealot::showstatus()
{
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "ü�� : " << hp << "���ݷ� : " << attackpower << std::endl;
}

void lecture6_2()
{
	Zealot Zealot1("Z1");
	Zealot Zealot2 = Zealot1;
	Zealot Zealot3(Zealot1);

	
	Zealot3.showstatus();
	
}