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
		我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
		请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
		*/
		
		/*
		我们先把2x8的覆盖方法记为f(8)。用第一个1x2小矩阵覆盖大矩形的最左边时有两个选择，竖着放或者横着放。
		当竖着放的时候，右边还剩下2x7的区域，这种情况下的覆盖方法记为f(7)。
		接下来考虑横着放的情况。当1x2的小矩形横着放在左上角的时候，左下角和横着放一个1x2的小矩形，
		而在右边还剩下2x6的区域，这种情况下的覆盖方法记为f(6)。因此f(8)=f(7)+f(6)。此时我们可以看出，这仍然是斐波那契数列。
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

