#include "ClassPolynom.h"
#include <math.h>
using namespace std;


// конструктор без параметров: создается полином нулевой степени
// с коэффициентом при нулевой степени равным нулю
Polynom::Polynom() {
	deg = 0;
	koef = new double[deg + 1];//массив из одного символа коэффициента
	koef[0] = 0.0;
}


//Этот конструктор принимает только один параметр - new_deg (степень создаваемого полинома). 
// Он инициализирует степень полинома с заданным значением и создает массив коэффициентов, 
// устанавливая все коэффициенты в начальное значение равное нулю.
Polynom::Polynom(unsigned int new_deg) {
	deg = new_deg;
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = 0; // инициализация массива коэффициентов нулями
}


// конструктор с параметрами
// new_deg - степень создаваемого полинома
// newkoef - указатель на new_deg+1 - элементный массив с коэффициентами 
// 	 		 полинома, где newkoef[i] - коффициент при i-й степени
//			 и newkoef[0] - коэффициент при нулевой степени
// В результате степень полинома будет наибольшим номером ненулевого
// элемента массива new_koef и меньше или равна new_deg (по определению степени полинома)
Polynom::Polynom(unsigned int new_deg, double* new_koef) {
	deg = 0;
	for (int i = 0; i <= new_deg; i++)
		if (new_koef[i] != 0) deg = i;	//инициализация переменной степени
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = new_koef[i]; //инициализация массива коэффициентов
}

//копирующий конструктор
Polynom::Polynom(const Polynom& f) {
	deg = f.deg;
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = f.koef[i];
}

//деструктор
Polynom::~Polynom() {
	delete[] koef;
}
// функция получения степени полинома
unsigned int Polynom::GetDeg() {
	return deg;
}

// функция получения коэффициента при i-й степени
double Polynom::GetKoef(unsigned int i) {
	if (i <= deg)
		return koef[i];
	else
		return 0.0;
}

// функция задания коэффициента при i-й степени
unsigned int Polynom::SetKoef(double new_koef, unsigned int i) {
	if (i <= deg) koef[i] = new_koef;
	else return deg;
	CorrectDeg();
	return deg;
}

//оператор сложения двух полиномов
Polynom Polynom::operator + (const Polynom& t) {
	int i;
	Polynom* result;

	if (deg >= t.deg) {	//если степень первого полинома больше степени второго
		result = new Polynom(deg, koef);
		for (i = 0; i <= t.deg; i++)
			result->koef[i] = result->koef[i] + t.koef[i];
	}
	else {					//если степень второго полинома больше степень первого
		result = new Polynom(t.deg, t.koef);
		for (i = 0; i <= deg; i++)
			result->koef[i] = result->koef[i] + koef[i];
	}
	result->CorrectDeg();
	return *result;
}

// Оператор вычитания двух полиномов
Polynom Polynom::operator - (const Polynom& t) const {
	int i;
	Polynom result;

	if (deg >= t.deg) {  // если степень первого полинома больше степени второго
		result = Polynom(deg);
		for (i = 0; i <= deg; i++)
			result.koef[i] = koef[i];
		for (i = 0; i <= t.deg; i++)
			result.koef[i] -= t.koef[i];
	}
	else {  // если степень второго полинома больше степени первого
		result = Polynom(t.deg);
		for (i = 0; i <= t.deg; i++)
			result.koef[i] = -t.koef[i];
		for (i = 0; i <= deg; i++)
			result.koef[i] += koef[i];
	}
	result.CorrectDeg();
	return result;
}

//оператор присваивания
Polynom Polynom::operator = (const Polynom& t) {
	deg = t.deg;
	delete[] koef;
	koef = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		koef[i] = t.koef[i];
	return *this;
}

//оператор умножения полинома на число
Polynom Polynom::operator * (const double K) const {
	Polynom res = *this;
	return MultConst(K, res);
}


//функция реализующая умножение полинома на число
Polynom MultConst(double K, Polynom& t) {
	if (K == 0) {
		Polynom result;
		return result;
	}
	else {
		int deg = t.deg;
		double* tmp_koef = new double[deg + 1];
		for (int i = 0; i <= deg; i++)
			tmp_koef[i] = K * t.koef[i];
		Polynom result(deg, tmp_koef);
		delete[] tmp_koef;
		return result;
	}
}

// Оператор умножения полинома на полином
Polynom Polynom::operator* (const Polynom& t) const{
	Polynom k = t;
	Polynom g = *this;
	unsigned int new_deg = g.deg + k.deg;
	double* new_koef = new double[new_deg + 1]();

	for (unsigned int i = 0; i <= g.deg; i++) {
		for (unsigned int j = 0; j <= k.deg; j++) {
			new_koef[i + j] += g.koef[i] * k.koef[j];
		}
	}
	Polynom result(new_deg, new_koef);
	delete[] new_koef;
	return result;
}

