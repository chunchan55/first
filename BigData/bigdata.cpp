#define _CRT_SECURE_NO_WARNINGS 1
#include "BigData.h"
const INT64 UN_INIT=0xcccccccccccccccc;
const INT64 MaxValue=+9223372036854775807;
const INT64 MinValue=-9223372036854775808;

BigData::BigData(INT64 value=UN_INIT)
:_value(value)
{
	char buf[128]={0};
	sprintf(buf,"%lld",_value);
	_strData=buf;
}

BigData::BigData(const std::string& str)
:_value(0)
,_strData("+0")
{
	//�մ�
	if(str.empty())
		return ;
	char *pData=(char *)str.c_str();
	//�����ո�
	while(isspace(*pData))
	{
		pData++;
	}
	//����һ����ȫ���ǿո�
	if(*pData == '\0')
		return ;
	//ȷ������λ
	char sign=*pData;
	if(*pData == '+' || *pData == '-')
		pData++;
	else if(isdigit(*pData))
		sign='+';
	else
		return ;
	//����ǰ������ַ�0
	while(*pData == '0')
	{
		pData++;
	}
	//ȫ0
	if(*pData == '\0')
		return ;
	_strData.resize(strlen(pData)+1);
	_strData[0]=sign;   //��һλ��ŷ���λ
	size_t count=1;
	//�������������_value��_strData�ж�����һ��
	while(*pData >= '0' && *pData <= '9')
	{
		_value=_value*10+*pData-'0';
		_strData[count++]=*pData;
		pData++;
	}
	if(sign == '-')
		_value=0-_value;

	_strData.resize(count);  //��С��ǰ�Ŀռ��С
}
//��������������
ostream& operator<<(ostream& os,const BigData& b)
{
	const char *pData=b._strData.c_str();
	if(*pData == '+')
		cout<<pData+1;
	else 
		cout<<pData;
	return os;
}
//�ж������Ƿ����
bool BigData::IsINT64OverFlow(const string& strData)
{
	const string maxValue="+9223372036854775807";
	const string minValue="-9223372036854775808";
	if(strData.size() < maxValue.size())
		return false;
	else if(strData.size() == maxValue.size())
	{
		if(strData[0] == '+' && strData <= maxValue \
			|| strData[0] == '-' && strData >= minValue)
			return false;
	}
	return true;
}

BigData BigData::operator+(const BigData& b)
{

	//-99 99999
	//111  2222
	//
	if(!IsINT64OverFlow(_strData) && !IsINT64OverFlow(b._strData))
	{
		if(_strData[0] != b._strData[0]) //����������ŵĻ�ֱ�����
		{
			return BigData(_value+b._value);
		}
		else if(_strData[0] == '+' && MaxValue-_value >= b._value || \
			_strData[0] == '-' && MinValue-_value <= b._value)//�ж���������ӻ᲻�����
		{
			return BigData(_value+b._value);
		}
	}
//�����
	if(_strData[0] == b._strData[0])   //ͬ����ӣ�����Add����
	{
		return Add(_strData,b._strData);
	}
	else
	{
		//������ת��Ϊ�������
		string left=_strData;
		string right=b._strData;
		left[0] = '+';
		right[0] = '+';
		if(_strData[0] == '-')
			std::swap(left,right);//��֤��ߵ�����
		return Sub(left,right);
	}
}

BigData BigData::operator-(const BigData& b)
{
	if(_strData[0] == b._strData[0])   //ͬ�ŵĻ�ֱ�����
		return Sub(_strData,b._strData);

	return Add(_strData,b._strData);  //���
}



