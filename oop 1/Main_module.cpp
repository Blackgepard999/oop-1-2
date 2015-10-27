#include "stdafx.h"
#include "BM.h"
#include <locale>

int main()
{
	setlocale(LC_ALL, ".1251");

	///// ������� ������ ��������. �������:
	///// a)  ������ ������ � ����������/���������� ����������� ������;
	///// b)  ������ ������ � ����� ���������� ����� � ������ ������
	int const size = 3;
	BoolMatrix mas[size] = {BoolMatrix(2,2),BoolMatrix(3,3), BoolMatrix(4,4)};
	
	for (int i = 0; i < size; i++)
	{
		mas[i].printall();
	}

	
	int max = 0;
	int min = 1000;
	int n = 0;
	int l = 0;

	for (int i = 0; i < size; i++)
	{
		if (max < mas[i].number(1))
		{
			max = mas[i].number(1);
			n = i + 1;
		}
		if (min > mas[i].number(1))
		{
			min = mas[i].number(1);
			l = i + 1;
		}
	}

	cout << "���������� ���������� ������ � ������� " << n << " ---- " << max << endl;
	cout << "���������� ���������� ������ � ������� " << l << " ---- " << min << endl;


	for (int i = 0; i < size; i++)
	{
		bool y = 0;
		y = mas[i].numberstr(0);
		if (y == true)
			cout << "������� " << i + 1 << " � ������ ����������� ����� � ������ ������" << endl;
	}

	///// ������������ ����� � ������������������ ������� //////
	/*BoolMatrix a = BoolMatrix(5, 4);
	a.printall();
	BoolMatrix c = BoolMatrix(5, 4);
	c.lgraphsort(a);
	c.printall();*/
	/////////////////////////////////

	///// ���������� ������ � ������� //////
	/*BoolMatrix a = BoolMatrix(2, 2);
	a.printall();
	int n = 0;
	n = a.number(1);
	cout << "������� �������� " << n << " ---- " << 1 << endl;
	*/
	/////////////////////////////////

	///// ���������� ��������� //////
	/*BoolMatrix a = BoolMatrix(2, 2);
	a.printall();
	BoolMatrix c = BoolMatrix(2, 2);
	c.printall();
	c.inversion(a);
	c.printall();*/
	/////////////////////////////////

	///// ���������� ��������� //////
	/*BoolMatrix a = BoolMatrix(2, 2);
	a.printall();
	int d; cin >> d;
	BoolMatrix b = BoolMatrix(2, 2);
	b.printall();
	BoolMatrix c = BoolMatrix(2, 2);
	c.conjunction(a, b);
	c.printall();*/
	/////////////////////////////////

	///// ���������� �������� //////
	/*BoolMatrix a = BoolMatrix(4, 5);
	a.printall();
	int d; cin >> d;
	BoolMatrix b = BoolMatrix(4, 5);
	b.printall();
	BoolMatrix c = BoolMatrix(4, 5);
	c.disjunction(a, b);
	c.printall();*/

	/////////////////////////////////

	return 0;
}