int factorial(int number) {
	int a = 1;
	for (int i = 1; i <= number; i++) {
		a *= i;
	}
	return a;
}

// Оператор деления двух полиномов с получением частного
Polynom Polynom::operator / (const Polynom& divisor) {
	Polynom quotient;
	Polynom remainder;
	Divide(divisor, quotient, remainder);
	return quotient;
}

// Оператор деления двух полиномов с получением остатка
Polynom Polynom::operator % (const Polynom& divisor) {
	Polynom quotient;
	Polynom remainder;
	Divide(divisor, quotient, remainder);
	return remainder;
}

// Функция деления двух полиномов с получением частного и остатка отдельно
Polynom Polynom::Divide(const Polynom& divisor, Polynom& quotient, Polynom& remainder) {
	if (divisor.deg == 0 && divisor.koef[0] != 0) {
		// Если делитель - константа (ненулевая)
		double constant = divisor.koef[0];
		quotient = *this / constant;
		remainder = Polynom();
		return remainder;
	}

	unsigned int dividendDeg = deg;
	unsigned int divisorDeg = divisor.deg;

	if (dividendDeg < divisorDeg) {
		// Если степень делимого меньше степени делителя, возвращаем ноль в частном и делимое в остатке
		quotient = Polynom();
		remainder = *this;
		return remainder;
	}

	Polynom tmp(*this);
	Polynom div(divisor);

	quotient = Polynom(dividendDeg - divisorDeg + 1);

	for (unsigned int i = dividendDeg - divisorDeg + 1; i > 0; i--) {
		quotient.koef[i - 1] = tmp.koef[tmp.deg] / div.koef[div.deg];
		unsigned int j = 0;
		for (; j <= div.deg; j++) {
			tmp.koef[tmp.deg - j] -= quotient.koef[i - 1] * div.koef[div.deg - j];
		}
		tmp.CorrectDeg();
	}

	remainder = tmp;
	return remainder;
}


//Производные
Polynom Polynom::Derivative(int order) {
	if (order <= 0) {
		return *this;
	}

	int resultDeg = deg - order;
	if (resultDeg < 0) {
		return Polynom();
	}

	double* resultKoef = new double[resultDeg + 1];

	for (int i = 0; i <= resultDeg; i++) {
		resultKoef[i] = koef[i + order] * factorial(i + order) / factorial(i);
	}

	Polynom result(resultDeg, resultKoef);

	delete[] resultKoef;

	return result;
}

//Интегрирование
Polynom Polynom::Integrate() {
	int resultDeg = deg + 1;
	double* resultKoef = new double[resultDeg + 1];

	resultKoef[0] = 0;  // Коэффициент при свободном члене всегда 0 после интегрирования

	for (int i = 1; i <= resultDeg; i++) {
		resultKoef[i] = koef[i - 1] / i;
	}

	Polynom result(resultDeg, resultKoef);

	delete[] resultKoef;

	return result;
}


// функция корректировки степени полинома: коэффициент 
// при максимальной степени должен быть ненулевым
void Polynom::CorrectDeg() {
	while (deg > 0 && koef[deg] == 0) {
		deg--;
	}
}

//оператор ввода полинома
istream& operator>>(istream& in, Polynom& r) {
	cout << "Input degree: ";
	in >> r.deg;
	delete[] r.koef;
	r.koef = new double[r.deg + 1];

	cout << "Input coefficients from lowest to highest degree:" << endl;
	for (int i = 0; i <= r.deg; ++i) {
		cout << "Coefficient for x^" << i << ": ";
		in >> r.koef[i];
	}
	r.CorrectDeg(); // Корректируем степень полинома
	return in;
}

//оператор вывода полинома
ostream& operator<<(ostream& out, const Polynom& r) {
	if (r.deg == 0 && r.koef[0] == 0) {
		out << "0";
		return out;
	}

	bool firstTerm = true;

	for (int i = r.deg; i >= 0; --i) {
		if (r.koef[i] == 0) { continue; }

		if (!firstTerm) {
			if (r.koef[i] > 0) { out << " + "; }
			else {out << " - ";}
		}
		else {
			if (r.koef[i] < 0) { out << "-"; }
			firstTerm = false;
		}

		double absCoef = abs(r.koef[i]);

		if (i == 0) {
			out << absCoef;
		}
		else if (i == 1) {
			if (absCoef == 1) { out << "X"; }
			else { out << absCoef << "X"; }
		}
		else {
			if (absCoef == 1) { out << "X^" << i; }
			else { out << absCoef << "X^" << i; }
		}
	}

	return out;
}


