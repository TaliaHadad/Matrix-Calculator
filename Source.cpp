/******************
exe03
Talia Hadad 209049253
Tali Klinger Deutch 208646398
******************/

#include "MyMatrix.h"
#include <iostream>
using namespace std;

int main()
{
	MyMatrix m1(2, 2);
	MyMatrix m2(2, 2);
	MyMatrix m3(2, 2);
	cout << "Insert values for m1:" << endl;
	cin >> m1;
	cout << "Insert values for m2:" << endl;
	cin >> m2;
	cout << "Insert values for m3:" << endl;
	cin >> m3;
	cout << "m1: " << endl << m1 << "m2:" << endl << m2 << "m3:" << endl << m3 << endl << endl;
	cout << "m1+m2+m3:" << endl << m1 + m2 + m3 << endl;
	cout << "m1-m2-m3:" << endl << m1 - m2 - m3 << endl;
	cout << "m1-m2+m3:" << endl << m1 - m2 + m3 << endl;
	cout << "m1*m2:" << endl << m1 * m2 << endl;
	cout << "3*m1:" << endl << 3 * m1 << endl;
	cout << "m1*10.8:" << endl << m1 * 10.8 << endl;
	cout << "m3 = m2:" << endl << (m3 = m2) << endl;
	cout << "m1 == m2:" << endl << (m1 == m2) << endl;
	MyMatrix m4(m3);//copy constructor
	cout << "m4 == m3:" << endl << (m4 == m3) << endl;
	MyMatrix m5(2, 3);
	cout << "Insert values for m5:" << endl;
	cin >> m5;
	cout << "m5: " << endl << m5 << endl;
	cout << "m1+m5:" << endl;
	try
	{
		cout << m1 + m5;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "m1-m5:" << endl;
	try
	{
		cout << m1 - m5;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "m1*m5:" << endl;
	try
	{
		cout << m1 * m5;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "m5*m1:" << endl;
	try
	{
		cout << m5 * m1;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "m1 = m5:" << endl;
	try
	{
		cout << (m1 = m5);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << endl << "m1: " << endl << m1;
	cout << endl << "m1[0][1]: ";
	try
	{
		cout << m1[0][1];
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << endl << "m1[9][1]: ";
	try
	{
		cout << m1[9][1];
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << endl << "m2: " << endl << m2;
	m2[0][0] = 3.5;
	cout << endl << "m2[0][0]=3.5: " << endl << m2;
	double sumOfM1;
	sumOfM1 = (double)m1;
	cout << endl << endl << "The sum of m1 is: " << sumOfM1 << endl << endl;


}