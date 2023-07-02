#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<cmath>

//1.Константный метод
/*
// Числовые и строковые константы const
const int size = 3;
const std::string s{ "Ivanov" };

// Числовые константные массивы И Массивы Символов
const int days[] = { 15, 38, 20 };
const char* s{ "Ivanov Ivan Ivananovich" };

//Константные объекты класса   const Date electionDay{ 11, 30, 2020 };
class Date
{
private:
	int _month;
	int _day;
	int _year;
public:
	Date(int month, int day, int year) : _month{ month }, _day{ day }, _year{ year } {}

	// Константные объекты и ссылки на константные объекты класса
	Date(const Date& date); // часто появляются в тексте программ, как параметры методов класса,
	//например, параметры конструктора копирования
	
	// Date(const Date& date) {} Объект date может получить значение только
	//путем ИНИЦИАЛИЗАЦИИ!!!!

	// Вызывать const объек можно Простым способом
	int getDay()const { return _day;}// ключевое слово 
	//int getDay()const в функции означает что она не меняет объект _day
	//Называется Константной функцией - членом

	// Перегрузка функции на 2 версии Не конст и Конст
	double getValue();
	double getValue() const;
	// Необходимость в таких перегруженных функциях возникает 
	// когда мы используем операторы с перегрузкой. Это  чтения и записи объектов и константная перегрузка для 
	//константных объектов

	// !!!!!Конструкторы и деструкторы не могут объявляться как const.!!!!!!!!!!


};
const Date electionDay{ 11, 30, 2020 };
*/

//1.2. Особенности указателя this в константном методе
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

	void setDay(Date* const this, int value) // this Содержит адрес того объекта
		// который вызывает метод класса 
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
Все методы, которые выдают какие-либо характеристики объекта, не изменяя при этом значение объекта,
должны быть описаны как константные. В противном
случае их нельзя будет применить для константных
объектов или даже для нормальных объектов, доступ
к которым осуществляется через константный указатель или ссылку. Отсутствие const в описании таких
методов является неправильным стилем программирования на С+
*/

//2.Объявление конструктора с использованием ключевого
//слова explicit
/*
Для предотвращения возможных ошибок, связанных с неявным преобразованием (случайным созданием)
объектов класса следует делать конструкторы с 1 (одним)
параметром явными, используя ключевое слово explicit
*/
/*
class Array
{
	int _size;
	int* _array;
public:
	explicit Array(int size = 10);// Конструктором создали пустой Динамический массив 
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
void display(const Array& array)// display(const Array& array) Глобальной
// функцией Выводим массив на экран
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
	display(array); // Тут если явно напишем параметр display(3); то explicit  даст ошибку на этапе коипиляции. Т.К.
	// Тут void display(const Array& array)  У нас недолжно быть явного аргумента. А без  explicit  мы получим туфту.
	std::cout << "!!!!!!" << std::endl;

	int _getch(void);

	return{};
}
*/

//3. Необходимость использования перегрузки операторов
/*
Рассмотрим пример: пусть нам предстоит выполнить
ряд геометрических вычислений, связанных с использованием координат точек и векторов на координатной
плоскости.
*/
// Так как эти две координаты имеют одинаковую сущьность удобней объединить в один объект
//int count; 
//std::cin>> count;
//double* x = new double[count];
//double* y = new double[count];
// Создадим класс 

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

// Создадим класс 
	// Создадим static функции 

	void display()const // Вывод точки
	{
		std::cout << "( " << _x << ", " << _y << " )";		
	}

	// Чтение точки
	void read() 
	{ 		
		std::cout << "Enter X: ";
		set_x();
		
		std::cout << "\n\nEnter Y: ";
		set_y();

	} 

	// Сравнение двух точек или векторов
	static bool isEqual(const Point& point1, const Point& point2) // Если bool то возвращает всегда true или false !!!
	{
		/*int max_x;
		int max_y;

		return (point1._x >= point2._x ? max_x = point1._x : max_x = point2._x,
			point1._y >= point2._y ? max_y = point1._y : max_y = point2._y);*/

		if (point1._x == point2._x && point2._y == point1._y) return true;
		//point1._x == point2._x ? point1.y == point2.y ? return true : return false;

		return false;
		
		// Второй способ через if
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

	// Сложение двух векторов (Или точек)
	static const Point add(const Point& point1, const Point& point2)
	{ 
		return Point(point1._x + point2._x, point1._y + point2._y);
	}

	// Умножение вектора на число
	static const Point mult(const Point& point, double value) 
	{ 
		return Point(point._x * value, point._y * value);
	}

	// Операция деления  координат точки На число (Деление вектора на число)
	static const Point divide(const Point& point, double value)
	{
		return Point(point._x / value, point._y / value);
	}

		//Расстояние между двумя точками
	static double distance(const Point& point1, const Point& point2)
	{ 
		return sqrt(pow(point1._x - point2._x, 2) + pow(point1._y - point2._y, 2));
	}

		// Длинна вектора
	static double length(const Point& point) { }
};
int main()
{
	int count;// создали переменную Счётчик  - как будущий размер динамик памяти
	std::cin >> count;
	Point* point = new Point[count]; // под наш класс Point выделим
	// динамическую память размером [count]

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