#include "polynom/ClassPolynom.h"
#include"iostream"
#include"math.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru-RU");
	
	//Сложение двух многочленов
	cout << "Сложение двух многочленов: " << endl;
	double koeff1[] = { 1, 2, 3 }; // Создаем полиномы P(x) = 1 + 2x + 3x^2 и Q(x) = 4 + 5x
	Polynom polyn(2, koeff1);
	double koeff2[] = { 4, 5 };
	Polynom quan(1, koeff2);

	Polynom result_add = polyn + quan;// Складываем полиномы P(x) и Q(x)
	cout << "Многочлен 1: " << polyn << endl << "Многочлен 2: " << quan << endl << "Многочлен 1 + Многочлен 2 = " << result_add << endl;

	double koeff3[] = { 2, 0, 4 }; // Создаем еще один полином R(x) = 2 + 0x + 4x^2
	Polynom res(2, koeff3);

	result_add = polyn + res;// Складываем полиномы P(x) и R(x)
	cout << "Многочлен 1: " << polyn << endl << "Многочлен 2: " << res << endl << "Многочлен 1 + Многочлен 2 = " << result_add << endl << endl;


	//Вычитание двух многочленов
	cout << "Вычитание двух многочленов: " << endl;
	double koeffi1[] = { 1, 2, 3 }; // Создаем полиномы P(x) = 3x^2 + 2x + 1 и Q(x) = 5x + 4
	Polynom poligonn(2, koeffi1);
	double koeffi2[] = { 4, 5 };
	Polynom count(1, koeffi2);
	Polynom result_subtrac = poligonn - count; // Вычитаем полиномы P(x) и Q(x)
	cout << "Многочлен 1: " << poligonn << endl << "Многочлен 2: " << count << endl << "Многочлен 1 - Многочлен 2 = " << result_subtrac << endl;

	double koef3[] = { 2, 0, 4 }; // Создаем еще один полином R(x) = 4x^2 + 0x + 2
	Polynom ress(2, koef3);
	result_subtrac = poligonn - ress;// Вычитаем полиномы P(x) и R(x)
	cout << "Многочлен 1: " << poligonn << endl << "Многочлен 2: " << ress << endl << "Многочлен 1 - Многочлен 2 = " << result_subtrac << endl << endl;


	//Умножение
	cout << "Умножение многочлена на число: " << endl;
	double koef[] = { 1, 2, 3 }; // Создаем полином P(x) = 1 + 2x + 3x^2
	Polynom pol(2, koef);
	Polynom result_mult = pol * 3;// Умножаем многочлен на число 3
	cout << "Многочлен 1: " << pol << endl << "Многочлен 1 * 3 = " << result_mult << endl << endl;


	cout << "Умножение многочлена на многочлен: " << endl;
	double koef1[] = { 1, 2, 3 }; // Создаем полиномы P(x) = 1 + 2x + 3x^2 и Q(x) = 4 + 5x
	Polynom polinom(2, koef1);
	double koef2[] = { 4, 5 };
	Polynom quantity(1, koef2);
	Polynom result = polinom * quantity; // Умножаем полиномы P(x) и Q(x)
	cout << "Многочлен 1: " << polinom << endl << "Многочлен 2: " << quantity << endl << "Многочлен 1  * Многочлен 2 = " << result << endl << endl;


	//Деление
	cout << "Деление многочленов: " << endl;
	Polynom p1(3, new double[4] {1, 2, 3, 4});    // Полином 2x^3-3x-2
	Polynom p2(2, new double[3] {2, 2, 1});       // Полином x+2
	cout << "Многочлен 1: " << p1 << endl << "Многочлен 2: " << p2 << endl;

	Polynom q = p1 / p2;                         // Частное от деления p1 на p2
	Polynom r = p1 % p2;                         // Остаток от деления p1 на p2
	cout << "Частное от деления p1 на p2: " << q << endl << "Остаток от деления p1 на p2: " << r  << endl;

	Polynom q2, r2;
	p1.Divide(p2, q2, r2);                       // Частное и остаток от деления p1 на p2 отдельно
	cout << "Частное и остаток от деления p1 на p2 отдельно: " << "("<<q2<<")" << "*" << "(" << p2 << ")" << "+" << "(" << r2 << ")" << endl << endl;


	//Производные
	cout << "Взятия производной произвольного порядка с получением нового объекта-многочлена: " << endl;
	Polynom p(4, new double[5] {1, 2, 3, 4, 5});   // Полином 1 + 2x + 3x^2 + 4x^3 + 5x^4
	cout << "Полином: " << p << endl;

	Polynom derivative1 = p.Derivative(1);         // Производная первого порядка: 2 + 6x + 12x^2 + 20x^3
	Polynom derivative2 = p.Derivative(2);         // Производная второго порядка: 6 + 24x + 60x^2
	cout << "Производная первого порядка: " << derivative1 << endl << "Производная второго порядка: " << derivative2 << endl << endl;


	//Интегрирование
	cout << "Операцию интегрирования многочлена: " << endl;
	Polynom p3(4, new double[5] {2, 3, 4, 5, 6});   // Полином 2 + 3x + 4x^2 + 5x^3 + 6x^4
	Polynom integral = p3.Integrate();             // Интеграл: C + 2x + 3/2x^2 + 2x^3 + 3x^4 + 6/5x^5, где C - константа интегрирования
	cout << "Многочлен: " << p3 << endl << "Интеграл: " << integral << endl << endl;

}