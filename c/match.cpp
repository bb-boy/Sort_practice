#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


/*����ƥ�䣬����[0]�д洢���Ǹ������Ӵ��ĳ��ȣ����ص����Ӵ��ڸ����п�ʼ��λ��*/
int Brute_Match(const char* parentStr,  const char* childStr) {
	char p[100], c[100];
	p[0] = strlen(parentStr);
	c[0] = strlen(childStr);
	strcpy(p + 1, parentStr);
	strcpy(c + 1, childStr);
	int i = 1, j = 1;
	while (j<=c[0]) {
		if (p[i] == c[j]) {
			i++, j++;
		}
		else 
			i = i - j + 2,j = 1;
	}
	return i-j+1;

}

void get_Next(const char* str) {

}


//int main() {
//	const char* str =  "abcdacdde" ;
//	const char* str1 =  "de" ;
//	//printf("�ַ�����%s", str1[0]);
//	int a;
//	a =Brute_Match(str, str1);
//	printf("�Ӵ��Ǵ�%d��ʼ\n", a);
//
//}