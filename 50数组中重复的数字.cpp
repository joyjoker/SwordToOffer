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
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication) {
        if(numbers == NULL || length <= 0) {
        	return false;
		} 
		for(int i = 0; i < length; i++) {
			if(numbers[i] < 0 || numbers[i] > length - 1) {
				return false;
			}
		} 
		for(int i = 0; i < length; i++) {
			while(numbers[i] != i) {
				if(numbers[i] == numbers[numbers[i]]) {
					*duplication = numbers[i];
					cout << *duplication << endl;
					return true;
				}
				swap(numbers[i], numbers[numbers[i]]);
		 	}
		} 
		return false;
    }
};


int main() {
	Solution s;
	int A[] = {2,3,1,0,2,5,3};
	int len = sizeof(A) / sizeof(A[0]); 
	int *duplication = new int;
	cout << s.duplicate(A, 7, duplication) << " ";
	cout << *duplication;
	return 0;
}

