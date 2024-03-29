#include "pch.h"
#include <iostream>
#include <string>
#include "BitArray.h"
using namespace std;

const unsigned char pi[] = { 252, 238,  221,  17,  207,  110,  49,  22,  251,  196,  250,  218,  35,  197,  4,  77,  233,  119,  240,  219,  147,  46, 153,  186, 23, 54, 241,  187, 20, 205, 95,  193, 249, 24,  101,90, 226, 92, 239, 33,  129, 28, 60, 66, 139,  1, 142, 79, 5,  132, 2,  174, 227,  106,  143,  160, 6,  11,237,  152,  127, 212, 211,31,235, 52, 44, 81,234, 200, 72, 171, 242, 42,  104,  162,  253,  58,  206,  204,  181,  112,  14, 86, 8,  12,  118,  18,  191,  114,  19,  71,  156,  183,  93,  135, 21,  161,  150, 41,  16,  123,  154,  199, 243,  145,  120,  111,  157,  158,  178,  177,  50,  117,  25, 61, 255, 53,  138, 126,  109,  84,  198,  128,  195,  189,  13,  87, 223,  245,  36,  169,  62,  168,  67, 201, 215,  121, 214, 246,  124,  34, 185,  3, 224,  15, 236, 222,  122,  148,  176,  188, 220, 232, 40,  80, 78, 51,  10, 74,  167,  151, 96, 115, 30, 0, 98, 68,  26,  184,  56,  130,  100,  159,  38, 65,  173,  69, 70,  146,  39,  94, 85,  47,  140,  163,  165,  125,  105, 213,  149, 59,  7, 88,  179,  64,  134,  172,  29,  247,  48,  55,  107,  228,  136,  217,  231,  137,  225,  27,  131,  73, 76, 63, 248, 254,  141,83,  170,  144, 202, 216,  133, 97, 32,  113,  103,  164, 45, 43, 9, 91,203,  155, 37, 208, 190, 229,  108, 82, 89,  166,  116, 210, 230, 244, 180,  192, 209,  102,  175,  194, 57, 75, 99,  182 };

