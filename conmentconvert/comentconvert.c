#define _CRT_SECURE_NO_WARNINGS 1
#include "conmentconvert.h"
static enum STATE state;
void DoNulState(FILE*pfIn,FILE*pfOut)
{
	int first = fgetc(pfIn);
	switch(first)
	{
	case '/':
		{
			int second = fgetc(pfIn);
			switch(second)
			{
			case '*':
				{
					fputc('/',pfOut);
					fputc('/',pfOut);

				    state = C_STATE;
				}
				break;
			case '/':
				{
					fputc('/',pfOut);
					fputc('/',pfOut);

				    state = CPP_STATE;
				}
				break;
			case EOF:
				state = END_STATE;
				break;
			default :
				fputc(second,pfOut);
				break;

			}
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default :
		fputc(first,pfOut);
		break;
	}
}
void DoCppState(FILE*pfIn,FILE*pfOut)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		{
			fputc(first,pfOut);
			state = NUL_STATE;
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default :
		
		{
			fputc(first,pfOut);
			state = CPP_STATE;
		}

		break;
}
}

void DoCState(FILE*pfIn,FILE*pfOut)
{
	int first = fgetc(pfIn);//*
	switch(first)
	{
	case '\n':
		{
			fputc(first,pfOut);
			fputc('/',pfOut);
			fputc('/',pfOut);
			state = C_STATE;
		}
		break;


	case '*':
		{
			int second = fgetc(pfIn);//x
			switch (second)
			{
			case '/':
				{
					int third = fgetc(pfIn);
					state = NUL_STATE;
					if(third !='\n')
					{
						fputc('\n',pfOut);
						ungetc(third,pfIn);
					}
					else if(third=='\n')
					{
						fputc(third,pfOut);
					}

				}
				break;
			default :
				/*{
					int third = fgetc(pfIn);///
					if (third!='/')
					{
						fputc(second,pfIn);
						state = C_STATE;
					}
					else if(third=='/')
					{
						fputc('\n',pfOut);
						state = NUL_STATE;
					}
					else 
					{
						fputc(second,pfIn);
						state = C_STATE;
					}
				}*/

				fputc(first,pfOut);
				ungetc(second,pfIn);
				break;

			}
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default :
		fputc(first,pfOut);
		state = C_STATE;
		break;
	}
}

void DoConvertWork(FILE*pfIn,FILE*pfOut)
{

	while(state!=END_STATE)
	{
		switch(state)
		{
		case NUL_STATE:
			DoNulState(pfIn,pfOut);
			break;
		case CPP_STATE:
			DoCppState(pfIn,pfOut);
			break;
		case C_STATE:
			DoCState(pfIn,pfOut);
			break;
		default:
			break;
		}
	}
}
