#include "MyMatrix.h"
#include <iostream>
using namespace std;


// get:
int MyMatrix:: getRow()
{ 
	return _m;
}
int MyMatrix ::getCol()
{ 
	return _n;
}
double** MyMatrix::getMatrix()
{
	//allocate memory for N*M matrix
	double** newMatrix = new double* [_m];
	for (int i = 0; i < _m; ++i)
		newMatrix[i] = new double[_n];
	//coping the matrix
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			newMatrix[i][j] = _arr[i][j];
	return newMatrix;
}
//3 constructors (copy, mymatrix, defult):
/*
	defult constructor - The function initialize the MyMatrix object. 
	no input & no output
*/
MyMatrix::MyMatrix()
{
	_m = 3;
	_n = 3;
	//allocate memory for 3*3 matrix
	_arr = new double* [3];
	for (int i = 0; i < _m; ++i)
		_arr[i] = new double[3];
	//intialize all the values of the matrix to 0
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_arr[i][j] = 0;
}
/*
	constructor - The function initialize the MyMatrix object with n*m matrix.
	gets 2 indexes for the size of the matrix for input & no output.
*/
MyMatrix::MyMatrix(int n, int m)
{
	_m = n;
	_n = m;
	//allocate memory for N*M matrix
	_arr = new double* [_m];
	for (int i = 0; i < _m; ++i)
		_arr[i] = new double[_n];
	//intialize all the data to 0
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_arr[i][j] = 0;
}
/*
	copy constructor - The function copy the MyMatrix object.
	gets a MyMatrix object for input & no output.
*/
MyMatrix::MyMatrix(const MyMatrix& newMatrix)
{
	_m = newMatrix._m;
	_n = newMatrix._n;
	//allocate memory
	_arr = new double* [_m];
	for (int i = 0; i < _m; ++i)
		_arr[i] = new double[_n];
	//copying the data
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_arr[i][j] = newMatrix._arr[i][j];
}
//distructor (because _arr is dynamic and must be delete):
/*
	destructor - The function deleting all the memory.
	no input & no output.
*/
MyMatrix::~MyMatrix()
{
	for (int i = 0; i < _m; i++)
		delete[] _arr[i];
	delete[] _arr;
}
//functions:
/*
	isValidCalc - The function return true if the 2 matrixes have the same number of rows and the same number of cols, else it returns false.
	gets 2 rows indexes and 2 col indexes for input & return true/false for output.
	*/
