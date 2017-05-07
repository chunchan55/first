#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef     __CONTACT_H__
#define     __CONTACT_H__
#define     MAX  1000
#define     MAX_NAME 20
#define     MAX_SEX  5
#define     MAX_TEL  12
#define     MAX_ADDR  20



typedef struct PeoInfor
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char addr[MAX_ADDR];

}PeoInfor;
typedef struct Contact
{
	PeoInfor contact [MAX];
	int count;

}Contact,*pContact;

void InitContact(pContact pcon);
void AddContact(pContact pcon);
void DelContact(pContact pcon);
void SearchContact(pContact pcon);
void ModifyContact(pContact pcon);
void ShowContact(pContact pcon);
void SortContact(pContact pcon);
#endif //