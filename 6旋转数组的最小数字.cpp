#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(size == 0) {
        	return 0;
		}
		int left = 0;
		int right = size - 1;
		int mid = 0;
		while(rotateArray[left] >= rotateArray[right]) {
			if(right - left == 1) {
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;
			//特殊情况：如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
			if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[right]) {
				return minInOrder(rotateArray, left, right);
			}
			
			if(rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}else {
				right = mid;
			}
		}
		return rotateArray[mid];
    }
private:
	int minInOrder(vector<int> &num, int left, int right) {
		int result = num[left];
		for(int i = left + 1; i < num.size(); i++) {
			if(result < num[i]){
				result = num[i];
			}
		}
		return result;
	}
};


int main() {
	vector<int> v = {3, 4, 5, 2, 2}; 
	Solution s;
	cout << s.minNumberInRotateArray(v) << endl;
	return 0;
}
