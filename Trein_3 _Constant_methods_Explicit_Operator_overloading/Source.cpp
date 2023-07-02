#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<cmath>

//1.����������� �����
/*
// �������� � ��������� ��������� const
const int size = 3;
const std::string s{ "Ivanov" };

// �������� ����������� ������� � ������� ��������
const int days[] = { 15, 38, 20 };
const char* s{ "Ivanov Ivan Ivananovich" };

//����������� ������� ������   const Date electionDay{ 11, 30, 2020 };
class Date
{
private:
	int _month;
	int _day;
	int _year;
public:
	Date(int month, int day, int year) : _month{ month }, _day{ day }, _year{ year } {}

	// ����������� ������� � ������ �� ����������� ������� ������
	Date(const Date& date); // ����� ���������� � ������ ��������, ��� ��������� ������� ������,
	//��������, ��������� ������������ �����������
	
	// Date(const Date& date) {} ������ date ����� �������� �������� ������
	//����� �������������!!!!

	// �������� const ����� ����� ������� ��������
	int getDay()const { return _day;}// �������� ����� 
	//int getDay()const � ������� �������� ��� ��� �� ������ ������ _day
	//���������� ����������� �������� - ������

	// ���������� ������� �� 2 ������ �� ����� � �����
	double getValue();
	double getValue() const;
	// ������������� � ����� ������������� �������� ��������� 
	// ����� �� ���������� ��������� � �����������. ���  ������ � ������ �������� � ����������� ���������� ��� 
	//����������� ��������

	// !!!!!������������ � ����������� �� ����� ����������� ��� const.!!!!!!!!!!


};
const Date electionDay{ 11, 30, 2020 };
*/

//1.2. ����������� ��������� this � ����������� ������
/*
class Date
{
private:
	int day;
	int month;
	int year;
public:
	void setDay(int value)
	{
		day = value;
	}
	int getDay() const
	{
		return day;
	}

	void setDay(Date* const this, int value) // this �������� ����� ���� �������
		// ������� �������� ����� ������ 
	{
		this->day = value;
	}
	
};



int main()
{
	Date aDate;
	aDate.setDay(100);	
	std::cout << aDate.getDay() << std::endl;

	getchar();
	return 0;
}

*/
/*
��� ������, ������� ������ �����-���� �������������� �������, �� ������� ��� ���� �������� �������,
������ ���� ������� ��� �����������. � ���������
������ �� ������ ����� ��������� ��� �����������
�������� ��� ���� ��� ���������� ��������, ������
� ������� �������������� ����� ����������� ��������� ��� ������. ���������� const � �������� �����
������� �������� ������������ ������ ���������������� �� �+
*/

//2.���������� ������������ � �������������� ���������
//����� explicit
/*
��� �������������� ��������� ������, ��������� � ������� ��������������� (��������� ���������)
�������� ������ ������� ������ ������������ � 1 (�����)
���������� ������, ��������� �������� ����� explicit
*/
/*
class Array
{
	int _size;
	int* _array;
public:
	explicit Array(int size = 10);// ������������� ������� ������ ������������ ������ 
	~Array();
	int getSize() const;
	int getValue(int index)const;
	void setValue(int index, int value);
	void display(int index) const;

};
Array::Array(int size)
{
	Array::_size = size;
	_array = new int[size];
}
Array::~Array()
{
	delete[]_array;
}
int Array :: getSize() const { return _size; }
int Array::getValue(int index) const { return _array[index]; }
void Array::setValue(int index, int value){	_array[index] = value; }
void Array :: display(int index) const
{
	std::cout << _array[index] << ' ';
}
void display(const Array& array)// display(const Array& array) ����������
// �������� ������� ������ �� �����
{
	for (int i = 0; i < array.getSize(); ++i)
	{
		array.display(i);
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Dinamik inter Array" << std::endl;
	int size = 4;
	Array array(size);
	for (int i = 0; i < size; ++i)
	{
		array.setValue(i, size - i);
	}
	display(array); // ��� ���� ���� ������� �������� display(3); �� explicit  ���� ������ �� ����� ����������. �.�.
	// ��� void display(const Array& array)  � ��� �������� ���� ������ ���������. � ���  explicit  �� ������� �����.
	std::cout << "!!!!!!" << std::endl;

	int _getch(void);

	return{};
}
*/

