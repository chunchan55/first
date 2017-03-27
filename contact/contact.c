#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void checkcapacity(pContact pcon)
{
	if(pcon->count==pcon->capacity)
	{
		PeoInfor*ptr = (PeoInfor*)realloc(pcon->contact,(pcon->count+INC_SZ)*sizeof(PeoInfor));
		if (ptr==NULL)
		{
			printf ("out of memory\n");
			exit(EXIT_FAILURE);
		}
		else 
		{
			pcon->contact = ptr;
		}
		pcon->capacity +=INC_SZ;
	}
}
void _add(pContact pcon,PeoInfor *p)//����Ϣд���ļ���
{
	assert (pcon);
	checkcapacity(pcon);
	pcon->contact[pcon->count] = *p;
	pcon->count++;
}
void Load_Contact(pContact pcon)
{
	PeoInfor peoinfor;
	FILE *pfr = fopen("test.txt","r");
	if (pfr==NULL)
	{
		perror("open the file for read");
		exit (EXIT_FAILURE);
	}
	while (fread(&peoinfor,sizeof(PeoInfor),1,pfr))
	{
		_add(pcon,&peoinfor);
	}
}
void Save_Contact(pContact pcon)
{
	int i = 0;
	FILE*pfw = fopen("test.txt","w");
	if (pfw==NULL)
	{
		perror("open the file for write");
		exit (EXIT_FAILURE);
	}
	for (i=0;i<pcon->count;i++)
	{
		fwrite(&(pcon->contact[i]),sizeof(PeoInfor),1,pfw);
	}
	//free (pcon->contact);
	fclose(pfw);
}
void InitContact(pContact pcon)
{
	pcon ->count = 0;
	pcon->contact = (PeoInfor*)malloc(DEFAULT_SZ*sizeof(PeoInfor));
	if (pcon->contact==NULL)
	{
		strerror(errno);
		return ;
	}
	memset(pcon->contact,0,DEFAULT_SZ*sizeof(PeoInfor));
	pcon->capacity = DEFAULT_SZ;
	Load_Contact(pcon);//�����ļ�
}

void AddContact(pContact pcon)
{
	checkcapacity(pcon);
	printf ("����������>:");
	scanf ("%s",pcon->contact[pcon->count].name);
	printf ("����������>:");
	scanf ("%s",pcon->contact [pcon->count].age);
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
		printf ("%s\t%s\t%s\t%s\t%s\t\n",
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
	char age[MAX_AGE] = {0};
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
	scanf ("%s",age);

	printf ("��������Ҫ��Ϊ���Ա�\n");
	scanf ("%s",sex);
	printf ("��������Ҫ��Ϊ�ĵ绰\n");
	scanf ("%s",tel);
	printf ("��������Ҫ��Ϊ�ĵ�ַ\n");
	scanf ("%s",addr);
	printf ("%10s%6s%7s%8s\n",
		strcpy(pcon->contact[pos].name,name),
		strcpy(pcon->contact[pos].sex,age),

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
		printf ("%10s%5s%6s%7s%8s\n",
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
		printf ("%s %s %s %s %s\n",pcon->contact[i].name,
			pcon->contact[i].age,
			pcon->contact[i].sex,
			pcon->contact[i].tel,
			pcon->contact[i].addr);
	}


}

void DestroyContact(pContact pcon)
{
	Save_Contact (pcon);//����ͨѶ¼����Ҫ���ļ���д�ļ�
	if (pcon->contact!=NULL)
	{
		free(pcon->contact);
		pcon->contact = NULL;
	}
}

