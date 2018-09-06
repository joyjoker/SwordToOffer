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
    int jumpFloorII(int number) {
		if(number <= 0) {
			return 0;
		}
		int total = 1;
		for(int i = 1; i < number; i++) {
			total *= 2;
		}
		return total;
    }
};


int main() {
	Solution s;
	cout << s.jumpFloorII(0) << endl;
	cout << s.jumpFloorII(1) << endl;
	cout << s.jumpFloorII(2) << endl;
	cout << s.jumpFloorII(3) << endl;
	cout << s.jumpFloorII(4) << endl;
	return 0;
}

