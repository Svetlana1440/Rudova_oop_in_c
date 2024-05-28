#include <iostream>
#include <math.h>
using namespace std;

//класс Polynom
class Polynom{
private:

public:
	void CorrectDeg(); // функция корректировки степени полинома
	unsigned int deg; //степень полинома
	double *koef; //указатель на массив коэффициентов полинома
				  //koef[i] - коэффициент при i-й степени,
				  //koef[0] - коэффициент при нулевой степени
	Polynom(); //конструктор без параметров
	Polynom(unsigned int); //конструктор с параметром
	Polynom(unsigned int, double*); //конструктор с параметрами
	Polynom(const Polynom &); //копирующий контсруктор
	~Polynom(); //деструктор

	unsigned int GetDeg(); //функция получения степени полинома
	double GetKoef(unsigned int); //функция получения коэффициента при i-й степени
	unsigned int SetKoef(double, unsigned int); //функция задания коэффициента при i-й 
												//степени, возвращает степень полинома
	Polynom operator + (const Polynom &);	//оператор сложения двух полиномов
	Polynom operator - (const Polynom& t) const; //оператор вычитания двух полиномов
	Polynom operator = (const Polynom &);	//оператор присваивания
	friend Polynom MultConst(double, Polynom &); //дружественная функция умножения полинома
											  //на константу
	Polynom operator * (const double K) const;//умножение полинома на число
	Polynom operator * (const Polynom& t) const;//умножение полинома на полином

	Polynom operator / (const Polynom&);	// оператор деления двух полиномов с получением частного
	Polynom operator % (const Polynom&);	// оператор деления двух полиномов с получением остатка

	Polynom Divide(const Polynom& divisor, Polynom& quotient, Polynom& remainder);	// функция деления двух полиномов с получением частного и остатка отдельно

	Polynom Derivative(int order);  // Функция для взятия производной заданного порядка

	Polynom Integrate();

	friend istream& operator>>(istream& in, Polynom& r);
	friend ostream& operator<<(ostream& out, const Polynom& r);
};

int factorial(int number);