const unsigned char invpi[] = 
{
	0xA5, 0x2D, 0x32, 0x8F, 0x0E, 0x30, 0x38, 0xC0, 	// 00..07
	0x54, 0xE6, 0x9E, 0x39, 0x55, 0x7E, 0x52, 0x91, 	// 08..0F
	0x64, 0x03, 0x57, 0x5A, 0x1C, 0x60, 0x07, 0x18, 	// 10..17
	0x21, 0x72, 0xA8, 0xD1, 0x29, 0xC6, 0xA4, 0x3F, 	// 18..1F
	0xE0, 0x27, 0x8D, 0x0C, 0x82, 0xEA, 0xAE, 0xB4, 	// 20..27
	0x9A, 0x63, 0x49, 0xE5, 0x42, 0xE4, 0x15, 0xB7, 	// 28..2F
	0xC8, 0x06, 0x70, 0x9D, 0x41, 0x75, 0x19, 0xC9, 	// 30..37
	0xAA, 0xFC, 0x4D, 0xBF, 0x2A, 0x73, 0x84, 0xD5, 	// 38..3F
	0xC3, 0xAF, 0x2B, 0x86, 0xA7, 0xB1, 0xB2, 0x5B, 	// 40..47
	0x46, 0xD3, 0x9F, 0xFD, 0xD4, 0x0F, 0x9C, 0x2F, 	// 48..4F
	0x9B, 0x43, 0xEF, 0xD9, 0x79, 0xB6, 0x53, 0x7F, 	// 50..57
	0xC1, 0xF0, 0x23, 0xE7, 0x25, 0x5E, 0xB5, 0x1E, 	// 58..5F
	0xA2, 0xDF, 0xA6, 0xFE, 0xAC, 0x22, 0xF9, 0xE2, 	// 60..67
	0x4A, 0xBC, 0x35, 0xCA, 0xEE, 0x78, 0x05, 0x6B, 	// 68..6F
	0x51, 0xE1, 0x59, 0xA3, 0xF2, 0x71, 0x56, 0x11, 	// 70..77
	0x6A, 0x89, 0x94, 0x65, 0x8C, 0xBB, 0x77, 0x3C, 	// 78..7F
	0x7B, 0x28, 0xAB, 0xD2, 0x31, 0xDE, 0xC4, 0x5F, 	// 80..87
	0xCC, 0xCF, 0x76, 0x2C, 0xB8, 0xD8, 0x2E, 0x36, 	// 88..8F
	0xDB, 0x69, 0xB3, 0x14, 0x95, 0xBE, 0x62, 0xA1, 	// 90..97
	0x3B, 0x16, 0x66, 0xE9, 0x5C, 0x6C, 0x6D, 0xAD, 	// 98..9F
	0x37, 0x61, 0x4B, 0xB9, 0xE3, 0xBA, 0xF1, 0xA0, 	// A0..A7
	0x85, 0x83, 0xDA, 0x47, 0xC5, 0xB0, 0x33, 0xFA, 	// A8..AF
	0x96, 0x6F, 0x6E, 0xC2, 0xF6, 0x50, 0xFF, 0x5D, 	// B0..B7
	0xA9, 0x8E, 0x17, 0x1B, 0x97, 0x7D, 0xEC, 0x58, 	// B8..BF
	0xF7, 0x1F, 0xFB, 0x7C, 0x09, 0x0D, 0x7A, 0x67, 	// C0..C7
	0x45, 0x87, 0xDC, 0xE8, 0x4F, 0x1D, 0x4E, 0x04, 	// C8..CF
	0xEB, 0xF8, 0xF3, 0x3E, 0x3D, 0xBD, 0x8A, 0x88, 	// D0..D7
	0xDD, 0xCD, 0x0B, 0x13, 0x98, 0x02, 0x93, 0x80, 	// D8..DF
	0x90, 0xD0, 0x24, 0x34, 0xCB, 0xED, 0xF4, 0xCE, 	// E0..E7
	0x99, 0x10, 0x44, 0x40, 0x92, 0x3A, 0x01, 0x26, 	// E8..EF
	0x12, 0x1A, 0x48, 0x68, 0xF5, 0x81, 0x8B, 0xC7, 	// F0..F7
	0xD6, 0x20, 0x0A, 0x08, 0x00, 0x4C, 0xD7, 0x74	 	// F8..FF
};

const unsigned char l[] = {1, 148, 32, 133, 16, 194, 192, 1, 251, 1, 192, 194, 16, 133, 32, 148};

unsigned int xtime(unsigned int b)    // multiply on x
{
	b = b << 1;
	return b;
}

int getHighest(unsigned int a)
{
	int res = -1;
	for (unsigned int i = a; i > 0; i /= 2)
		res++;
	return res;
}

BitArray XOR(BitArray a, BitArray b)
{
	BitArray res = a;
	for (int i = 0; i < res.getN(); i++)
	{
		res[i] ^= b[i];
	}
	return res;
}

unsigned int MOD(unsigned int a, unsigned int mod)
{
	unsigned int temp = a, res = a;
	int i = 0;
	int h1 = getHighest(res), h2 = 8;
	while (h1 >= h2)
	{
		res ^= (mod << (h1 - h2));
		h1 = getHighest(res);
	}
	return res;
}

unsigned char MULT(unsigned char a, unsigned char b, unsigned int mod)
{
	unsigned int res = 0;
	for (int i = 0; i < 8; i++)
	{
		if (b & (1 << i))
		{
			res ^= (a << i);
		}
	}
	res = MOD(res, mod);
	return (unsigned char)res;
}

unsigned char lin(BitArray a)
{
	unsigned char res = 0;
	const unsigned int mod = 0x1c3;
	for (int i = 0; i < a.getN(); i++)
	{
		res ^= MULT(a[i], l[i], mod);
	}
	return res;
}

BitArray R(BitArray a)
{
	BitArray res = a;
	for (int i = 0; i < res.getN() - 1; i++)
	{
		res[i] = res[i + 1];
	}
	res[res.getN() - 1] = lin(a);
	return res;
}

