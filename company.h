#ifndef __COMPANY__
#define __COMPANY__
#define NO_COMPANY 150
#define BUFSIZE 1024
#define DELIMIT "\t\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct COMPANY {
    char* name;
    int no_employee;
    char* phone;
    char* webpage;
};

typedef struct COMPANY COMPANY;
void print_company(COMPANY com);
void print_companies(COMPANY companies[], int no_companies);
int compare_by_name(const void *a, const void *b);
COMPANY search_by_name(const char *name, COMPANY companies[], int no_companies);

int read_companies(const char *fname, COMPANY companies[], int size) {
    FILE* fp = fopen(fname, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't Open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    char buf[BUFSIZ];
    COMPANY com;
    fgets(buf, BUFSIZ, fp); // skip the first line
    int no_companies = 0;
    while (no_companies < size && fgets(buf, BUFSIZ, fp) != NULL) {
        printf("%s", buf);
        char *tok = strtok(buf, DELIMIT); // 구분
        tok = strtok(NULL, DELIMIT); // 특성화고
        tok = strtok(NULL, DELIMIT); // 기업
        com.name = strdup(tok);
        tok = strtok(NULL, DELIMIT); // 사원수
        sscanf(tok, "%d", &com.no_employee);
        tok = strtok(NULL, DELIMIT); // 대표전화
        com.phone = strdup(tok);
        tok = strtok(NULL, DELIMIT); // 홈페이지
        com.webpage = strdup(tok ? tok : "");
        //print_company(com);
        companies[no_companies] = com;
        no_companies++;
    }
    fclose(fp);
    return no_companies;
}

#endif