//3. ������������� ������������� ���������� ����������
/*
���������� ������: ����� ��� ��������� ���������
��� �������������� ����������, ��������� � �������������� ��������� ����� � �������� �� ������������
���������.
*/
// ��� ��� ��� ��� ���������� ����� ���������� ��������� ������� ���������� � ���� ������
//int count; 
//std::cin>> count;
//double* x = new double[count];
//double* y = new double[count];
// �������� ����� 

class Point
{
private:
	double _x{ 0 };
	double _y{ 0 };
public:
	Point(double x, double y) : _x{ x }, _y{ y } { }
	double get_x() { return _x; }
	double get_y() { return _y; }
	void set_x()
	{
		std::cin >> _x;
	}void set_y()
	{
		std::cin >> _y;
	}

// �������� ����� 
	// �������� static ������� 

	void display()const // ����� �����
	{
		std::cout << "( " << _x << ", " << _y << " )";		
	}

	// ������ �����
	void read() 
	{ 		
		std::cout << "Enter X: ";
		set_x();
		
		std::cout << "\n\nEnter Y: ";
		set_y();

	} 

	// ��������� ���� ����� ��� ��������
	static bool isEqual(const Point& point1, const Point& point2) // ���� bool �� ���������� ������ true ��� false !!!
	{
		/*int max_x;
		int max_y;

		return (point1._x >= point2._x ? max_x = point1._x : max_x = point2._x,
			point1._y >= point2._y ? max_y = point1._y : max_y = point2._y);*/

		if (point1._x == point2._x && point2._y == point1._y) return true;
		//point1._x == point2._x ? point1.y == point2.y ? return true : return false;

		return false;
		
		// ������ ������ ����� if
		/*if (&point1 > &point2)
		{
			if (&point1 == &point2)
			{
				std::cout << "p1" << &point1 << " = " << "p1 " << &point2 << std::endl;
			}
			return &point1;
		}
		return &point2;*/
	}

	// �������� ���� �������� (��� �����)
	static const Point add(const Point& point1, const Point& point2)
	{ 
		return Point(point1._x + point2._x, point1._y + point2._y);
	}

	// ��������� ������� �� �����
	static const Point mult(const Point& point, double value) 
	{ 
		return Point(point._x * value, point._y * value);
	}

	// �������� �������  ��������� ����� �� ����� (������� ������� �� �����)
	static const Point divide(const Point& point, double value)
	{
		return Point(point._x / value, point._y / value);
	}

		//���������� ����� ����� �������
	static double distance(const Point& point1, const Point& point2)
	{ 
		return sqrt(pow(point1._x - point2._x, 2) + pow(point1._y - point2._y, 2));
	}

		// ������ �������
	static double length(const Point& point) { }
};
int main()
{
	int count;// ������� ���������� �������  - ��� ������� ������ ������� ������
	std::cin >> count;
	Point* point = new Point[count]; // ��� ��� ����� Point �������
	// ������������ ������ �������� [count]

	Point point1(1, 1);
	Point point2;
	Point point3(1, 1);

	if (Point::isEqual(point1, point2))	
		std::cout << "Point1 and Point2 are Equal!" << std::endl;
	
	std::cout << "p1: ";
	point1.display();
	std::cout << std::endl;

	std::cout << "Enter point p2 in format x,y ( e.g. 12,10): ";
	point2.read();

	std::cout << "p2: ";

	point2.display();
	std::cout << std::endl;

	std::cout << "p2 + p1 = ";
	Point::add(point1, point2).display();
	std::cout << std::endl;
	std::cout << "Distance between ";
	point1.display();
	std::cout<< " and ";
	point2.display();
	std::cout << " is ";
	std::cout << Point::distance(point1, point2);
	std::cout << std::endl;

	 _getch();
	
	return{};
}