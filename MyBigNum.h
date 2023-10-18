#pragma once
#define SIZE 255
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

using namespace std;


class MyBigNum
{
public:
	void setHex(string str);
	string getHex();
	void ADD(MyBigNum* rez, MyBigNum* second);
	bool compare(MyBigNum* second);
	void SUB(MyBigNum* rez, MyBigNum* second);
	void MOD(MyBigNum* rez, MyBigNum* second);
	void print() {
		std::cout << "hi";
		for (int i = 0; i <= 255; i++) {
			_numD[i] = 0;
		}
		std::cout << 15 % 10;
	}
	//private:
	uint64_t* _numD = new uint64_t[SIZE]();
	char** _numB = new char* [SIZE];
	uint64_t Lenght=SIZE;
};