bool MyMatrix::isValidCalc(int row1, int row2, int col1, int col2) const
{
	return(row1 == row2 && col1 == col2); 
}
/*
isValidCalc - The function return true if the number of rows from the first matrix is the same as the numebr of col of the second matrix, else it returns false.
gets row index and col index for input & return true/false for output. 
*/
bool MyMatrix:: isValidCalc(int row, int col) const
{
	return (row == col);
}
/*
	operator+ - The function calculate the + operator between 2 matrixes.
	gets a MyMatrix object for input & return a MyMatrix object for output.
*/
const MyMatrix MyMatrix:: operator+(const MyMatrix& a) const
{
	if (!isValidCalc(_m, a._m, _n, a._n))
	{
		throw "The operation is not possible, the matrices have different dimensions.";
	}
	MyMatrix newMatrix;
	newMatrix._n = _n;
	newMatrix._m = _m;
	//allocate memory for N*M matrix
	newMatrix._arr = new double* [newMatrix._m];
	for (int i = 0; i < _m; ++i)
		newMatrix._arr[i] = new double[newMatrix._n];
	//coping the data
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			newMatrix._arr[i][j] = _arr[i][j] + a._arr[i][j];
	return newMatrix;
}
/*
     operator- - The function calculate the - operator between 2 matrixes.
     gets a MyMatrix object for input & return a MyMatrix object for output.
*/
const MyMatrix MyMatrix:: operator-(const MyMatrix& a) const
{
	if (!isValidCalc(_m, a._m, _n, a._n))
	{
		throw "The operation is not possible, the matrices have different dimensions.";
	}
	MyMatrix newMatrix;
	newMatrix._n = _n;
	newMatrix._m = _m;
	//allocate memory for N*M matrix
	newMatrix._arr = new double* [newMatrix._m];
	for (int i = 0; i < _m; ++i)
		newMatrix._arr[i] = new double[newMatrix._n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			newMatrix._arr[i][j] = _arr[i][j] - a._arr[i][j];
	return newMatrix;
}
/*
operator* - The function calculate the * operator between 2 matrixes.
gets a MyMatrix object for input & return a MyMatrix object for output.
*/
const MyMatrix MyMatrix:: operator*(const MyMatrix& a) const
{
	if (!isValidCalc(_n, a._m))
	{
		throw "The operation is not possible, the matrices have different dimensions.";
	}
	MyMatrix newMatrix;
	newMatrix._n = a._n;//takes the number of colom from the second matrix
	newMatrix._m = _m;//takes the number of rows from the first matrix
	//allocate memory for N*M matrix
	newMatrix._arr = new double* [newMatrix._m];
	for (int i = 0; i < _m; i++)
		newMatrix._arr[i] = new double[newMatrix._n];
	//nullify the new matrix
	for (int i = 0; i < newMatrix._m; i++)
		for (int j = 0; j < newMatrix._n; j++)
			newMatrix._arr[i][j] = 0;
	//calculating the this*a of each cell
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			for (int k = 0; k < _n; k++)
				newMatrix._arr[i][j] += _arr[i][k] * a._arr[k][j];
	return newMatrix;
}
/*
operator* - The function calculate the * operator between a matrix and a scalar.
gets an integer scalar for input & return a MyMatrix object. 
*/
const MyMatrix MyMatrix:: operator*(int a) const
{
	MyMatrix temp(this->_m, this->_n);
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			temp[i][j] = _arr[i][j] * a;
	return temp;
}
/*
operator* - The function calculate the * operator between a matrix and a scalar.
gets an double scalar for input & return a MyMatrix object.
*/
const MyMatrix MyMatrix:: operator*(double a) const
{
	MyMatrix temp(this->_m, this->_n);
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			temp[i][j] = _arr[i][j] * a;
	return temp;
}
/*
operator= - The function operation: The function copys one matrix to another.
gets a MyMatrix object for input & return a MyMatrix object for output.
*/
MyMatrix& MyMatrix:: operator=(const MyMatrix& newMatrix)
{
	//checking if its the same Matrix
	if (*this == newMatrix)
		return *this;
	//checking if its possible to copy the Matrix to the other Matrix
	if (!isValidCalc(_m, newMatrix._m, _n, newMatrix._n))
	{
		throw "The operation is not possible, the matrices have different dimensions.";
	}
	//coping the data of the Matrix
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_arr[i][j] = newMatrix._arr[i][j];
	return *this;
}
/*
operator== - The function returns true if the two matrix are identical else it returns false.
gets a MyMatrix object for input & return true/false for output.
*/
bool MyMatrix:: operator==(const MyMatrix& a) const
{
	if (!isValidCalc(_m, a._m, _n, a._n))
		return false;
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			if (_arr[i][j] != a._arr[i][j])//if only one is different they are not equal
				return false;
	return true;
}
/*
operator* - The function calculate the * operator between a matrix and a scalar.
gets a MyMatrix object and integer scalar for input & return a MyMatrix object for output.
*/
const MyMatrix operator*(int x, const MyMatrix& newMatrix)
{
	return newMatrix * x;// calling the other operator* function
}
/*
operator* - The function calculate the * operator between a matrix and a scalar.
gets a MyMatrix object and double scalar for input & return a MyMatrix object for output.
*/
const MyMatrix operator*(double x, const MyMatrix& newMatrix)
{
	return newMatrix * x;// calling the other operator* function
}
/*
operator[] - The function returns the array in the index position.
gets an integer index for input & return an arry according to the index for output.
*/
double* MyMatrix:: operator[](int index)
{
	if (index < 0 || index >= this->getRow())
		throw "Out of the matrix range";
	return _arr[index];
}
/*
operator<< - The function printing the matrix.
gets a MyMatrix object and ostream out & return ostream out for output.
*/
ostream& operator<<(ostream& out, const MyMatrix& MyMatrix)
{
	for (int i = 0; i < MyMatrix._m; i++)
	{
		for (int j = 0; j < MyMatrix._n; j++)
			out << MyMatrix._arr[i][j] << "\t";
		out << endl;
	}
	return out;
}
/*
operator>> - The function obserb the matrix.
gets a MyMatrix object and istream in & return istream in for output.
*/
istream& operator>>(istream& in, const MyMatrix& MyMatrix)
{
	for (int i = 0; i < MyMatrix._m; i++)
	{
		for (int j = 0; j < MyMatrix._n; j++)
			in >> MyMatrix._arr[i][j];
	}
	return in;
}
/*
operator double () - The function sum the matrix.
no input & return matrixsum for output.
*/
MyMatrix::operator double() const
{
	double matrixSum = 0;
	for (int i = 0; i < this->_m; i++)
	{
		for (int j = 0; j < this->_n; j++)
			matrixSum = matrixSum + this->_arr[i][j];
	}
	return matrixSum;
}
