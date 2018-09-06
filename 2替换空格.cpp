#include<cstdio>

//��ǰ������� �Ӻ���ǰ���� 
void replaceSpace(char* str, int length) {
	if(str == NULL && length <= 0) {
		return ;
	}
	int original_length = 0;//ԭʼ���� 
	int number_blank = 0; //�ո���
	int i = 0;
	//���� 
	while(str[i] != '\0') { //++�ŵ����� 
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
	//index_new ��ǰ�� ��������ո� ���滻 ����ִ�и��Ʋ���
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
