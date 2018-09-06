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
    void Insert(int num)
    {
        // �����������Ϊż�����������С��
        if(((max.size() + min.size()) & 1) == 0){
            // ������������С����������������������ֲ�������
            // ���������е��������ֲ��뵽��С��
            if(max.size() > 0 && num < max[0]){
                // �������ݲ��뵽��������
                max.push_back(num);
                // ��������
                push_heap(max.begin(), max.end(), less<int>());
                // �ó������е������
                num = max[0];
                // ɾ�����ѵ�ջ��Ԫ��
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            // �����ݲ�����С������
            min.push_back(num);
            // ������С��
            push_heap(min.begin(), min.end(), greater<int>());
        }
        // ��������Ϊ���������������
        else{
            if(min.size() > 0 && num > min[0]){
                // �����ݲ�����С��
                min.push_back(num);
                // ������С��
                push_heap(min.begin(), min.end(), greater<int>());
                // �ó���С�ѵ���С��
                num = min[0];
                // ɾ����С�ѵ�ջ��Ԫ��
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // �����ݲ�������
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }
    double GetMedian()
    {
        // ͳ�����ݴ�С
        int size = min.size() + max.size();
        if(size == 0){
            return 0;
        }
        // �������Ϊż��
        if((size & 1) == 0){
            return (min[0] + max[0]) / 2.0;
        }
        // ����
        else{
            return min[0];
        }
    }
private:
    // ʹ��vector�������Ѻ���С��,min����С������,max����������
    vector<int> min;
    vector<int> max;
};

int main() {

	return 0;
}

