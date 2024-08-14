#include "lectures.h"

/*
*  �н� ��ǥ : Ŭ����(��ü���� ���α׷���)�� Ư¡
*  �ۼ��� : 2024-08-14
*  �ۼ��� : ������
*/

// Ŭ���� ����
// Ŭ���� ������, �Լ� �����ε�

// ���α׷��Ӹ� �����ϴ� ���� Ŭ������ ���� �ִ� Ư¡�̴�.
// ���α׷��� �Ǽ��� ��õ������ ������ �� �ִ�.

// 1. ������ : ���α׷��Ӱ� �Ǽ��� �ʱ�ȭ���� �ʰ� �����͸� ����ϴ� ���� ��õ������ ���� ���� �����̴�.
// 2. �������� : ���������ڸ� ���ؼ� ���α׷��Ӱ� �����͸� �����ϰ� ������ �� �ִ� ����̴�.(����� ����� ���ؼ�)
// ��� ������ private���� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ� ������ ���·� ��� ������ ������ �����ϴ� ���� �ǹ��Ѵ�.
// ���� Ŭ������ �ۼ��ϱ� ���� �⺻ ���� : ��������(���м�), ĸ��ȭ
// 3. ĸ��ȭ : ĸ���� �������� ������ ȥ�յǾ� �ִ� ���� �����ϴ� ��
// Ȯ�� �Ϸ��� ĸ���� �� �м��ؾ��Ѵ�.
// �ڵ带 ĸ��ȭ ���״�. -> �ڵ带 �Լ��� �����ߴ�. �Լ��� �ڵ�� �ۼ��� �ؼ� , �� ����� �ʿ��� ����� �� �Լ��� ȣ�⸸ �ϸ� �ǰԲ� �ۼ��ϴ� ��
// (1) �����(����)�� �� �Լ��� ������ �ϴ��� �� �ʿ䰡 ����.
// (2) �ۼ���(���α׷���) ���忡�� �ڵ带 �ۼ��ϴµ� �ʿ��� �Լ��� �׳� ȣ�⸸ �ϸ� �ȴ�.
// ��) Play(); �ູ��,��� ����� ��ȭ
//     ��Ű�� ��ǰ�� �����. Play, Feed, Shower����� �ѹ��� ����Ǵ� ���
//     Package1(){Play(); Feed(); Shower();}


class Date
{
private:
	int day;   // ���� �� ����. 30, 31
	int month; // 1 ~ 12
	int year; // 2024 �ʱ�ȭ ��
public:
	// private�� �ƴ�  public�� �ۼ��Ѵٸ�
	Date();
	Date(int _day, int _month, int _year);
	void ChangeDay(int x); // day�� �����ϴ� �Լ�
	void ChangeMonth(int x);
	void ChangeYear(int x);
	void ChangeDate(int _year, int _month, int _day);
	void ShowDate(); // ���� ��¥�� ����ϴ� �Լ�

};

Date::Date() // ����Ʈ �������� ������
{
	day = 14;
	month = 8;
	year = 2024;
}

Date::Date(int _day, int _month, int _year)
{
	day = _day; // this->day=day;
	this->month = _month;
	this->year = _year;

}

void Date::ChangeDay(int x)
{
	if (x > 31)
	{
		std::cout << "���� 31�� ���� �� �����ϴ�." << std::endl;
		std::cout << "�ش� ����� �ǽ� �� �� �����ϴ�." << std::endl;
		return;
	}
	day=x;
}

void Date::ChangeMonth(int x)
{
	month = x;
}

void Date::ChangeYear(int x)
{
	year = x;
}

void Date::ChangeDate(int _year, int _month, int _day)
{
	year = _year;
	month = _month;
	day = _day;
}

void Date::ShowDate()
{
	std::cout << "������ " << year << "�� " << month << "�� " << day << "���Դϴ�"<< std::endl;
}

class SinivelCap
{
public:
	void Take()
	{
		std::cout << "�๰���� �����߽��ϴ�." << std:: endl;
	}
};
class SneezCap
{
public:
	void Take()
	{
		std::cout << "������� �����߽��ϴ�." << std::endl;
	}
};

class Capsule100
{
private:
	SinivelCap sc;
	SneezCap sz;
public:
	void Take()
	{
		sc.Take();
		sz.Take();
	}
};

