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
		����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
		�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
		�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
		*/
class Solution {
	public:
		vector<int> printMatrix(vector<vector<int>> matrix) {
			int rows = matrix.size(); // ���� 
			int cols = matrix[0].size(); // ����
			
			vector<int> result; //�������
			if(rows == 0 && cols == 0) {
				return result;
			}
			int left = 0, right = cols- 1, top = 0, bottom = rows - 1;
			while(left <= right && top <= bottom) {
				// ������
				for(int i = left; i <= right; i++) {
					result.push_back(matrix[top][i]);
				} 
				// ���ϵ��� 
				for(int i = top + 1; i <= bottom; i++) {
					result.push_back(matrix[i][right]);
				} 
				// ���ҵ��� 
				if(top != bottom) { // ���ֻ��һ�� 
					for(int i = right - 1; i >= left; i--) {
						result.push_back(matrix[bottom][i]);
					} 
				}
				
				// ���µ���
				if(left != right) { // ���ֻ��һ�� 
					for(int i = bottom - 1; i > top; i--) { //û�е��� 
						result.push_back(matrix[i][left]);
					} 
				} 
				
				left++, right--, top++, bottom--; 
			}
			
			return result; 
		}
};

int main() {
    vector<vector<int>> matrix = {{1,   2,  3,  4}, 
								  {5,   6,  7,  8},
								  {9,  10, 11, 12}, 
								  {13, 14, 15, 16}};
	vector<vector<int>> matrix1 = {{1}, 
								   {2},
								   {3}, 
								   {4}, 
								   {5}};
								  
	Solution s;
	vector<int> result = s.printMatrix(matrix);
	for(int v : result) {
		cout << v << " ";
	}
	return 0;
}

