
#include <iostream>
#include "MyBigNum.h"


int main()
{
	string str1;
	string str2;
	int str1Len, str2Len;
	cout << "Enter first num: ";
	cin >> str1;
	cout << "Enter second num: ";
	cin >> str2;
	str1Len = str1.size();
	str2Len = str2.size();
	MyBigNum a;
	MyBigNum b;
	a.setHex(str1);
	b.setHex(str2);
	string rez;
	MyBigNum ADD;
	a.ADD(&ADD, &b);
	rez = ADD.getHex();
	cout << " First + Second = "<< rez<<endl;
	MyBigNum SUB;
	a.SUB(&SUB, &b);
	rez = SUB.getHex();
	cout <<" First - Second = " << rez << endl;
	//end
}
