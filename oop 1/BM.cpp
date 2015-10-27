#include "BM.h"
#include "stdafx.h"

BoolMatrix::BoolMatrix()
{
	cout << "Вызов конструктора по умолчанию" << endl;
	storage = new int*[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
	hsize = vsize = maxsize;
	randomfill();
}

BoolMatrix::BoolMatrix(int v, int h)
{
	cout << "Вызов конструктора с параметрами" << endl;
	storage = new int*[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
	hsize = h;
	vsize = v;
	randomfill();
}

BoolMatrix::BoolMatrix(const BoolMatrix& m)
{
	cout << "Вызов конструктора копирования" << endl;
	storage = new int*[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
	hsize = m.hsize;
	vsize = m.vsize;
	for (int i = 0; i < maxsize; i++)
		for (int j = 0; j < maxsize; j++)
			storage[i][j] = m.storage[i][j];
}

BoolMatrix::~BoolMatrix()
{
	cout << "Вызов деструктора " << endl;
	for (int i = 0; i < maxsize; i++)
		delete[] storage[i];
	delete[] storage;
}

int BoolMatrix::gethsize() { return hsize; }

int BoolMatrix::getvsize() { return vsize; }

void BoolMatrix::randomfill()
{
	srand(time(NULL));
	for (int i = 0; i < hsize; i++)
		for (int j = 0; j < vsize; j++)
			if (storage[i][j] < 0)
				storage[i][j] = rand() % 2;
}

void BoolMatrix::printall()
{
	for (int i = 0; i < hsize; i++)
	{
		for (int j = 0; j < vsize; j++)
			cout << storage[i][j] << "";
		cout << endl;
	}
	cout << endl;
}

void BoolMatrix::checksize()
{
	for (int i = 0; i < maxsize; i++)
		for (int j = 0; j < maxsize; j++)
			if (i >= hsize || j >= vsize)
				storage[i][j] = -1;
}

void BoolMatrix::sethsize(int h)
{
	hsize = h;
	this->checksize();
	this->randomfill();
}

void BoolMatrix::setvsize(int v)
{
	vsize = v;
	this->checksize();
	this->randomfill();
}

void BoolMatrix::print(int v, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < v; j++)
			cout << storage[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void BoolMatrix::disjunction(const BoolMatrix & m, const BoolMatrix & c)
{
	cout << "Логическое сложение" << endl;
	if (m.hsize == c.hsize && m.vsize == c.vsize)
	{
		hsize = m.hsize;
		vsize = m.vsize;
		for (int i = 0; i < maxsize; i++)
			for (int j = 0; j < maxsize; j++)
				storage[i][j] = m.storage[i][j] || c.storage[i][j];
	}
	else
	{
		cout << "Матрицы не одинаковы по размеру " << endl;
	}
}
void BoolMatrix::conjunction(const BoolMatrix & m, const BoolMatrix & c)
{
	cout << "Логическое умножение" << endl;
	if (m.hsize == c.vsize)
	{
	hsize = m.hsize;
	vsize = c.vsize;
		for (int i = 0; i < hsize; i++)
			for (int j = 0; j < hsize; j++)
			{
				storage[i][j] = 0;
				for (int k = 0; k < hsize; k++)
					storage[i][j] = storage[i][j] || m.storage[i][k] && c.storage[k][j];
			}

	}
	else
	{
		cout << "Число столбцов 1 матрицы не совпадает с числом строк 2" << endl;
	}
}

void BoolMatrix::inversion(const BoolMatrix & m)
{
	cout << "Логическое отрицание" << endl;
	hsize = m.hsize;
	vsize = m.vsize;
	for (int i = 0; i < maxsize; i++)
		for (int j = 0; j < maxsize; j++)
			storage[i][j] = !m.storage[i][j];
}

int BoolMatrix::number(int v)
{
	int n = 0;
	for (int i = 0; i < hsize; i++)
	{
		for (int j = 0; j < vsize; j++)
			if (storage[i][j] == v)
				n++;
	}
	return n;
}
bool BoolMatrix::numberstr(int v)
{
	int n = 0;
	int t = 0;
	for (int i = 0; i < hsize+1; i++)
	{
			if (i != 0)
			{
				if (t == n)
					n = 0;
				else
					return false;
			}
			for (int j = 0; j < vsize; j++)
			{
				if (storage[i][j] == v)
				{
					n++;
					if (i == 0)
						t++;
				}
			}
	}
	return true;
}

void BoolMatrix::lgraphsort(const BoolMatrix & m)
{
	cout << "Упорядочение строк в лексикографическом порядке" << endl;

	for (int k = 0; k < hsize; k++)
	{
		for (int i = 0; i < vsize; ++i)
		{
			for (int j = 0; j < vsize - 1; ++j)
			{
				if (storage[k][j] > storage[k][j + 1])
				{
					int temp = storage[k][j];
					storage[k][j] = storage[k][j + 1];
					storage[k][j + 1] = temp;
				}
			}
		}
	}
}