BigData BigData::operator*(const BigData& b)
{
	if(_strData == "+0" || b._strData == "+0")//����Ϊ0
		return BigData(0);
	if(!IsINT64OverFlow(_strData) && !IsINT64OverFlow(b._strData))//δ���
	{
		INT64 maxValue=9223372036854775807;
		INT64 minValue=0-9223372036854775808;
		if(_strData[0] == b._strData[0])   //ͬ��
		{
			if((_strData[0] == '+' && maxValue /_value >= b._value) || \
				(_strData[0] == '-' && maxValue / _value <= b._value))//û�����ֱ�ӳ�
				//����һ������maxValue /_value >= b._value��֤�����Ҳ�����
				return BigData(_value*b._value);
		}
		else  //���
		{
			if(_strData[0] == '+' && minValue / _value <= b._value || \
				_strData[0] == '-' && minValue / _value >= b._value)
				return BigData(_value*b._value);
		}
	}
	//�ж��Ƿ��������1�����
	if(_strData[0] == '+1')
		return BigData(b._strData);
	if(b._strData[0] == '+1')
		return BigData(_strData);
	if(_strData[0] == '-1')
	{
		string tmp=b._strData;
		if(b._strData[0] == '-')  //- -
			tmp[0]='+';
		else   // - +
			tmp[0]='-';
		return BigData(tmp);
	}
	if(b._strData[0] == '-1')
	{
		string tmp=_strData;
		if(_strData[0] == '-') //- -
			tmp[0]='+';
		else  //+ -
			tmp[0]='-';
		return BigData(tmp);
	}//������������꣬�����Ǵ�����
	return Mul(_strData,b._strData);
}


BigData BigData::operator/(const BigData& b)
{
	if(b._strData == "+0")
	{
		cout<<"����Ϊ0����"<<endl;
		return BigData(0);
	}
	if(!IsINT64OverFlow(_strData) && !IsINT64OverFlow(b._strData))  //�������ֶ�û�����
		return BigData(_value/b._value);
	//������Ϊ0���������ĳ���С�ڳ���������С�ڳ���
	if(_strData == "+0" || _strData.size() < b._strData.size() || \
		_strData.size() == b._strData.size() && strcmp(_strData.c_str()+1,b._strData.c_str()+1) < 0)
	{
		return BigData(0);
	}
	//���ֲ�����ͬ�����Ų�ͬ
	if(strcmp(_strData.c_str()+1,b._strData.c_str()+1) == 0)
	{
		BigData ret('+1');
		if (_strData[0] != b._strData[0])  //���
		{
			ret._value=0-ret._value;
			ret._strData[0]='-';
		}
		return ret;
	}
	//������+1,-1
	if(b._strData == "+1")
		return *this;
	if(b._strData == "-1")
	{
		BigData ret(*this);
		if(_strData[0] == '+')
			ret._strData[0]='-';
		else
			ret._strData[0]='+';
		ret._value=0-ret._value;
		return ret;
	}

	return Div(_strData,b._strData);
}


BigData BigData::Add(string left,string right)
{
	size_t leftsize=left.size();
	size_t rightsize=right.size();
	char symbol = left[0];
	if(rightsize > leftsize)   //ʼ�ձ�����ߵ����ݱ��ұߵ����ݴ�
	{
		std::swap(left,right);
		std::swap(leftsize,rightsize);
	}
	string result;
	result.resize(leftsize+1);
	result[0] = symbol;//�������	
	char step=0;      //�����λ
	for(size_t index=1;index<leftsize;++index)
	{
		char ret=left[leftsize-index]-'0';
		if(index < rightsize)
			ret=ret+right[rightsize-index]-'0';
		ret += step;
		step=ret/10;    //���½�λ��ֵ��ȡ�ϸ�λ
		result[leftsize+1-index]=ret%10+'0';
	}
	result[1]=step+'0'; //��ӵ����һλҲ�п��ܲ�����λ

	return result;
}

BigData BigData::Sub(string left,string right)
{
	char sign=left[0];
	size_t leftsize=left.size();
	size_t rightsize=right.size();
	if(leftsize < rightsize || leftsize == rightsize && left < right)  //������ߵ�С
	{
		//���ﴦ��ӷ����õ�ʱ��
		if(right[0] == '+')
			sign='-';
		else
			sign='+';
		std::swap(left,right);
		std::swap(leftsize,rightsize);
	}
	string result;
	result.resize(leftsize);
	result[0]=sign;
	for(size_t index=1;index<leftsize;++index)
	{
		char ret=left[leftsize-index]-'0';
		if(index < rightsize)
			ret=ret-(right[rightsize-index]-'0');
		if(ret < 0)  //�����Ľ��Ϊ�������Ӹ�λ��λ����1��10
		{
			left[leftsize-index-1] -= 1;
			ret += 10;
		}
		result[leftsize-index]=ret+'0';
	}
	return result;
}

