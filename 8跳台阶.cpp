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
�������ǿ�����򵥵���������ֻ��1��̨�ף���ô��Ȼֻһ�������������2��̨�ף��Ǿ�������������
һ���Ƿ���������ÿ����1������һ����һ����2����

���ţ�����������һ����������ǰ�n��̨��ʱ������������n�ĺ�������Ϊf(n)����n>2ʱ����һ������ʱ��������ֲ�ͬ��ѡ��
һ�ǵ�һ��ֻ��1������ʱ������Ŀ���ں���ʣ�µ�n-1��̨�׵�������Ŀ����Ϊf(n-1)������һ��ѡ������һ����2����
��ʱ������Ŀ���ں���ʣ�µ�n-2��̨�׵�������Ŀ����Ϊf(n-2)�����n��̨�׵Ĳ�ͬ����������f(n)=f(n-1)+f(n-2)��
������������ǲ��ѿ�����ʵ���Ͼ���쳲����������ˡ�
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0) {
        	return 0;
		} else if(number < 3) {
			return number;
		}
		int first = 1, second = 2, third = 0;
		for(int i = 3; i <= number; i++) {
			third = first + second;
			first = second;
			second = third;
		}
		return third;	
    }
};

int main() {
	Solution s;
	cout << s.jumpFloor(0) << endl;
	cout << s.jumpFloor(1) << endl;
	cout << s.jumpFloor(2) << endl;
	cout << s.jumpFloor(3) << endl;
	cout << s.jumpFloor(4) << endl;
	return 0;
}

