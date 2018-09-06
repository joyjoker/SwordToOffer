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
    int StrToInt(string str) {
    	bool isValid = false;
        // �Ƿ�����
		if(str.empty()) {
			isValid = true;
			return 0;
		} 
		//ָ���ַ������ָ�� 
		const char* cstr = str.c_str(); 
		// �Ƿ�Ϊ����
		bool isMinus = false;
		// ����ǰ��Ŀհ��ַ�
		while(*cstr == ' ') {
			cstr++;
		} 
		if(*cstr == '+') {
			cstr++;
		} else if(*cstr == '-') {
			cstr++;
			isMinus = true;
		}
		//���ֻ�����˿հ��ַ�������λ������ʲô��û���룬ҲΪ�Ƿ�����
		if(*cstr == '\0') {
			isValid = true;
			return 0;
		}
		// �������������Ϸ���ת��Ϊ����
		long num = 0; // ��� 
		while(*cstr != '\0') {
			// ���벻�� 0 ~ 9 �Ƿ�
			if(*cstr < '0' || *cstr > '9') {
				isValid = true;
				return 0;
			}
			// �Բ���������λ�ĺϷ��ַ�����ת��
			num = 10 * num + (*cstr - '0'); 
			cstr++;
		} 
		// ȷ������
		num = isMinus ? (-1 * num) : num;
		// �ж��Ƿ����
		if(num > 0x7fffffff || num < (signed int)0x80000000) {
			isValid = true;
			return 0;
		} 
		return (int)num;
    }
};


int main() {
	string str = "-123";
    Solution s;
    cout << s.StrToInt(str);
    return 0;
}

