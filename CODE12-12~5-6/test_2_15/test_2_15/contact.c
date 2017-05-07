#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
 void InitContact(pContact pcon)
{
	pcon ->count = 0;
	memset(pcon->contact,0,MAX*sizeof(PeoInfor));
}
void AddContact(pContact pcon)
{
	if (pcon->count >=MAX)
	{
		printf ("�绰�����ˡ�\n");
		return ;
	}
	printf ("����������>:");
	scanf ("%s",pcon->contact[pcon->count].name);
	printf ("����������>:");
	scanf ("%d",&(pcon->contact [pcon->count].age));
	printf ("�������Ա�>:");
	scanf ("%s",pcon->contact [pcon->count].sex);
	printf ("������绰>:");
	scanf ("%s",pcon->contact [pcon->count].tel);
	printf ("�������ַ>:");
	scanf ("%s",pcon->contact [pcon->count].addr);
	pcon->count ++;
	printf("��ӳɹ�\n");

}
int find_entry(pContact pcon,char name[])
{
	int i = 0;
	for (i=0;i<pcon->count;i++)
	{
		if (strcmp(name,pcon->contact[i].name)==0)
			return i;
	}
	return -1;
}
void DelContact(pContact pcon)
{
	char name[MAX_NAME] = {0};
	int pos = 0;
	int i = 0;
	if (pcon->count==0)
	{
		printf ("�绰��Ϊ�գ��޷�ɾ��\n");
		return ;
	}
	printf ("������Ҫɾ����������>:");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("Ҫɾ���˲�����\n");
		return ;
	}
	for (i=pos;i<pcon->count;i++)
	{
		pcon->contact[i] = pcon->contact[i+1]; 
	}
	pcon->count--;
	printf ("ɾ���ɹ�\n");


}
void SearchContact(pContact pcon)
{
	int pos = 0;
	char name[MAX_NAME] = {0};
	printf ("��������Ҫ���ҵ�������\n");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("û�������\n");
		return ;
	}
	else 
	{
			printf ("%10s%5s%6s%7s%8s\n",
				    "name","age","sex","tel","addr"  );
		printf ("%10s%5d%6s%7s%8s\n",
			pcon->contact[pos].name,
			pcon->contact[pos].age,
			pcon->contact[pos].sex,
			pcon->contact[pos].tel,
			pcon->contact[pos].addr);
	}
}
void ModifyContact(pContact pcon)
{
	int pos = 0;
	char name[MAX_NAME] = {0};
	int age = 0;
	char sex[MAX_SEX] = {0};
	char tel[MAX_TEL] = {0};
	char addr[MAX_ADDR] = {0};
	printf ("��������Ҫ���ҵ�������\n");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("û�������\n");
		return ;
	}
	printf ("��������Ҫ��Ϊ������\n");
	scanf ("%s",name);
	printf ("��������Ҫ��Ϊ������\n");
	scanf ("%d",&age);
	printf ("��������Ҫ��Ϊ���Ա�\n");
	scanf ("%s",sex);
	printf ("��������Ҫ��Ϊ�ĵ绰\n");
	scanf ("%s",tel);
	printf ("��������Ҫ��Ϊ�ĵ�ַ\n");
	scanf ("%s",addr);
    printf ("%10s%5d%6s%7s%8s\n",
		     strcpy(pcon->contact[pos].name,name),
			 age,
			 strcpy(pcon->contact[pos].sex,sex),
		     strcpy(pcon->contact[pos].tel,tel),
			 strcpy(pcon->contact[pos].addr,addr));
}
void ShowContact(pContact pcon)
{
	int i = 0;
	printf ("%10s%5s%6s%7s%8s\n","name","age","sex","tel","addr"  );
	for (i=0;i<pcon->count;i++)
	{
		printf ("%10s%5d%6s%7s%8s\n",
			pcon->contact[i].name,
			pcon->contact[i].age,
			pcon->contact[i].sex,
			pcon->contact[i].tel,
			pcon->contact[i].addr);
	}
}
static int cmp(const void *elem1,const void *elem2)
{
		return  strcmp ((*(PeoInfor*)elem1).name ,(*(PeoInfor*)elem2).name );
}

void SortContact(pContact pcon)
{
	int i = 0;
	int sz = sizeof(pcon->contact)/sizeof(pcon->contact[0]);
	qsort (pcon->contact,pcon->count,sizeof (pcon->contact[0]),&cmp);	
		for (i=0;i<pcon->count;i++)
		{
				printf ("%s %d %s %s %s\n",
					pcon->contact[i].name,
					pcon->contact[i].age,
					pcon->contact[i].sex,
					pcon->contact[i].tel,
					pcon->contact[i].addr);
		}
	

}
				  

