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
    int InversePairs(vector<int> data) {
    	if(data.size() <= 1) {
    		return 0;
		}
		//����ĸ�������
		vector<int> copy;
		for(int i = 0; i < data.size(); i++) {
			copy.push_back(data[i]);
		} 
		int begin = 0; 
		int end = data.size() - 1;
        return InverserPairsCore(data, copy, begin, end) % 1000000007; 
    }
    long InverserPairsCore(vector<int> &data, vector<int> &copy, int begin, int end) {
    	// ���ָ����ͬλ�� 
    	if(begin == end) {
    		return 0; // û������ 
		}
		int mid = (begin + end) / 2; // �е�
		// ʹdata �������� ��������������Ե���Ŀ
		long left = InverserPairsCore(copy, data, begin, mid);
		// ʹdata �Ұ������ �������Ұ������Ե���Ŀ
		long right = InverserPairsCore(copy, data, mid + 1, end);
		
		int i = mid; // i��ʼ��Ϊǰ������һ�����ֵ��±�
        int j = end; // j��ʼ��Ϊ�������һ�����ֵ��±�
        int indexcopy = end; // �������鸴�Ƶ���������һ�����ֵ��±�
        long count = 0; // ����������Եĸ�����ע������
		
		while(i >= begin && j >= mid + 1) {
			if(data[i] > data[j]) {
				copy[indexcopy--] = data[i--];
				count += j - mid; //ע���� 
			} else {
				copy[indexcopy--] = data[j--];
			}
		}  
		while(i >= begin) {
			copy[indexcopy--] = data[i--];
		}
		while(j >= mid + 1) {
			copy[indexcopy--] = data[j--];
		}
		return left + right + count;
	} 
};


int main() {
	Solution s;
	vector<int> data = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
	cout << s.InversePairs(data);
	return 0;
}

