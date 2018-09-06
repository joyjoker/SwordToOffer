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
		���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
		������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
		*/
		
		/*
		�����Ȱ�2x8�ĸ��Ƿ�����Ϊf(8)���õ�һ��1x2С���󸲸Ǵ���ε������ʱ������ѡ�����ŷŻ��ߺ��ŷš�
		�����ŷŵ�ʱ���ұ߻�ʣ��2x7��������������µĸ��Ƿ�����Ϊf(7)��
		���������Ǻ��ŷŵ��������1x2��С���κ��ŷ������Ͻǵ�ʱ�����½Ǻͺ��ŷ�һ��1x2��С���Σ�
		�����ұ߻�ʣ��2x6��������������µĸ��Ƿ�����Ϊf(6)�����f(8)=f(7)+f(6)����ʱ���ǿ��Կ���������Ȼ��쳲��������С�
		*/

class Solution {
public:
    int rectCover(int number) {
		if(number <= 2) {
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
	cout << s.rectCover(0) << endl;
	cout << s.rectCover(1) << endl;
	cout << s.rectCover(2) << endl;
	cout << s.rectCover(3) << endl;
	cout << s.rectCover(4) << endl;
	return 0;
}

