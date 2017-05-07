#define _CRT_SECURE_NO_WARNINGS 1
#include "Data.h"
#include <iostream>
using namespace std;
ostream &operator<<(ostream &_cout ,const Data d)//Êä³öÁ÷º¯Êý

{
	_cout<<d._year<<" "<<d._month<<" "<<d._day;
	return _cout;
}
int main()
{
	Data d1(2004,3,31);
	//d1 = d1+3;
	Data d2(2009,4,30);
	//d2 = d2+5;
	Data d3(2004,2,28);
	//d3 = d3+2;
	Data d4(2007,2,29);
	//d4 = d4+7;
	Data d5(2004,2,1);
	//d5 = d4--;
	if (d1>d2)
	{
		cout<<d1<<endl;
	}
	else
		cout<<d2<<endl;
	if (d1==d2)
	{
		cout<<d2;
	}
	else 
		cout<<d1<<endl;
	if (d2<d3)
	{
		cout<<d2<<endl;
	}
	else
		cout <<d3<<endl;
	
	/*cout<<d1<<endl;
	cout<<d2<<endl;
	cout<<d3<<endl;
	cout<<d4<<endl;
    cout<<d5<<endl;*/
	return 0;
}