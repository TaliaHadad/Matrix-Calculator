#pragma once
#include <iostream>
using namespace std;

/* this class represents matrices and various actions on them.
*/
class MyMatrix
{
	int _n, _m;
	double** _arr;
public:

	//get :
	int getRow();
	int getCol();
	double** getMatrix();

	//3 constructors (copy, mymatrix, defult):
	MyMatrix();
	MyMatrix(int n, int m);
	MyMatrix(const MyMatrix& MyMatrix);
	
	//distructor (because _arr is dynamic and must be delete):
	~MyMatrix();

	//functions:
	bool isValidCalc(int row1, int row2, int col1, int col2) const;
	bool isValidCalc(int row, int col) const;
	const MyMatrix operator+(const MyMatrix& MyMatrix) const;
	const MyMatrix operator-(const MyMatrix& MyMatrix) const;
	const MyMatrix operator*(const MyMatrix& MyMatrix) const;
	const MyMatrix operator*(int a) const;
	const MyMatrix  operator*(double a) const;
	MyMatrix& operator=(const MyMatrix& MyMatrix);
	bool operator==(const MyMatrix& MyMatrix) const;
	friend const MyMatrix operator*(int x, const MyMatrix& MyMatrix);
	friend const MyMatrix operator*(double x, const MyMatrix& newMatrix);
	double* operator[](int index);
	friend ostream& operator<<(ostream& out, const MyMatrix& MyMatrix);
	friend istream& operator>>(istream& in, const MyMatrix& MyMatrix);
	operator double() const;

};

