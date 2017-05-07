#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Data
{
public:
	Data(int year,int month,int day)
		:_year (year)
		,_month (month)
		,_day (day)//初始化列表，用（）
	{
		cout<<"data()"<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Data d1(2017,3,14);
	return 0;
}