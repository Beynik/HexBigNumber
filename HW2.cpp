
#include <iostream>
#include "MyBigNum.h"


int main()
{
	string str1;
	string str2;
	int str1Len, str2Len;
	cout << "Enter first num: ";
	cin >> str1;
	cout << "Enter second num ";
	cin >> str2;
	str1Len = str1.size();
	str2Len = str2.size();
	MyBigNum a;
	MyBigNum b;
	a.setHex(str1);
	b.setHex(str2);
	/*
	a.setBinary(str2);*/
	/*for (int i = 0; i <= 255; i++) {
		std::cout << a._numD[i];
	}*/
	string rez;
	rez=a.getHex();
	cout << rez;
	MyBigNum REZ;
	a.ADD(&REZ, &b);
	rez = REZ.getHex();
	cout << rez;
}
