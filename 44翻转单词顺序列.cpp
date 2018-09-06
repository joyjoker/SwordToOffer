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
    string ReverseSentence(string str) {
        string result = str;
        if(str.length() == 0) {
        	return "";
		}
		int mark = 0;
		result += " ";
		for(int i = 0; i < result.length(); i++) {
			if(result[i] == ' ') {
				ReverseString(result, mark, i - 1);
				mark = i + 1;
			}
		}
		result = result.substr(0, result.size() - 1);
		ReverseString(result, 0, result.length() - 1);
		return result = result;
    }
private:
	void ReverseString(string &str, int begin, int end) {
		while(begin < end) {
			swap(str[begin++], str[end--]);
		}
	}
};

int main() {
	Solution s;
	cout << s.ReverseSentence("I am a student."); //student. a am I
	return 0;
}

