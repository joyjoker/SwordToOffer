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
		����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
		*/
		/*
		
		���һ��������Ϊ0����ô�������������һλ��1��������ǰ����������1����ôԭ�������������ұߵ�1�ͻ��Ϊ0��
		ԭ����1��������е�0������1(������ұߵ�1���滹��0�Ļ�)����������λ�������ܵ�Ӱ�졣

		�ٸ����ӣ�һ����������1100�����ұ��������λ�Ǵ������ұߵ�һ��1����ȥ1�󣬵���λ���0��
		���������λ0�����1����ǰ���1���ֲ��䣬��˵õ��Ľ����1011.���Ƿ��ּ�1�Ľ���ǰ����ұߵ�һ��1��ʼ������λ��ȡ���ˡ�
		���ʱ����������ٰ�ԭ���������ͼ�ȥ1֮��Ľ���������㣬��ԭ���������ұ�һ��1��һλ��ʼ����λ������0��
		��1100&1011=1000.Ҳ����˵����һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1���0.
		��ôһ�������Ķ������ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
		
		*/
		
class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;
        while(n) {
        	count++;
        	n = n&(n - 1);
		}
		return count;
    }
};

int main() {
	Solution s;
	cout << s.NumberOf1(-3);
	return 0;
}

