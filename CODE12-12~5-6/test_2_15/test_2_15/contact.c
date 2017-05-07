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
		printf ("电话本满了。\n");
		return ;
	}
	printf ("请输入姓名>:");
	scanf ("%s",pcon->contact[pcon->count].name);
	printf ("请输入年龄>:");
	scanf ("%d",&(pcon->contact [pcon->count].age));
	printf ("请输入性别>:");
	scanf ("%s",pcon->contact [pcon->count].sex);
	printf ("请输入电话>:");
	scanf ("%s",pcon->contact [pcon->count].tel);
	printf ("请输入地址>:");
	scanf ("%s",pcon->contact [pcon->count].addr);
	pcon->count ++;
	printf("添加成功\n");

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
		printf ("电话本为空，无法删除\n");
		return ;
	}
	printf ("请输入要删除的人名字>:");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("要删的人不存在\n");
		return ;
	}
	for (i=pos;i<pcon->count;i++)
	{
		pcon->contact[i] = pcon->contact[i+1]; 
	}
	pcon->count--;
	printf ("删除成功\n");


}
void SearchContact(pContact pcon)
{
	int pos = 0;
	char name[MAX_NAME] = {0};
	printf ("请输入你要查找的人名字\n");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("没有这个人\n");
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
	printf ("请输入你要查找的人名字\n");
	scanf ("%s",name);
	pos = find_entry(pcon,name);
	if (pos==-1)
	{
		printf ("没有这个人\n");
		return ;
	}
	printf ("请输入你要改为的名字\n");
	scanf ("%s",name);
	printf ("请输入你要改为的年龄\n");
	scanf ("%d",&age);
	printf ("请输入你要改为的性别\n");
	scanf ("%s",sex);
	printf ("请输入你要改为的电话\n");
	scanf ("%s",tel);
	printf ("请输入你要改为的地址\n");
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
				  

