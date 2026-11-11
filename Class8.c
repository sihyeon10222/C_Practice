#include <ctype.h>
#include "company.h"

int binary_search(const char* name, COMPANY companies[], int count);

int main() {
    COMPANY companies[NO_COMPANY];
    const char* fname = "../기업리스트.txt";
    int no_companies = read_companies(fname, companies, NO_COMPANY);
    print_companies(companies, no_companies);

    print_companies(companies, no_companies);
    qsort(companies, no_companies, sizeof(COMPANY), compare_by_name);
    print_companies(companies, no_companies);

    int search = binary_search("산하건설(주)", companies, no_companies);
    printf("\n탐색결과:\n");
    print_company(companies[search]);

    return 0;
}

int binary_search(const char* name, COMPANY companies[], int count) {
    int low, high, mid;

    low = 0;
    high = count - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        int result = strcmp(name, companies[mid].name);
        if (result == 0)
            return mid;
        else if (result < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

void print_company(COMPANY com) {
    printf("%-20s\t %d\t %-10s\t %s\n", com.name, com.no_employee, com.phone, com.webpage);
}

void print_companies(COMPANY companies[], int no_companies) {
    printf("========================================================");
    for (int i = 0; i < no_companies; i++)
        print_company(companies[i]);
}

int compare_by_name(const void* a, const void* b) {
    COMPANY c1 = *(const COMPANY*)a;
    COMPANY c2 = *(const COMPANY*)b;
    //return c1.no_employee = c1.no_employee;
    return strcmp(c1.name, c2.name);
}

COMPANY search_by_name(const char *name, COMPANY companies[], int no_companies) {
    for (int i = 0; i < no_companies; i++) {
        if (strcmp(companies[i].name, name) == 0)
            return companies[i];
    }
    return (COMPANY){0};
}
