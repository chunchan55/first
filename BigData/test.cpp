//#pragma 
//#include "BigData.h"
//
//int main()
//{	BDTest();
//return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1

#include "BigData.h"

void testInvaild()
{
	cout<<BigData("12345678")<<endl;
	cout<<BigData("+12345678")<<endl;
	cout<<BigData("-12345678")<<endl;
	cout<<BigData("1234abc34567")<<endl;
	cout<<BigData("abc123456")<<endl;
	cout<<BigData("000123456")<<endl;
	cout<<BigData("000000000")<<endl;
	cout<<BigData("		12345")<<endl;
	cout<<BigData("		")<<endl;
	cout<<BigData("0")<<endl;
}

void testAdd()
{
	BigData b1("999999999999999999999999999999999");
	BigData b2("-99");
	BigData b3("99");
	BigData b4("999999");
	cout<<b2+b1<<endl;
	cout<<b3+b4<<endl;
}

void testSub()
{
	BigData b1("-222222222222222222222222222222222");  //一次借位
	BigData b2("-99");
	BigData b3("10");  //多次借位
	BigData b4("99");
	cout<<b1-b2<<endl;
	cout<<b3-b4<<endl;
}

void testMul()
{
	BigData b1("-999999999999999999999999999999999");
	BigData b2("99");
	BigData b3("10000000000000000000000000000000001");
	BigData b4("99");
	BigData b5("99");
	BigData b6("99");
	cout<<b1*b2<<endl;
	cout<<b3*b4<<endl;
	cout<<b5*b6<<endl;
}

void testDiv()
{
	BigData b1("22222222222222222222222222");
	BigData b2("33");
	BigData b3("100000000000000000000000000000001");
	BigData b4("-1");
	BigData b5("99");
	BigData b6("999");
	cout<<b1/b2<<endl;
	cout<<b3/b4<<endl;
	cout<<b5/b6<<endl;
	cout<<b6/b5<<endl;
}

int main()
{
	//testInvaild();
	//testAdd();
	//testSub();
	//testMul();
	testDiv();
	return 0;
}