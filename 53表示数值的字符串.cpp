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
    bool isNumeric(char* string) {
        // ��� ������ С���� eE �Ƿ���ֹ� 
		bool sign = false, decimal = false, hasE = false;
		for(int i = 0; i < strlen(string); i++) {
			if(string[i] == 'e' || string[i] == 'E') {
				if(i == strlen(string) - 1) {
					return false; // e ����һ��Ҫ������ 
				}	
				if(hasE) {
					return false; // ���ܳ�������e 
				} 
				hasE = true;
			} else if(string[i] == '+' || string[i] =='-') {
				// �ڶ��γ��� + - ���������e ֮��
				if(sign && string[i - 1] != 'e' && string[i - 1] != 'E') {
					return false;
				}
				// ��һ�γ��� + - �Ҳ����ڿ�ͷ���������e ֮��
				if(!sign && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E') {
					return false;
				}
				sign = true;
			} else if(string[i] == '.') {
				// e ���治�ܽ�С���� С���㲻�ܳ�������
				if(hasE || decimal) {
					return false;
				} 
				decimal = true;
			} else if(string[i] < '0' || string[i] > '9') {
				// �ַ��Ƿ� 
				return false;
			}
		} 
		return true; 
    }

};

int main() {
	Solution s;
	cout << s.isNumeric("12e+5.4");
	return 0;
}

