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
		����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
		*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		return bst(sequence, 0, sequence.size() - 1);
    }
private:
	bool bst(vector<int> seq, int begin, int end) {
		
		if(seq.empty() || begin > end) {
			return false;
		}
		//������� ���ڵ�Ϊ����ĩβԪ�� 
		int root = seq[end];
		
		//�������ڵ�ȫ��С�ڸ��ڵ� 
		int i = begin;
		for( ; i < end; i++) { //�ҵ����������ֽ�� 
			if(seq[i] > root) {
				break;
			}
		} 
		//�������ڵ�ȫ�����ڸ��ڵ� 
		for(int j = i; j < end; j++) { // �ж��Ƿ���϶��������� 
			if(seq[j] < root) {
				return false;
			}
		}
		
		//�ж��������Ƿ���϶���������
		bool left = true;
		if(i > begin) { //��֤�������� 
		 	left = bst(seq, 0, i - 1); 
		}
		//�ж��������Ƿ���϶��������� 
		bool right = true;
		if(i > end) { //��֤�������� 
		 	right = bst(seq, i, end - 1); 
		}
		return left && right;
	}
};


int main() {
	vector<int> v = {5, 7, 6, 9, 11, 10, 8};
	Solution s;
	cout << s.VerifySquenceOfBST(v);
	return 0;
}

