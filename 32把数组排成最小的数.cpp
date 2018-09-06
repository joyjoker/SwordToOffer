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
		����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
		������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
		*/
		/*
			��ab > ba �� a ���� b��
			��ab < ba �� a С�� b��
			��ab = ba �� a ���� b��
		*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size() == 0) {
        	return "";
		}
		sort(numbers.begin(), numbers.end(), cmp);
		string result;
		for(int i = 0; i < numbers.size(); i++) {
			result += to_string(numbers[i]);
		}
		return result;
    }
private:
	static bool cmp(int a, int b) {
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};

int main() {
	Solution s;
	vector<int> numbers = {3, 32, 321};
	cout << s.PrintMinNumber(numbers);
	return 0;
}

