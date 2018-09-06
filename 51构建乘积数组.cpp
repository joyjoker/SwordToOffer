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
    vector<int> multiply(const vector<int>& A) {
    	vector<int> B(A.size());
    	if(A.empty()) {
    		return B;
		}
		B[0] = 1;
		for(int i = 1; i < A.size(); i++) {
			B[i] = B[i - 1] * A[i - 1];
		}
		int temp = 1;
		for(int i = A.size() - 2; i >= 0; i--) {
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
    }
};

int main() {
	Solution s;
	vector<int> A = {1,2,3,4,5};
	vector<int>B;
	B = s.multiply(A);
	for(int v : B) {
		cout << v << " "; 
	}
	return 0;
}

