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
	// 堆排序 
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        int length = input.size();
		if(length <= 0 || k <= 0) {
			return result;
		} 
		
		for(int i = 0; i < length; i++) {
			if(result.size() < k) {
				result.push_back(input[i]);
			} else {
				//建立堆 
				for(int j = k / 2; j >= 0; j--) {
					HeapAdjust(result, j, k);
				}
				for(int j = k - 1; j > 0; j--) {
					swap(result[0], result[j]);
					HeapAdjust(result, 0, j);
				} 
				if(result[k - 1] > input[i]) {
					result[k - 1] = input[i];
				}	
			}
		}
		return result;
    }
    
    /* 2. 暴力破解
	vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
        vector<int> result;
		if(input.empty() || input.size() < k) {
        	return result;
		} 
		sort(input.begin(), input.end());
		for(int i = 0; i < k; i++) {
			result.push_back(input[i]);
		} 
		return result;
    } */
private:
	void HeapAdjust(vector<int> &input, int parent, int length) {
		int temp = input[parent];
		int child = 2 * parent + 1;
		while(child < length) {
			if(child + 1 < length && input[child] < input[child + 1]) {
				child++;
			}
			if(temp > input[child]) {
			    break; 
			} 
			
			input[parent] = input[child];
			parent = child;
			child = 2 * parent + 1;
		} 
		input[parent] = temp;
	}
};

int main() {
	Solution s;
	vector<int> input = {7, 6, 5, 4, 3, 2, 1};
	vector<int> result;
	result = s.GetLeastNumbers_Solution(input, 4);
	for(int v : result) {
		cout << v << " "; 
	} 
	return 0;
}