BigData BigData::Mul(string left,string right)
{
	//ȷ�����ս���ķ���λ
	char sign='+';
	if(left[0] != right[0])
		sign='-';
	size_t leftsize=left.size();
	size_t rightsize=right.size();
	//ȷ��������ĳ���С���ұ����ݵĳ���
	if(leftsize > rightsize)
	{
		std::swap(left,right);
		std::swap(leftsize,rightsize);
	}
	string result;
	result.resize(leftsize+rightsize-1,'0');
	result[0]=sign;
	char step=0;    //�洢��λ
	char iOffset=0; //�洢ƫ����
	//�˷���ԭ���ǻ�ȡ��ߵ�һλ���ݷֱ������һ������ÿһλ�������õ�����ѭ��
	for(size_t i=1;i<leftsize;++i)
	{
		char tmp=left[leftsize-i]-'0';
		if(tmp == 0)   //���˵��м��0
		{
			iOffset++;
			continue;
		}
		step=0;     //��λ��ֵ����
		for(size_t j=1;j<rightsize;++j)
		{
			char ret=tmp*(right[rightsize-j]-'0');
			ret += step;
			ret = ret + (result[leftsize+rightsize-1-j-iOffset]-'0');
			step=ret/10;   //���½�λ��ֵ
			result[leftsize+rightsize-1-j-iOffset]=ret%10+'0';
		}
		result[leftsize-iOffset-1] = step+'0';
		iOffset++;
	}
	return result;
}

BigData BigData::Div(string left,string right)//һ��һ�γ�
{
	char sign='+';
	if(left[0] != right[0])//���
		sign='-';
	size_t leftsize=left.size();
	size_t rightsize=right.size();
	char *pleft=(char *)left.c_str()+1;
	char *pright=(char *)right.c_str()+1;
	size_t dataLen=0;
	string tmp;
	tmp.append(1,sign);  //��ŷ���λ
	while(*(pleft+dataLen-1) != '\0')
	{
		if(*pleft == '0')  //�����ݸ�λ���ֵ�0���˵�
		{
			pleft++;
			tmp.append(1,'0');
			continue;
		}//����������������
		if(!IsLeftLarge(pleft,dataLen,pright,rightsize-1))//�ж��ǲ�����ߵĴ�
		{
			tmp.append(1,'0');
			dataLen++;
		}
		else
		{
			tmp.append(1,SubLoop(pleft, dataLen, pright, rightsize)+'0');
			dataLen++;
		}
	}
	return tmp;
}

//�ж��Ƿ���ߴ�
bool BigData::IsLeftLarge(const char *pleft,const size_t dataLen,const char *pright,const size_t rightsize)
{
	if(dataLen > rightsize)
		return true;
	else if(dataLen == rightsize)
	{
		if(strncmp(pleft,pright,dataLen) >= 0)
			return true;
	}
	return false;
}

char BigData::SubLoop(char*& pleft, size_t& dataLen, const char *pright,const size_t rightsize)
{
	char count = 0;
	//ȷ����ߴ����ұ�
	while (IsLeftLarge(pleft,dataLen,pright,rightsize-1))
	{
		for (size_t index=1;index<=dataLen;index++)
		{
			char ret=pleft[dataLen-index]-'0';
			if (index < rightsize)
			{
				ret -= pright[rightsize-index-1]-'0';
			}
			if (ret < 0)  //���λ��λ����1��10
			{
				pleft[dataLen-index-1] -= 1;
				ret += 10;
			}
			pleft[dataLen-index]=ret+'0';
		}
		count++;
		while (*pleft == '0' && dataLen > 0)  //������λ��0
		{
			pleft++;
			dataLen--;
		}
	}
	return count;
}