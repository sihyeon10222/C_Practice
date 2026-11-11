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

int main() {
	const char* fname = "../기업리스트.txt";
	NODE *head = read_companies(fname);
	print_companies(head);

	//qsort(companies, no_companies, sizeof(COMPANY), compare_by_name);
	//print_companies(companies, no_companies);

	//COMPANY c = search_by_name("비전세미콘", companies, no_companies);
	//print_company(c);
	return 0;
}
