#pragma once
#include <iostream>
using namespace std;

unsigned char translate1(char sym);
char translate2(unsigned char sym);
class BitArray
{
private:
	unsigned char* byte;
	int n;
	void oneLeftShift();
public:
	BitArray();
	BitArray(int a);
	BitArray(string a);
	BitArray(BitArray & a);
	~BitArray();
	void copy(int offset, int limit, BitArray a);
	void leftShift(int k);
	bool getBit(int i);
	int getN();
	unsigned char & operator[](int i);
	string getStr();
};

