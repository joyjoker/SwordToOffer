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
��Ŀ����
һ�����������������������֮�⣬���������ֶ�������ż���Ρ���д�����ҳ�������ֻ����һ�ε����֡�
Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��	
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int length = data.size();
		if(length < 2) {
			return;
		} 
		// ��ԭʼ����ÿ��Ԫ�������
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
	// �ҵ���������num��һ��Ϊ1��λ��������0010����һ��Ϊ1��λ����2��
	unsigned int FindFirstBitIs1(int num) {
		unsigned int indexBit = 0;
		// ֻ�ж�һ���ֽ�
		while((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {
			num = num >> 1;
			indexBit++;
		} 
		return indexBit;
	}
	// �жϵ�indexBitλ�Ƿ�Ϊ1 
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return num & 1; // 1������λ��Ϊ 0 
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

