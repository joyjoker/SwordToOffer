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
	// 解法一 ：先排个序 如果有超过一半的 一定是数组中间那个数字 
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
	思路二：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
	在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，
	则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
	*/
	 int MoreThanHalfNum_Solution1(vector<int> numbers) {
	 	if(numbers.empty()) {
	 		return 0;
		 }
		 // 先初始化
		 int result = numbers[0];
		 int count = 1; //numbers[0] 初现一次 
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
		 // 因为count 不可能小于零 检测最后的数字是否是超过一半的数字
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

