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
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int length = array.size();
        int plow = 0;
        int phigh = length - 1;
        while(plow < phigh) {
        	int curSum = array[plow] + array[phigh];
        	if(curSum == sum) {
        		result.push_back(array[plow]);
        		result.push_back(array[phigh]);
        		break; // ���������С�� ������ 
			} else if(curSum < sum) { // �������ж�С�� 
				plow++;
			} else {
				phigh--;
			}
		}
		return result; 
    }
};

int main() {
	Solution s;
	vector<int> v = {1, 2, 3, 4, 5, 6};
	vector<int> result = s.FindNumbersWithSum(v, 7);
	
	for(int r : result) {
		cout << r << " ";
	}
	return 0;
}

