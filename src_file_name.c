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
		printf("1. ���� �б�\n");
		printf("2. �߰�\n");
		printf("3. ���\n");
		printf("4. �˻�\n");
		printf("5. ���Ͼ���\n");
		printf("6. ����\n");
		printf("====================\n");
		printf("�������� �Է��Ͻÿ� : ");
		scanf("%d", &number);
		if (number == 1) {
			fp = fopen("book.txt", "r");
			if (fp == NULL) {
				puts("���� ���� ����\n");
			}
			else {
				puts("���� ���� ����!");
			}
			fclose(fp);
		}
		else if (number == 2) {
			printf("������ �̸� : ");
			scanf("%s", book[n].title);
			printf("���� : ");
			scanf("%s", book[n].name);
			printf("���ǻ� : ");
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
			printf("���� : ");
			scanf("%s", search);
			for (int i = 0; i < 100; i++) {
				if (strcmp(search, book[i].title) == 0)
					printf("���ǻ��  %s\n", book[i].public);
			}

		}
		else if (number == 5) {
			fp = fopen("book.txt", "w");
			if (fp == NULL) {
				puts("���� ���� ����\n");
			}
			else {
				puts("���� ���� ����!(2)");
			}
			fclose(fp);
		}
		else if (number == 6) {
			printf("���α׷��� ���� �˴ϴ�");
			break;
		}
	}
	return 0;
}