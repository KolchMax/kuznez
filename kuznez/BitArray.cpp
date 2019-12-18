#include "pch.h"
#include "BitArray.h"


unsigned char translate1(char sym)
{
	if (sym >= '0' && sym <= '9')
		return (unsigned char)(sym - '0');
	if (sym >= 'a' && sym <= 'f')
		return (unsigned char)(sym - 'a' + 10);
	if (sym >= 'A' && sym <= 'F')
		return (unsigned char)(sym - 'A' + 10);
	throw "Error at translate 1";
}

char translate2(unsigned char num)
{
	if (num <= 9)
	{
		return (char)num + '0';
	}
	if (num >= 10 && num <= 15)
	{
		return (char)num + 'a' - 10;
	}
	throw "Error at translate 2";
}

void BitArray::copy(int offset, int limit, BitArray a)
{
	this->n = limit;
	delete byte;
	this->byte = new unsigned char[this->n];
	for (int i = 0; i < n; i++)
	{
		this->byte[i] = a[offset + i];
	}
}

string BitArray::getStr()
{
	string res = "";
	unsigned char hiegh = 0, low = 0;
	for (int i = 0; i < n; i++)
	{
		hiegh = (byte[i] >> 4);
		low = (byte[i] & 0b1111);
		res = translate2(low) + res;
		res = translate2(hiegh) + res;
	}
	return res;
}

BitArray::BitArray()
{
	this->n = 0;
	byte = 0;
}

BitArray::BitArray(BitArray & a)
{
	this->n = a.getN();
	this->byte = new unsigned char[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->byte[i] = a[i];
	}
}

BitArray::BitArray(int a)
{
	n = 0;
	int temp = a;
	do
	{
		temp /= 256;
		n++;
	} while (a != 0);
	byte = new unsigned char[n];
	temp = a;
	for (int i = 0; i < n; i++)
	{
		byte[i] = temp % 256;
		temp /= 256;
	}
}

BitArray::BitArray(string a)
{
	if(a.length() % 2)
		this->n = a.length() / 2 + 1;
	else
		this->n = (a.length() / 2);
	byte = new unsigned char[n];
	for (int i = 0; i < a.length(); i++)
	{
		byte[i / 2] = 0;
		byte[i / 2] |= translate1(a[a.length() - 1 - i]);
		i++;
		byte[i / 2] |= (translate1(a[a.length() - 1 - i]) << 4);
	}
}

void BitArray::oneLeftShift()
{
	bool flag = false;
	unsigned char temp;
	for (int i = 0; i < n; i++)
	{
		temp = byte[i];
		if (flag)
		{
			byte[i] <<= 1;
			byte[i]++;
		}
		else
		{
			byte[i] <<= 1;
		}
		flag = (temp >= (1 << 8));
	}
}

void BitArray::leftShift(int k)
{
	for (int i = 0; i < k; i++)
	{
		oneLeftShift();
	}
}

BitArray::~BitArray()
{

}

bool BitArray::getBit(int i)
{
	return ((byte[i / 8] >> (i % 8)) & 1);
}

unsigned char & BitArray::operator [] (int i)
{
	return byte[i];
}

int BitArray::getN()
{
	return n;
}