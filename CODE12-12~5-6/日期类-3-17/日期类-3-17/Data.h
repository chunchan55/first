#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int _CheckYear(int year)
{
	if (((year%4==0)&&(year%100!=0))||(year%400==0))
	{
		return 1;
	}
	else 
	{
	  return 0;
	}
	return -1;
}
void AddCheckDay (int &year, int &month,int &day,int days)//�ӵ�����С��31��
{
	
	if ((month==1)||(month==3)||(month==5)
		||(month==7)||(month==8)||(month==10)
		||(month==12))//31����·�
	{
		if(month==12)
		{
			if ((day+days)>31)
			{
				year++;
				month = 1;
				day = (day+days)-31;
			}
		}
		else

		{
			if ((day+days)>31)
		  { 
				month++;
				day = (day+days)-31;
		  }
		else 
		  {
			    day+=days;
		  }
		}
	}
	else 
		if ((month==4)||(month==6)||(month==9)
			||(month==11))//31����·�
	{
		if ((day+days)>30)//30����·�
		{
			month++;
			day = (day+days)-30;
				
		}
		else 
		{
			day+=days;
		}
	}

}
void AddCheck2Month (int ret,int &month,int &day,int days)
{
	if (ret==1)
	{
		if (month==2)
		{
			if ((day+days)>28)//�ж�2��
			{
				month++;
				day = (day+days)-28;
			}
			else
			{
				day +=days;
			}
		}

	} 
	else
		{
			if (month==2)
			{
				if ((day+days)>29)//�ж�2��
				{
					month++;
					day = (day+days)-29;
				}
				else
				{
					day +=days;
				}
			}
		}
}


void SubCheckDay (int &year,int &month,int &day,int days)
{
		if ((day-days)<1)
		{
			if (month==1)
			{
				if ((day-days)<1)
				{
					year--;
					month = 12;
					day = 31-(days-day);
					return ;
				}

			}
		}

				if ((month==1)||(month==3)||(month==5)
					||(month==7)||(month==8)||(month==10)
					||(month==12))
				{
					if ((day-days)<1)
					{
						month--;
						day = 31-(days-day);
					}
					else 
					{
						day-=days;
					}
					
				}
				else
					if ((month==4)||(month==6)||(month==9)
					||(month==11))
				{
					if ((day-days)<1)
					{
						month--;
						day = 30-(days-day);
					}
					else 
					{
						day-=days;
					}
				}
}
void SubCheck2Month (int ret,int &month,int &day,int days)
{
	if (ret==1)
	{
		if (month==2)
		{
			if ((day-days)<1)//�ж�2��
			{
				month--;
				day = 28-(days-day);
			}
			else
			{
				day -=days;
			}
		}

	} 
	else
	{
		if (month==2)
		{
			if ((day-days)<1)//�ж�2��
			{
				month--;
				day = 29 - (days-day);
			}
			else
			{
				day -=days;
			}
		}
	}
}
class Data
{
public:
	Data (int year = 0 ,int month = 0,int day = 0)
		:_year(year)
		,_month(month)
		,_day(day)
	{
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
	Data &operator + (const int d)
	{
		//�ж�����
		int ret = _CheckYear(_year);
		AddCheckDay(_year,_month,_day,d);//Ҫ�ȵ������������Ȼ�������ȵ��������Ǹ���ı��£�
		                         //Ȼ���ڵ�������������ּ�һ������
		AddCheck2Month(ret,_month,_day,d);
		//�ж����е��·ݺ����Ƿ����
		//����ʵ�֣���Ϊ���涼���õ�
		//�ж������Ϸ���
		
		return *this;
	}
	Data &operator -(const int d )
	{
		int ret = _CheckYear(_year);
		SubCheckDay(_year,_month,_day,d);
		SubCheck2Month(ret,_month,_day,d);
		return *this;

	}
	Data &operator++ ()//ǰ�üӼ�
	{
		int ret = _CheckYear(_year);
		AddCheckDay(_year,_month,_day,1);
		AddCheck2Month(ret,_month,_day,1);
		return *this;
	}
	Data operator++(int)//���üӼ�
	{
		Data temp (*this);
		int ret = _CheckYear(_year);
		if ((_month==1)||(_month==3)||(_month==5)
			||(_month==7)||(_month==8)||(_month==10)
			||(_month==12))//31����·�
		{
			if(_month==12)
			{
				if (_day==31)
				{
					_year++;
					_month = 1;
					_day = 1;
					return temp;
				}
			}
			else 

			{
				if (_day==31)
				{ 
					_month++;
					_day = 1;
				}
				else 
				{
					_day++;
				}
			}
		}
		else 
			if ((_month==4)||(_month==6)||(_month==9)
				||(_month==11))//31����·�
			{
				if (_day==30)//30����·�
				{
					_month++;
					_day = 1;

				}
				else 
				{
					_day++;
				}
			}
			if (ret==1)
			{
				if (_month==2)
				{
					if (_day==28)//�ж�2��
					{
						_month++;
						_day = 1;
					}
					else
					{
						_day ++;
					}
				}

			} 
			else
			{
				if (_month==2)
				{
					if (_day==29)//�ж�2��
					{
						_month++;
						_day = 1;
					}
					else
					{
						_day ++;
					}
				}
			}


		return temp;


	}
	Data operator--()//ǰ�ü���
	{
		int ret = _CheckYear(_year);
		SubCheckDay(_year,_month,_day,1);
		SubCheck2Month(ret,_month,_day,1);
		return *this;
	}
	Data operator--(int)//���ü��������ܴ���ַ����ı䵱ǰ�����ֵ
	{
		Data temp (*this);
		if (_day==1)
		{
			if (_month==1)
			{
				if (_day==1)
				{
					_year--;
					_month = 12;
					_day = 31;
					return temp;
				}

			}
		}

		if ((_month==1)||(_month==3)||(_month==5)
			||(_month==7)||(_month==8)||(_month==10)
			||(_month==12))
		{
			if (_day==1)
			{
				_month--;
				_day = 31;
			}
			else 
			{
				_day--;
			}

		}
		else
			if ((_month==4)||(_month==6)||(_month==9)
				||(_month==11))
			{
				if (_day==1)
				{
					_month--;
					_day = 30;
				}
				else 
				{
					_day--;
				}
			}
			return temp;
	}
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
		if ((_year<d._year)||(_month<d._month)||(_day<d._day))
		{
			return true;
		}
		else 
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


private:
	int _year;
	int _month;
	int _day;

};
