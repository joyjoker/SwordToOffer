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
		��ֻ����������2��3��5��������������Ugly Number����
		����6��8���ǳ�������14���ǣ���Ϊ������������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
		*/
		
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> result(index);
        if(index < 7) {  
        	return index; //1, 2, 3, 4, 5, 6 ȫ�ǳ��� 
		}
		result[0] = 1; 
		int t2 = 0, t3 = 0, t5 = 0;
		int i;
		for(i = 1; i < index; i++) {
			result[i] = min(result[t2] * 2, min(result[t3] * 3, result[t5] * 5));
			if(result[i] == result[t2] * 2) {
				t2++;
			}
			if(result[i] == result[t3] * 3) {
				t3++;
			}
			if(result[i] == result[t5] * 5) {
				t5++;
			}
		}
		return result[index - 1];
    }
};

int main() {
	Solution s;
	cout << s.GetUglyNumber_Solution(7);
	return 0;
}

