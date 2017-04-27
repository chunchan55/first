#define _CRT_SECURE_NO_WARNINGS 1
#include "conmentconvert.h"
int main()
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;
	pfRead = fopen("input.c","r");
	if(pfRead==NULL)
	{
		perror("read the file");
		return ;
	}
	pfWrite = fopen("output.c","w");
	if(pfWrite==NULL)
	{
		perror("write the file");
		fclose(pfRead);
		return ;
	}
	DoConvertWork(pfRead,pfWrite);

	{
		fclose(pfRead);
	    fclose(pfWrite);
	}




	return 0;
}
