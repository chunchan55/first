#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"
 ostream&operator<<( ostream &_cout,String &s)
 {
	 int i = 0;
	 for (i=0;i<=sizeof(s._pStr);i++)
	 {
		 cout<<s._pStr[i];
	 }
	 return _cout;
 }

int main()
{
	String s1("hello ");
	//cout<<s1.Size()<<endl;
	String s3("bit");
	String s4("bit");

	if(s4==s3)
	{
		cout<<"deng"<<endl;
	}
	if(s1>s3)
	{
		cout<<"da"<<endl;
	}
	if(s3<s1)
	{
		cout<<"xiao"<<endl;
	}
	//s1.operator +(s3);
	//cout<<s1+s3<<endl;

	/*if(!s1.StrStr(s3))
	{
		cout<<"wu"<<endl;
	}
	else
	{
		cout<<"you"<<endl;
	}*/



	
	//cout<<s1<<endl;
	return 0;
}