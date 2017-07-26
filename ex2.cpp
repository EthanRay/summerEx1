#include"stdfx.h"

/*将整数A转换为B */
int bitSwapRequired(int a, int b)
{
	int cnt = 0;
	for (int c = a^b; c != 0; c &= c - 1)
	{
		++cnt;
	}
	return cnt;
}

/*二进制中有多少个1*/
int countOnes(int num)
{
	int cnt = 0;
	for (; num; num &= num - 1)
	{
		++cnt;
	}
	return cnt;
}

/*
二进制表示
*/
string binaryRepresentation(string n)
{
	int int_part = stoi(n.substr(0, n.find('.')));
	double dec_part = stod(n.substr(n.find('.')));

	string int_str = "";
	string dec_str = "";
	
	if (int_part == 0)
	{
		int_str.push_back('0');
	}
	while (int_part > 0)
	{
		int c = int_part % 2;
		int_str.push_back('0' + c);
		int_part = int_part >> 1;
	}
	reverse(int_str.begin(), int_str.end());

	while (dec_part > 0.0)
	{
		if (dec_str.length() > 32)
		{
			return "ERROR";
		}
		double remain = dec_part * 2;
		if (remain >= 1.0)
		{
			dec_str.push_back('1');
			dec_part = remain - 1.0;
		}
		else{
			dec_str.push_back('0');
			dec_part = remain;
		}
	}
	return dec_str.length() > 0 ? int_str + "." + dec_str : int_str;
}

/*??更新二进制位*/
int updateBits(int n, int m, int i, int j)
{
	int right_part = n&((1 << i) - 1);
	int left_part = j >= 31 ? 0 : (n >> (j + 1)) << (j + 1);
	return left_part | (m << i) | right_part;
}

/*O(1)时间检测2的幂次*/
bool checkPowerOf2(int n)
{
	return n > 0 && (n&(n - 1)) == 0;
}
