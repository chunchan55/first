#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include"Complex.h"
ostream &operator <<(ostream &_cout,const Complex c )
{
	_cout<<c._real<<" "<<c._image<<endl;
	return _cout;

}
int main()
{
	Complex c1(3.0,4.0);
	Complex c2(4.0,5.0);
	Complex c3(0,0);
	Complex ret1(0,0);
	Complex ret2 (0,0);
	c3 = c1 ;
	c3 = c1 + c2;
	c3 = c2 - c1;
	c3 = c1*c2;
	//c3 = c2/c1;
	//c1 += c2;
	//c2/=c1;
	//c1 -= c2;
	//c1 *= c2;
	if (c1<c2)
	{
		cout <<"hehe"<<endl;
	}
	cout<<c1<<" "<<c2;

	return 0;
}
