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
		�����趨������λ�ã���n���зָ��Ϊ�����֣���λn/i����λn%i
		��i��ʾ��λ���Ұ�λ��Ӧ����>=2,��n=31456,i=100����a=314,b=56����ʱ��λΪ1�Ĵ�����a/10+1=32�������λ0~31����
			ÿһ�ζ�����100�������ĵ㣬������(a/10+1)*100����İ�λΪ1
		��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ1����n=31156,i=100����a=311,b=56����ʱ��λ��Ӧ�ľ���1������a/10(�����λ0-30)���ǰ���100�������㣬
			�������λΪ31����a=311��������ֻ��Ӧ�ֲ���00~56����b+1�Σ����е���������У�a/10*100��+(b+1)����Щ���λ��ӦΪ1
		��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ0,��n=31056,i=100����a=310,b=56����ʱ��λΪ1�Ĵ�����a/10=31�������λ0~30��
		�ۺ������������������λ��Ӧ0��>=2ʱ����(a+8)/10�ΰ�������100���㣬���е���λΪ1(a%10==1)����Ҫ���Ӿֲ���b+1
		֮���Բ�8������Ϊ����λΪ0����a/10==(a+8)/10������λ>=2����8�������λλ��Ч����ͬ��(a/10+1)
		*/ 
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
    	int count = 0;
    	for(int i = 1; i <= n; i *= 10) {
    		int a = n / i;
    		int b = n % i;
    		count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
		}
		return count;
    }
};

int main() {
	Solution s;
	cout << s.NumberOf1Between1AndN_Solution(10);
	return 0;
}

