#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/
/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。	
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int length = data.size();
		if(length < 2) {
			return;
		} 
		// 对原始数据每个元素求异或
		int resultExclusiveOR = 0;
		for(int i = 0; i < length; i++) {
			resultExclusiveOR ^= data[i];
		} 
		unsigned int firstBit1 = FindFirstBitIs1(resultExclusiveOR);
		
		*num1 = *num2 = 0;
		for(int i = 0; i < length; i++) {
			if(IsBit1(data[i], firstBit1)) {
				*num1 ^= data[i];
			} else {
				*num2 ^= data[i];
			}
		}
    }
private:
	// 找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2。
	unsigned int FindFirstBitIs1(int num) {
		unsigned int indexBit = 0;
		// 只判断一个字节
		while((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {
			num = num >> 1;
			indexBit++;
		} 
		return indexBit;
	}
	// 判断第indexBit位是否为1 
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return num & 1; // 1的其他位都为 0 
	} 
};

int main() {
	Solution s;
	vector<int> v = {4,3,3,2,2,5};
	int *num1 = new int, *num2 = new int;
	s.FindNumsAppearOnce(v, num1, num2);
	cout << *num1 << " " << *num2;
	return 0;
}

