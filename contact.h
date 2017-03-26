#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#ifndef     __CONTACT_H__
#define     __CONTACT_H__
#define    DEFAULT_SZ 2
#define    INC_SZ     2
#define     MAX  1000
#define     MAX_NAME 20
#define     MAX_AGE 3
#define     MAX_SEX  5
#define     MAX_TEL  12
#define     MAX_ADDR  20



typedef struct PeoInfor
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char age[MAX_AGE];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];

}PeoInfor;
typedef struct Contact
{
	PeoInfor *contact;
	int count;
	int capacity ;

}Contact,*pContact;

void InitContact(pContact pcon);
void _add(pContact pcon,PeoInfor *p);
void Load_Contact(pContact pcon);
void DestroyContact(pContact pcon);
void Save_Contact(pContact pcon);
void AddContact(pContact pcon);
void DelContact(pContact pcon);
void SearchContact(pContact pcon);
void ModifyContact(pContact pcon);
void ShowContact(pContact pcon);
void SortContact(pContact pcon);
void DestroyContact(pContact pcon);

#endif //