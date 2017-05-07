
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Data
{
public:
	Data(int year=1900,int month=1,int day=1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if ((year<0)||(month>12)||(day<0))
		{
			year = 1900;
			month = 1;
			day = 1;
		}
	}
	friend ostream& operator<<(ostream &_cout ,const Data d);
	Data &operator = (const Data &d)
	{
		if (this!=&d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	int GetMonthDays(int _year,int _month)
	{
		int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(((_year%4==0)&&(_year%100!=0))||(_year%400==0))
		{
			days[2]+=1;
		}
		return days[_month];
	}
	Data operator+(const int days)
	{
		Data temp (*this);
		/*if (days<0)
		{
			return *this-(0-days);
		}*/
		temp._day+=days;
		int daysInMonth;
		while(temp._day>(daysInMonth=temp.GetMonthDays(temp._year,temp._month)))
		{
			temp._day-=daysInMonth;
			temp._month++;
			if(temp._month>12)
			{
				temp._year++;
				temp._month = 1;
			}
		}
		return temp;

	}
	Data operator-(const int days)
	{
		Data temp (*this);
		if (days<0)
		{
			return *this+(0-days);
		}
		temp._day-=days;
		while(temp._day<=0)
		{
			temp._month--;
			if(0==temp._month)
			{
				temp._year-=1;
				temp._month=12;
			}
			temp._day +=temp.GetMonthDays(temp._year,temp._month);//一定要加temp

		}
		return temp;
	}
	Data &operator++()//前置加加
	{
		*this = *this+1;
		return *this;
	}
	//Data &operator++(int)//后置加加
	//{
	//	Data temp (*this);
	//	*this = *this+1;
	//	return temp;
	//}
	Data &operator--()//前置减减
	{
		*this = *this-1;
		return *this;
	}
	//Data &operator--(int)//后置减减
	//{
	//	Data temp (*this);
	//	*this = *this-1;
	//	return temp;

	//}
	bool operator>(const Data &d)
	{
		if (_year>d._year)
		{
			return true;
		}
		else if(_year==d._year)
		{
			if(_month>d._month)
			{
				return true;
			}
			else if(_month==d._month)
			{
				if(_day>d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool operator<(const Data &d)
	{
		if (_year<d._year)
		{
			return true;
		}
		else 
			if(_year == d._year)
			{
				if (_month<d._month)
				{
					return true;
				}
				else if (_month == d._month)
				{
					if (_day<d._day)
					{
						return true;
					}
				}
			}
			return false;
	}
	bool operator==(const Data &d)
	{
		if ((_year==d._year)&&(_month==d._month)&&(_day==d._day))
		{
			return true;
		}
		else 
			return false;
	}

	bool operator!=(const Data &d)
	{
		if ((_year!=d._year)||(_month!=d._month)&&(_day!=d._day))
		{
			return true;
		}
		else 
			return false;
	}
	int operator - (const Data &d)//计算两个日期之间的差值
	{
		Data Maxdata(*this);
		Data Mindata(d);
		int count = 0;
		if (Maxdata<Mindata)
		{
			Maxdata = d;
			Mindata = *this;
		}
		int days= 0;
		while (1)
		{
			if((Mindata+days) == Maxdata)
				break;
			days++;
		}
		return days;
		
	}
private:
	int _year;
	int _month;
	int _day;
};
