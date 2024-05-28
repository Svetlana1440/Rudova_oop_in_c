#include <iostream>
#include <math.h>
using namespace std;

//����� Polynom
class Polynom{
private:

public:
	void CorrectDeg(); // ������� ������������� ������� ��������
	unsigned int deg; //������� ��������
	double *koef; //��������� �� ������ ������������� ��������
				  //koef[i] - ����������� ��� i-� �������,
				  //koef[0] - ����������� ��� ������� �������
	Polynom(); //����������� ��� ����������
	Polynom(unsigned int); //����������� � ����������
	Polynom(unsigned int, double*); //����������� � �����������
	Polynom(const Polynom &); //���������� �����������
	~Polynom(); //����������

	unsigned int GetDeg(); //������� ��������� ������� ��������
	double GetKoef(unsigned int); //������� ��������� ������������ ��� i-� �������
	unsigned int SetKoef(double, unsigned int); //������� ������� ������������ ��� i-� 
												//�������, ���������� ������� ��������
	Polynom operator + (const Polynom &);	//�������� �������� ���� ���������
	Polynom operator - (const Polynom& t) const; //�������� ��������� ���� ���������
	Polynom operator = (const Polynom &);	//�������� ������������
	friend Polynom MultConst(double, Polynom &); //������������� ������� ��������� ��������
											  //�� ���������
	Polynom operator * (const double K) const;//��������� �������� �� �����
	Polynom operator * (const Polynom& t) const;//��������� �������� �� �������

	Polynom operator / (const Polynom&);	// �������� ������� ���� ��������� � ���������� ��������
	Polynom operator % (const Polynom&);	// �������� ������� ���� ��������� � ���������� �������

	Polynom Divide(const Polynom& divisor, Polynom& quotient, Polynom& remainder);	// ������� ������� ���� ��������� � ���������� �������� � ������� ��������

	Polynom Derivative(int order);  // ������� ��� ������ ����������� ��������� �������

	Polynom Integrate();

	friend istream& operator>>(istream& in, Polynom& r);
	friend ostream& operator<<(ostream& out, const Polynom& r);
};

int factorial(int number);