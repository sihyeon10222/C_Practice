#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#include "company.h"
NODE* read_companies(const char* fname);

NODE* read_companies(const char* fname){
	FILE* fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open %s\n", fname);
		exit(EXIT_FAILURE);
	}
	char buf[BUFSIZ];
	fgets(buf, BUFSIZ, fp);
	COMPANY com;
	NODE* head = NULL;
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		//printf("%s", buf);
		char* tok = strtok(buf, DELIMIT);	// 구분
		tok = strtok(NULL, DELIMIT);		// 특성화고
		tok = strtok(NULL, DELIMIT);		// 기업명
		com.name = strdup(tok);
		tok = strtok(NULL, DELIMIT);		// 사원 수
		sscanf(tok, "%d", &com.no_employee);
		tok = strtok(NULL, DELIMIT);		// 대표전화
		com.phone = strdup(tok);
		tok = strtok(NULL, DELIMIT);		// 홈페이지
		com.webpage = strdup(tok ? tok : "");
		//print_company(com);
		head = insert_node_first(head, com);
	}
	fclose(fp);
	return head;
}

void print_company(COMPANY com) {
	printf("%-20s\t", com.name);
	printf("%-10s\t", com.phone);
	printf("%-30s\t", com.webpage);
	printf("%d\n", com.no_employee);
}

int compare_by_name(const void* a, const void* b) {
	COMPANY c1 = *(const COMPANY*)a; // void*를 int*로 형 변환 후 역참조
	COMPANY c2 = *(const COMPANY*)b;
	return strcmp(c1.name, c2.name);
}

void print_companies(NODE *head) {
	printf("===========================\n");
	NODE* p = head;
	while (p != NULL) {
		print_company( *(p->com) );
		p = p->link;
	}
}

NODE* insert_node_first(NODE* head, COMPANY com) {
	NODE* n = allocate_node();
	n->com = allocate_company(com);
	n->link = head;
	head = n;
	return head;
}

NODE* allocate_node() {
	NODE* n = (NODE*)malloc(sizeof(NODE));
	if (n == NULL) {
		fprintf(stderr, "no memory\n");
		exit(EXIT_FAILURE);
	}
	n->com = NULL;
	n->link = NULL;
	return n;
}

COMPANY* allocate_company(COMPANY com) {
	COMPANY* c = (COMPANY*)malloc(sizeof(COMPANY));
	if (c == NULL) {
		fprintf(stderr, "no memory\n");
		exit(EXIT_FAILURE);
	}
	*c = com;
	return c;
}
