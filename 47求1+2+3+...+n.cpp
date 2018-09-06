#include <cstdio> 

int Sum_Solution(int n) {
    int sum = n;
    n && (sum += Sum_Solution(n - 1));
    return sum;
}


int main() {
	printf("%d", Sum_Solution(4));
}
