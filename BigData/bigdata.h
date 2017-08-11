//#include<iostream>
//#include<string>
//#include <algorithm>
//
//using namespace std;
//#define MAX_VALUE +9223372036854775808
//#define MIN_VALUE -9223372036854775807
//
//typedef long long INT64;
//class BigData
//{
//private:
//	char* _bg;//
//	string _StrData;//������
//	INT64 _value;//�������Ϳ��Ա�ʾ������
//public:
//	friend ostream&operator<<(ostream&_cout,BigData&bg)
//	{
//		const char*pData = bg._StrData.c_str();
//		if(*pData=='+')
//			cout<<(pData+1);
//		else
//			cout<<pData;
//		return _cout;
//	}
//
//	BigData (INT64 value)
//		:_value(value)
//	{
//		char symbol = _StrData[0];
//		if(_value<0)
//			symbol = '-';
//		while(value)
//		{
//			_StrData.push_back(value%10+'0');
//			value/=10;
//		}
//		_StrData.push_back(symbol);
//		for(size_t i = 1;i<=(_StrData.size()-1)/2;++i)
//		{
//			swap(_StrData[i],_StrData[_StrData.size()-i]); 
//		}
//	}
//
//
//	BigData(const string&strData = "")//���캯��
//		:_value(0)
//		,_StrData("+0")
//	{
//		const char *pData = strData.c_str();
//		while(isspace(*pData))
//			pData++;
//		if(*pData==0)
//		{
//			return;
//		}
//		char sympol = '+';//�������λ
//		if(('+'==*pData)||('-'==*pData))
//		{
//			sympol = *pData;
//			pData++;
//		}
//		if(isdigit(*pData))
//		{
//			_StrData.resize(strlen(pData)+1);
//			_StrData[0] = sympol;
//			while('0'==*pData)
//			{
//				++pData;
//			}
//			if(*pData==0)
//			{
//				return;
//			}
//			size_t count = 1;
//			while(isdigit(*pData))
//			{
//				_value = _value*10+(*pData)-'0';
//				_StrData[count] = *pData;
//				++pData;
//				++count;
//			}
//			if('-'==sympol)
//				_value = 0-_value;
//			_StrData.resize(count);//��Ч�ַ���
//		}
//		else 
//			return ;
//	}
//
//	BigData operator+(const BigData&bg)
//	{
//		if(!ISINT64overflow()&&!bg.ISINT64overflow())
//		{
//			 if(_StrData[0]==bg._StrData[0])
//			 {
//				 return BigData(_value+bg._value);
//			 }
//			 else
//			 {
//				 if((('+'==_StrData[0])&&((INT64)(MAX_VALUE-_value)>=bg._value))||
//					 (('-'==_StrData[0])&&((INT64)(MIN_VALUE-_value)<=bg._value)))
//				 {
//					 return BigData(_value+bg._value);
//				 }
//			 }
//		}
//		else
//			if(_StrData[0]==bg._StrData[0])
//				return Add(_StrData,bg._StrData);//����һ��bigdata����
//			return Sub(_StrData,bg._StrData);
//	}
//	BigData operator-(const BigData&bg)
//	{
//		if(_StrData[0]==bg._StrData[0])//ͬ��
//		{
//			return BigData(_value-bg._value);
//		}
//		else
//			return Add(_StrData,bg._StrData);
//	}
//
//	BigData Add(string strLeft,string strRight)
//	{
//		int Lsize = strLeft.size();
//		int Rsize = strRight.size();
//		if(Lsize<Rsize)
//		{
//			strLeft.swap(strRight);
//			swap(Lsize,Rsize);
//		}
//		string strRet;//����������ֱ�Ӽ�
//		strRet.resize(Lsize+1);
//		strRet[0] = strLeft[0];
//		int step = 0;
//		for(size_t idx = 1;idx<(size_t)Lsize;++idx)
//		{
//			char res = strLeft[Lsize-idx] - '0'+step;
//			res = res + strRight[Rsize-idx] - '0';
//			step = 0;//��0
//			if(res>=10)//��λ
//			{
//				step = 1;
//				res-=10;
//			}
//			strRet[Lsize-idx+1] = res + '0';
//		}
//		//cout<<"ni"<<endl;
//		strRet[1] = step + '0';//�����һ���Ƿ��н�λ
//		return strRet;
//	}
//	BigData Sub(string strLeft,string strRight)
//	{
//		char symbol = strLeft[0];//����λ
//		size_t Lsize = strLeft.size();
//		size_t Rsize = strRight.size();
//		if(Lsize<Rsize||(Lsize==Rsize&&strLeft<strRight))//������ߵ�С
//		{
//			if(strRight[0]=='+')
//				symbol = '-';
//			else
//				symbol = '+';
//		}
//		string strRet;
//		strRet.resize(Lsize);
//		strRet[0] = symbol;//����λ
//		for(size_t idx = 1;idx<Lsize;++idx)
//		{
//			char ret = strLeft[Lsize-idx] - '0';
//			if(idx<Rsize)
//			{
//				ret = ret - (strRight[Rsize-idx]-'0');
//			}
//			if(ret<0)//�����Ľ��Ϊ-
//			{
//				strLeft[Lsize-idx-1] -= 1;
//				ret += 10;
//			}
//			strRet[Lsize-idx] = ret + '0';
//		}
//		return strRet;
//	}
//	bool ISINT64overflow()const
//	{
//		string StrTemp("+9223372036854775808");//����64λ��
//		//-9223372036854775807
//		if('-'==_StrData[0])
//			StrTemp = "-9223372036854775807";//��С��
//		if(_StrData.size()<StrTemp.size())//δ���
//			return false;
//		else
//			if(_StrData.size()==StrTemp.size())
//				return false;
//		else//���
//			return true;
//	}
//
//};
//
//void BDTest()
//{
//	
//	BigData b2("0");
//	BigData b1("123456789");
//	BigData b3("+123456789");
//	BigData b4("q123456789");
//	BigData b5("12345sdffh6789");
//	BigData b6("    123456789");
//	cout<<(b1+b2)<<endl;
//	
//}


#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include<string>
typedef long long INT64;

class BigData
{
public:
	friend ostream& operator<<(ostream& os,const BigData& b);
	BigData(INT64 value);
	BigData(const std::string& strData);
	BigData operator+(const BigData& b);
	BigData operator-(const BigData& b);
	BigData operator*(const BigData& b);
	BigData operator/(const BigData& b);
private:
	bool IsINT64OverFlow(const string& strData);
	BigData Add(string left,string right);
	BigData Sub(string left,string right);
	BigData Mul(string left,string right);
	BigData Div(string left,string right);
	bool IsLeftLarge(const char *pleft,const size_t dataLen,const char *pright,const size_t rightsize);
	char SubLoop(char* &pleft, size_t& dataLen, const char *pright,const size_t rightsize);
private:
	INT64 _value;
	std::string _strData;
};