class Patient
{

public:
	void TakeCapsule(Capsule100& capsule)
	{
		capsule.Take();
	}
};

// Point (int x, int y) ��ǥ�� ����ϴ� ��ü�� �����غ�����
// �簢�� ��ü�� �����غ�����
// �簢���� ���̸� ���ϴ� �Լ�
// �簢���� ������ ����ϴ� �Լ� ����
// leftdown �� upright�� ��ǥ�� �����ϴ� �Լ� �߰�

class Point
{
private:
	int x;
	int y;
public:
	Point();
	int GetX() const;
	int GetY() const;
	void ShowPoint() const;
};
Point::Point()
{
	std::cout << "x�� ��ǥ�� �Է� : ";
	std::cin >> x;
	std::cout << "y�� ��ǥ�� �Է� : ";
	std::cin >> y;	
}

// const �Լ��� ���� ����
// (��ȯ��) �Լ��̸�() const; �������� �ۼ��Ѵ�.
// const keyword ���Ĺ޴� ��� ������ ���� ������� ������ �����ϴ� Ű���� �Դϴ�.

int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}

void Point::ShowPoint() const
{
	std::printf("(%d, %d)\n", x, y);
	//std::cout << "(" << x <<"," << y << ")" << std::endl;
}


class Rectangle
{
private:
	Point leftDown;
	Point rightUp;
	int areaSize;
public:
	Rectangle();
	int CalculateArea();
	void ShowRectinfo();
};

// ��� �̴ϼȶ������� �̿��� ��� �ʱ�ȭ ���
// ��� �̴ϼȶ������� ��������� ����� ��ü�� ������ ȣ���� Ȱ���ϴ� ����Դϴ�.

Rectangle::Rectangle() :leftDown(), rightUp() 
{
	areaSize = CalculateArea();
}

int Rectangle::CalculateArea()
{
	int row =rightUp.GetX() - leftDown.GetX(); // ���� ����
	int col = rightUp.GetY() - leftDown.GetY(); // ���� ����

	std::cout << "�簢���� ���� : " << row * col << std::endl;
	return row * col;
}

void Rectangle::ShowRectinfo()
{
	leftDown.ShowPoint();
	rightUp.ShowPoint();
	std::cout << "�簢���� ���� : " << areaSize << std::endl;

}

// Circle Ŭ������ ���� �����غ�����
// ������ radius, const float PI=3.14f, ���� ��ǥ Point
// ���� ȣ�� ���̿�, ���� ���̸� �����ڷ� �����ϰ�
// showCircleinfo(); ���� ��ǥ, ������ ����, ȣ�� ����, ���̸� ����ϴ� �Լ��� ������

class Circle
{
private:
	const float PI = 3.14f;
	int radius;
	int ArcLength;
	int CircleArea;
	Point CirclePoint;
public:
	Circle();
	void ShowCircleinfo();
};

Circle::Circle():CirclePoint()
{
	std::cout << "�������� ���� : ";
	std::cin >> radius;
	ArcLength = 2 * PI * radius;
	CircleArea = radius * radius * PI;
}

void Circle::ShowCircleinfo()
{

	std::cout << "�������� ���� : " << radius << std::endl;
	std::cout << "���� ���� : " << CircleArea << std::endl;
	std::cout << "ȣ�� ���� : " << ArcLength << std::endl;

}

void lecture5()
{
	Date date1; // ����Ʈ �������� �ʱ�ȭ
	date1.ShowDate();

	Date date2 = Date(15, 8, 2024);
	// 2024-08-16
	date2.ChangeDay(16);
	date2.ShowDate();
	
	Date date3;
	date3.ChangeDate(2024, 4, 18);
	date3.ShowDate();
	// �Լ��� �̿��ؼ� ����� ���� �����ϴ� �Ͱ� 
	// ��� ������ ���� �����ؼ� �����ϴ� ���� ũ�� �������� ���� �ʳ���?

	Patient pa; // ȯ�� �Ѹ��� �����մϴ�.
	Capsule100 capsule;
	pa.TakeCapsule(capsule);

	// �簢�� Ŭ���� ȣ��
	Rectangle rect1;
	rect1.ShowRectinfo();






}
