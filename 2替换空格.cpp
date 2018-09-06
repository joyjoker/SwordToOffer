#include<cstdio>

//从前往后遍历 从后往前插入 
void replaceSpace(char* str, int length) {
	if(str == NULL && length <= 0) {
		return ;
	}
	int original_length = 0;//原始长度 
	int number_blank = 0; //空格数
	int i = 0;
	//遍历 
	while(str[i] != '\0') { //++放到下面 
		if(str[i++] == ' ') {
			original_length++;
			number_blank++;
		} else {
			original_length++;
		}
	} 
	int new_length = original_length + 2 * number_blank;
	int index_new = new_length;
	int index_old = original_length;
	//index_new 向前走 如果遇到空格 则替换 否则执行复制操作
	while(index_old >= 0 && index_new >= index_old) {
		if(str[index_old] == ' ') {
			str[index_new--] = '0';
			str[index_new--] = '2';
			str[index_new--] = '%';
		} else {
			str[index_new--] = str[index_old];
		}
		index_old--;
	} 
}

int main() {
	char a[20] = "hello world ";
	replaceSpace(a, 12);
	printf("%s", a);
	return 0;
}
