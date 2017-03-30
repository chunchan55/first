#define _CRT_SECURE_NO_WARNINGS 1
#include "data.h"
ostream &operator<<(ostream &_cout ,const Data d)//Êä³öÁ÷º¯Êý

{
	_cout<<d._year<<" "<<d._month<<" "<<d._day;
	return _cout;
}
int main()
{
	Data d1(2005,12,4);
	Data d2(2008,2,13);
	Data d3(2008,4,2);
	int ret = d3 - d2;
	int tem = d2-d3;
	if (d1<d2)
	{
		cout<<d1<<endl;
	}
	cout<<ret<<" "<<tem<<endl;

	//cout<<--d1<<endl;
	return 0;
}