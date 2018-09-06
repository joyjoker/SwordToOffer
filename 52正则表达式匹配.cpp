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
	    bool match(char* str, char* pattern) {
			if(str == NULL || pattern == NULL) {
				return false;
			}
			return matchCore(str, pattern);
	    }
	    bool matchCore(char *str, char* pattern) {
	    	if(*str == '\0' && *pattern == '\0') { // ������ֹ���� 
	    		return true;
			} 
			if(*str != '\0' && *pattern == '\0') { // ������ֹ���� 
	    		return false;
			} 
			
			// ��ģʽ�� ��Ҫ������һ���ַ�
			// ���ģʽ������һ���ַ���'*'�������״̬����ƥ��
	        if(*(pattern + 1) == '*'){
	            // ����ַ�����ģʽ����ȣ�����ģʽ����'.'�������ַ���û�е���β�������ƥ��
	            if(*str == *pattern || (*pattern == '.' && *str != '\0')){
	                // ������һ��״̬������ƥ�䵽��һ��
	                return matchCore(str + 1, pattern + 2) ||
	                    // ���ֵ�ǰ״̬�����Ǽ��������'*'ȥƥ��
	                    matchCore(str + 1, pattern) ||
	                    // �������'*'
	                    matchCore(str, pattern + 2);
	            }
	            // ����ַ�����ģʽ������ȣ���������ǰģʽ�����ַ���'*'��������һ�ֵ�ƥ��
	            else{
	                // �������'*'
	                return matchCore(str, pattern + 2);
	            }
	        }
	        // ����ַ�����ģʽ����ȣ�����ģʽ����'.'�������ַ���û�е���β�������ƥ��
	        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
	            return matchCore(str + 1, pattern + 1);
	        }
	        	return false;
		}
};

int main() {
	Solution s;
	char str[] = " ";
	char pattern[] = " ";
	cout << s.match(str, pattern);
	return 0;
}