BitArray invR(BitArray a)
{
	BitArray res = a;
	unsigned char t = a[res.getN() - 1];
	for (int i = res.getN() - 1; i > 0; i--)
	{
		res[i] = res[i - 1];
	}
	BitArray temp = res;
	temp[0] = t;
	res[0] = lin(temp);
	return res;
}

BitArray L(BitArray a)
{
	BitArray res = a;
	for (int i = 0; i < 16; i++)
	{
		res = R(res);
	}
	return res;
}

BitArray invL(BitArray a)
{
	BitArray res = a;
	for (int i = 0; i < 16; i++)
	{
		res = invR(res);
	}
	return res;
}

BitArray S(BitArray a)
{
	BitArray res = a;
	for (int i = 0; i < a.getN(); i++)
	{
		res[i] = pi[a[i]];
	}
	return res;
}

BitArray invS(BitArray a)
{
	BitArray res = a;
	for (int i = 0; i < a.getN(); i++)
	{
		res[i] = invpi[a[i]];
	}
	return res;
}

BitArray getC(int i)
{
	int a = i;
	string str = "";
	for (int j = 0; j < 32; j++)
	{
		str = translate2(a % 16) + str;
		a /= 16;
	}
	BitArray res(str);
	res = L(res);
	return res;
}



BitArray F(BitArray a, BitArray b)
{
	BitArray res = a;
	res = XOR(res, b);
	//cout << "X = " << res.getStr() << endl;
	res = S(res);
	//cout << "SX = " << res.getStr() << endl;
	res = L(res);
	//cout << "LSX = " << res.getStr() << endl;
	return res;
}

BitArray getKey(BitArray keys, int iter)
{
	BitArray h, l;
	BitArray res = keys;
	l.copy(0, 16, keys);
	h.copy(16, 16, keys);
	BitArray c, temp;
	for (int i = 0; i < 8; i++)
	{
		temp = h;
		c = getC(i + 1 + 8*iter);
		h = F(c, h);
		h = XOR(l, h);
		l = temp;
	}
	for (int i = 0; i < 16; i++)
	{
		res[i] = l[i];
		res[i + 16] = h[i];
	}
	return res;
}

BitArray* getRoundKeys(BitArray key)
{
	int count = 10;
	BitArray temp = key;
	BitArray* keys = new BitArray[count];
	for (int i = 0; i < count; i++)
	{
		keys[i].copy(16, 16, temp);
		i++;
		keys[i].copy(0, 16, temp);
		temp = getKey(temp, i / 2);
	}
	return keys;
}

void encrypt(BitArray & data, BitArray* keys)
{
	//cout << "Encrypting:" << endl;
	for (int i = 0; i < 9; i++)
	{
		data = XOR(data, keys[i]);
		data = S(data);
		data = L(data);
		//cout << "round: " << i + 1 << endl;
		//cout << "data: " << data.getStr() << endl;
	}
	data = XOR(data, keys[9]);
}

void decrypt(BitArray & data, BitArray* keys)
{
	//cout << "Decrypting: " << endl;
	for (int i = 0; i < 9; i++)
	{
		data = XOR(data, keys[9 - i]);
		data = invL(data);
		data = invS(data);
		//cout << "round: " << i + 1 << endl;
		//cout << "data: " << data.getStr() << endl;
	}
	data = XOR(data, keys[0]);
}
int main()
{
	BitArray k("8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef");
	BitArray data("1122334455667700ffeeddccbbaa9988");
	BitArray* keys = getRoundKeys(k);
	for (int i = 0; i < 10; i++)
	{
		//cout << "K[" << i + 1 << "] = " << keys[i].getStr() << endl;
	}
	cout << "data =     " << data.getStr() << endl;
	encrypt(data, keys);
	cout << "cipher =   " << data.getStr() << endl;
	decrypt(data, keys);
	cout << "decipher = " << data.getStr() << endl;
	cout << "C = " << getC(3).getStr() << endl;
	return 0;
}