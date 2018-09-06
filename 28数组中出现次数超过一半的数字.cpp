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
	// �ⷨһ �����Ÿ��� ����г���һ��� һ���������м��Ǹ����� 
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.size() == 0) {
    		return 0;
		} 
		sort(numbers.begin(), numbers.end());
		int middle = numbers[numbers.size() / 2];
		int count = 0;
		for(int i = 0; i < numbers.size(); i++) {
			if(numbers[i] == middle) {
				count++;
			}
		} 
		if(count > numbers.size() / 2) {
			return middle;
		} else {
			return 0;
		}
    }
    /*
	˼·��������з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ
	�ڱ�������ʱ��������ֵ��һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ��
	�������1�����������1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�
	*/
	 int MoreThanHalfNum_Solution1(vector<int> numbers) {
	 	if(numbers.empty()) {
	 		return 0;
		 }
		 // �ȳ�ʼ��
		 int result = numbers[0];
		 int count = 1; //numbers[0] ����һ�� 
		 for(int i = 1; i < numbers.size(); i++) {
		 	if(result == numbers[i]) {
		 		count++;
			 } else {
			 	count--;
			 	if(count == 0) {
			 		result = numbers[i];
			 		count++;
				 }
			 }
		 }
		 // ��Ϊcount ������С���� ������������Ƿ��ǳ���һ�������
		 count = 0; 
		 for(int i = 0; i < numbers.size(); i++) {
		 	if(result == numbers[i]) {
		 		count++;
			 }
		 } 
		 return count > numbers.size() / 2 ? result : 0;
	 }
};

int main() {
	vector<int> numbers = {1, 2, 2, 2, 2, 2, 2, 3, 4, 5, 6};
	Solution s;
	cout << s.MoreThanHalfNum_Solution1(numbers);
	return 0;
}

