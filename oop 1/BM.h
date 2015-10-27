#pragma once
#include <iostream>
#include <ctime>

class BoolMatrix
{
	int **storage;
	int hsize, vsize;
	static const int maxsize = 20;
public:
	BoolMatrix();
	BoolMatrix(int v, int h);
	BoolMatrix(const BoolMatrix &);
	~BoolMatrix();
	void sethsize(int);
	void setvsize(int);
	int gethsize();
	int getvsize();
	void printall();
	void print(int, int);
	void checksize();
	void randomfill();
	void disjunction( const BoolMatrix & m, const BoolMatrix & c);
	void conjunction(const BoolMatrix & m, const BoolMatrix & c);
	void inversion(const BoolMatrix & m);
	int number(int v);
	bool numberstr(int v);
	void lgraphsort(const BoolMatrix & m);
};
