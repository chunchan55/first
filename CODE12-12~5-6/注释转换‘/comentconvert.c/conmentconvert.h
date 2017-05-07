#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __COMENT_H__
#define __COMENT_H__

#include <stdio.h>
enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE,
};
void DoConvertWork(FILE*pfIn,FILE*pfOut);
void DoNulState(FILE*pfIn,FILE*pfOut);
void DoCppState(FILE*pfIn,FILE*pfOut);
void DoCState(FILE*pfIn,FILE*pfOut);



#endif __COMENT_H__
