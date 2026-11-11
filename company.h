#ifndef __COMPANY__
#define __COMPANY__

#define NO_COMPANY   150
#define DELIMIT      "\t\n"

struct company {
	char* name;
	char* phone;
	char* webpage;
	int   no_employee;
};
typedef struct company COMPANY;

struct node {
	COMPANY* com; // int data;
	struct node* link;
};
typedef struct node NODE;

NODE* read_companies(const char* fname);
NODE* insert_node_first(NODE *head, COMPANY com);
NODE* allocate_node();
COMPANY* allocate_company(COMPANY com);
void print_companies(NODE *head);
void print_company(COMPANY com);

//int compare_by_name(const void* a, const void* b);

#endif
