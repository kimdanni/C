#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int mystrlen(char* str); // 문자열의 길이 반환
void mystrcpy(char* sour, char* dest); // 앞 문자열을 뒷 문자열에 복사
void mystrcat(char* str1, char* str2); // 앞 문자열 뒤에 뒷 문자열 붙이기
void mystrreverse(char* str); // 문자열을 뒤집음

int main(void)
{
	int input = 0;
	int len = 0;
	char str1[100] = { 0 };
	char str2[100] = { 0 };

	do {
		printf("문자열 관련 프로그램입니다. 기능을 선택해주세요.\n");
		printf("▶ [ 1. 문자열 길이 측정 ] [ 2. 문자열 복사 ] [ 3. 문자열 붙이기 ] [ 4. 문자열 뒤집기 ] [ 0. 프로그램 종료 ]\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("문자열을 입력하세요.\n");
			scanf_s("%s", str1, 99);
			printf("%s 의 길이는 %d 입니다.\n", str1, mystrlen(str1));
			break;
		case 2:
			printf("문자열을 입력하세요.\n");
			scanf_s("%s", str1, 99);
			mystrcpy(str1, str2);
			printf("str1 = %s, str2 = %s\n", str1, str2);
			break;
		case 3:
			printf("첫번째 문자열을 입력하세요.\n");
			scanf_s("%s", str1, 99);
			printf("두번째 문자열을 입력하세요.\n");
			scanf_s("%s", str2, 99);
			mystrcat(str1, str2);
			printf("str1 = %s\n", str1);
			break;
		case 4:
			printf("문자열을 입력하세요.\n");
			scanf_s("%s", str1, 99);
			mystrreverse(str1);
			printf("str1 = %s\n", str1);
			break;
		default:
			printf("프로그램을 종료합니다.\n");
			break;
		}
		printf("계속하려면 Enter를 누르세요.");
		_getch();
		system("cls");
	} while (input != 0);
}

// 문자열의 길이 반환
int mystrlen(char* str)
{
	int i = 0;
	while (str[i] != NULL) {
		i++;
	}
	return i;
}

// 앞 문자열을 뒷 문자열에 복사
void mystrcpy(char* sour, char* dest)
{
	char *c_dest = dest;
	while (*sour)
	{
		*dest++ = *sour++;
	}
	*dest = NULL;
	return c_dest;
}

// 앞 문자열 뒤에 뒷 문자열 붙이기
void mystrcat(char* str1, char* str2)
{
	while (*str1 != NULL) {
		*str1++;
	}
	while (*str2 != NULL) {
		*str1++ = *str2++;
	}
	*str1 = NULL;
	return str1;
}

// 문자열을 뒤집음
void mystrreverse(char* str)
{
	int i;
	int len = 0;
	char temp;
	while (str[len] != NULL) {
		len++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return str;
}