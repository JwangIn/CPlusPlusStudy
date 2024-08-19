#include "lectures.h"

/*
*  �н���ǥ : ������ �����ε�
*  �ۼ��� : 2024-08-19
*  �ۼ��� : ������ 
*/

/*
*  #include <iostream>
*  istream(�Է� ��Ʈ��), out stream(��� ��Ʈ��)
*  �ܼ� â�� ������� �����Ͽ���.
*  cout << : c���� ��Ʈ �����ڷ� ���Ǿ��µ�, cout << ��Ʈ ����� ������ �ֳ���?
*  cin >> : c���� ��Ʈ�����ڷ� ���Ǿ��µ�, cin >> ��Ʈ ����� ������ �ֳ���?
*/

/*
*  ����ü, Ŭ���� : ����� ������ �ڷ���
*  Ŭ������ Ŭ���� ���̿� ��������ڰ� ����� �����Ѱ�?
*  ���� -> �ش��ϴ� �ǿ����ڰ� �����ϴ�.
*  �ذ� : �ش��ϴ� �����ڸ� ������ָ�ȴ�. -> ������ �����ε����� Ŭ������ ���� �����ϴ� ���̴�.
*/

/*
*  ������ �����ε� : �⺻ �����ڵ� (+,-,*,/,[],<<,>>)���� ����ڰ� Ŭ������ ���� �����ϴ� ���̴�.
*  (��ȯ��)(Ű����)(������)()
*  ���� : void operator+();
*/

/*
*  ���� �Լ� �����ε� : 
*  - ��� �Լ��� ���� �����ε� : ��ü.operator+(�ǿ�����) : ��ü + �ǿ����� ������ �̷���� �ִ�.
*  - ������ �������� ��ü�� �ݵ�� ���ʿ� �־���Ѵ�.
*  p1 + 10; ( o )
*  10 + p1; ( x )
*  ���� �Լ� �����ε��� operator+(�ǿ�����, �ǿ�����) �ǿ����� + �ǿ����� ������ ��ü�� �ڿ� ��ġ�ص� �������� ����� ����մϴ�.
*  �ǿ����� + �ǿ����� = operator+(�ǿ�����, �ǿ�����)
*/

/*
*  friend �Լ� 
*  Ŭ������ ��� �Լ��� �ƴϸ鼭 �ش� Ŭ������ private �����͸� �����Ҷ� ����ϴ� �Լ��Դϴ�.
*  Ŭ������ ������ ������, �� Ŭ���� �ȿ� �ִ� �����͸� ����ϰ� �;��� �� ����ϴ� Ű����
*  ���� : private,public -> private�� �̿��ؼ� �ܺο��� ������ ���ϰ� �ϱ� ���ؼ� ���� ���� �����ϴ� ����.
*  ���� : ������ �����ε��� ����ؼ� �������� �Լ��� ���� �� �ִ�.
*  ��� : ������ �����ε� �̿ܿ� friend Ű���带 ����ϴ� ���� �����Ѵ�.
*/

/*
*  ��Ȳ ������ �����ε� : ���� ������
*  ++ : num + 1;
*  -- : num - 1;
*  ++num : ���� ���� ����
*  num++ : ���� ���� ����
*/


class Point
{
private:
	int posX, posY;
public:
	Point(){}            // ����Ʈ ������
	Point(int x, int y)  // ������ �����ε�
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

	friend Point operator+(int num, Point ref);  // ���� �Լ� ������ �����ε�

	Point operator++()   // ���� ���� ������ ++p1;
	{
		posX += 1;
		posY += 1;
		return *this;  // �ڱ� �ڽ��� ��ü�� ��ȯ�Ѵ�.
	}
	Point operator++(int) // ���� ���� ������ p1++;
	{
		Point temp(*this); // ���� ������ : ���� ����� �����Ͱ� �̵��Ѵ�.
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



// �̸��� ������ ���ԵǾ� �ִ� Ŭ������ ����̴ϴ�.
// Math + English -> �������� : m1 �������� : e1;

class Eng; // Eng Ŭ������ �����Ѵٰ� ������ֱ�����
class Math
{
	char name[15];
	int score;

	friend int Add(Math m1, Eng e1);
public:
	Math(){} // �����ڸ� ���� �����ϸ� ����Ʈ �����ڰ� �ڵ����� �������� �ʱ� ������ ��������� ����
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
	std::cout << "�̸� : " << m1.name << ", ���� ���� : " << m1.score << ", ���� ���� : " << e1.score << std::endl;
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

// c��� int -> printf("%d",num);



void lecture7()
{
	Point p1(1, 1);
	Point p2(2, 3);
	
	Point result = p1 + p2; // �����ڿ� ��ġ�ϴ� "+" �����ڰ� �����ϴ�.
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
	std::cout << "���� ���� Ǯ�� " << std::endl;

	Math m1("����", 90), m2("����", 80);
	Eng e1("����", 70), e2("����", 99);
	Add(m1, e1);

	std::cout << "���� + ���� ���� : " << Add(m1, e1);

	// ���࿡ ������ �����ε� ������ ���������� �ʴ´ٸ�?
	// Add(m1,e1)
	

}