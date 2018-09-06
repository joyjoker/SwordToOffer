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
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1) {
        	return -1;
		}
		int last = 0;
		for(int i = 2; i <= n; i++) { // i = 1 或 i = 2 结果是一样的 
			last = (last + m) % i;
		} 
		return last;
    }
};

int main() {
	Solution s;
	cout << s.LastRemaining_Solution(5, 3); //3
	return 0;
}

