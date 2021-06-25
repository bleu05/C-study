#include<stdio.h>
#include<string.h>

struct b {
	char name[100];
	char public[100];
	char title[100];
};

int main() {
	struct b book[100];
	int number;
	int n = 0;

	FILE* fp;
	fp = fopen("book.txt", "a");
	while (1) {
		printf("====================\n");
		printf("1. 파일 읽기\n");
		printf("2. 추가\n");
		printf("3. 출력\n");
		printf("4. 검색\n");
		printf("5. 파일쓰기\n");
		printf("6. 종료\n");
		printf("====================\n");
		printf("정수값을 입력하시오 : ");
		scanf("%d", &number);
		if (number == 1) {
			fp = fopen("book.txt", "r");
			if (fp == NULL) {
				puts("파일 오픈 실패\n");
			}
			else {
				puts("파일 오픈 성공!");
			}
			fclose(fp);
		}
		else if (number == 2) {
			printf("도서의 이름 : ");
			scanf("%s", book[n].title);
			printf("저자 : ");
			scanf("%s", book[n].name);
			printf("출판사 : ");
			scanf("%s", book[n].public);
			fp = fopen("book.txt", "a");
			fprintf(fp, "\n %s %s %s", book[n].title, book[n].name, book[n].public);
			fclose(fp);
			n++;

		}
		else if (number == 3) {
			fp = fopen("book.txt", "r");
			while (!feof(fp)) {
				for (int i = 0; i < n; i++) {
					fscanf(fp, "%s %s %s", book[i].title, book[i].name, book[i].public);
					printf(" %s \n", book[i].title);
					printf(" %s \n", book[i].name);
					printf(" %s\n", book[i].public);
				}

			}
			fclose(fp);
		}
		else if (number == 4) {
			char search[100];
			printf("제목 : ");
			scanf("%s", search);
			for (int i = 0; i < 100; i++) {
				if (strcmp(search, book[i].title) == 0)
					printf("출판사는  %s\n", book[i].public);
			}

		}
		else if (number == 5) {
			fp = fopen("book.txt", "w");
			if (fp == NULL) {
				puts("파일 오픈 실패\n");
			}
			else {
				puts("파일 오픈 성공!(2)");
			}
			fclose(fp);
		}
		else if (number == 6) {
			printf("프로그램이 종료 됩니다");
			break;
		}
	}
	return 0;
}