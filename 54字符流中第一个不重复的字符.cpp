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

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch) {
         s += ch;
		 count[ch]++; 
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
    	for(int i = 0; i < s.length(); i++) {
    		if(count[s[i]] == 1) {
    			return s[i];
			}
		}
		return '#'; 
    }
private:
	string s;
	int count[128] = {0}; // ascii ±í¹²128¸ö×Ö·û 
};

int main() {
	Solution s;
	s.Insert('g');
	s.Insert('o');
	s.Insert('o');
	s.Insert('g');
	s.Insert('r');
	s.Insert('e');
	cout << s.FirstAppearingOnce();
	
	return 0;
}

