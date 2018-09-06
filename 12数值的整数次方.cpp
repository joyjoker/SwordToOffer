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
		给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
		*/ 
		//分为exponent 大于零 等于零 小于零 三种情况 
class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent > 0) {
    		if(exponent == 1) {
    			return base;
			}
			if(exponent % 2 == 0) {
				return Power(base, exponent / 2) * Power(base, exponent / 2);
			} else {
				return Power(base, exponent / 2) * Power(base, exponent / 2 + 1);
			} 
		} else if(exponent == 0) {
			return 1;
		} else {
			return 1 / Power(base, 0 - exponent);
		}
    }
};

int main() {
	Solution s;
	cout << s.Power(3.0, 3);
	return 0;
}

