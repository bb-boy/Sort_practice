#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


/*暴力匹配，数组[0]中存储的是父串和子串的长度，返回的是子串在父串中开始的位置*/
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
//	//printf("字符串是%s", str1[0]);
//	int a;
//	a =Brute_Match(str, str1);
//	printf("子串是从%d开始\n", a);
//
//}