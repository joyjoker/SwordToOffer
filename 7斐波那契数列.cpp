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

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) {
        	return 0;
		}
		if(n == 1) {
			return 1;
		}
		int first = 0, second = 1, third = 0;
		for(int i = 2; i <= n; i++) {
			third = first + second;
			first = second;
			second = third;
		}
		return third;
    }
};

int main() {
	Solution s;
	cout << s.Fibonacci(0) << endl;
	cout << s.Fibonacci(1) << endl;
	cout << s.Fibonacci(2) << endl;
	cout << s.Fibonacci(3) << endl;
	cout << s.Fibonacci(4) << endl;
	return 0;
}

