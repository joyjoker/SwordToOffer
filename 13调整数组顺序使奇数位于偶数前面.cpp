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
	����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
	���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
	*/
class Solution {
public:
	//˫�˶���ʵ�� 
    deque<int> reOrderArray(vector<int> &array) {
        deque<int> result;
        int num = array.size();
        for(int i = 0; i < num; i++) {
        	if(array[num - i - 1] % 2 == 1) {
        		result.push_back(array[i]);
			}
			if(array[i] % 2 == 0) {
				result.push_front(array[num - i - 1]);
			}
		}
		return result; 	//array.assign(result.begin(),result.end()); �޷���ֵ��� 
    }
    
    //ţ����ʵ�� ����ð�� �Ӻ���ǰ ��ż���� 
    void reOrderArray1(vector<int> &array) {
    	for(int i = 0; i < array.size(); i++) {
    		for(int j = array.size() - 1; j > i; j--) {
    			if(array[j] % 2 == 1 && array[j - 1] % 2 == 0) {
    				swap(array[j], array[j - 1]);
				}
			}
		} 
	}
    	
};

int main() {
	//˫�˶��м�� 
	vector<int> v = {1, 2, 3, 4, 5, 6};
	Solution s;
	deque<int> de = s.reOrderArray(v);
	for(int var : de) {
		cout << var << " " ;
	}
	cout << endl;
	//ţ�������
	vector<int> v1 = {1, 2, 3, 4, 5, 6};
	Solution s1;
	s1.reOrderArray1(v1);
	for(int var : v1) {
		cout << var << " " ;
	}
	return 0;
}

