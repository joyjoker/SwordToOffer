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
	题目描述
	输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
	输入描述:
	输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
	
	*/
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) {
        	return result;
		}
		permutation(str, 0);
		return result;
    }
    
private:
	void permutation(string str, int begin) {
		if(begin == str.length()) {
			result.push_back(str);
		}
		for(int i = begin; i < str.length(); i++) {
			if(i != begin && str[i] == str[begin]) {
				continue;
			}
			swap(str[i], str[begin]);
			permutation(str, begin + 1);
		}
	}
	vector<string> result; 
};

int main() {
	Solution s;
	string str = "cba";
	vector<string> result = s.Permutation(str);
	for(string st : result) {
		cout << st << endl;
	}
	return 0;
}

