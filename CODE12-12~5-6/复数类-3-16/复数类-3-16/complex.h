#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Complex
{
public:

	Complex(double real,double image)//构造函数
		:_real(real)
		,_image(image)
	{}
	  /*ostream &operator <<(ostream &_cout)
		{
			_cout<<_real<<" "<<_image<<endl;
			return _cout;
		
		}*/
	friend ostream &operator <<(ostream &_cout,const Complex c);


	 Complex operator +(Complex &c)//运算符的重载
	{
		Complex ret (_real + c._real,_image + c._image);
		return ret ;
    }
	 Complex &operator = (const Complex &c)
	 {
		 if(this!=&c)
		 {
			 _real = c._real;
			 _image = c._image;
		 }
		 return *this;
	 }
	 Complex operator - (const Complex &c)
	 {
		 return Complex(_real-c._real,_image-c._image);
	 }
	 Complex operator * ( const Complex &c)
	 {
		 return Complex((_real*c._real)-(_image*c._image),(_real*c._image)+(_image*c._real));
	 }
	 Complex operator / (const Complex &c)
	 {
		 return Complex (_real/((c._real*c._real)+(c._image*c._image)),
			 _image/((c._real*c._real)+(c._image*c._image)));
	 }
	 Complex operator +=( Complex &c)
	 {
		 _real = _real+c._real;
		 _image = _image+c._image;
		return Complex(_real,_image);
	 }
	 Complex operator -=( Complex &c)
	 {
		 _real = _real-c._real;
		 _image = _image-c._image;
		 return Complex(_real,_image);
	 }
	 Complex operator *= ( Complex &c)
	 {
		double tmp1 = 0;
		double tmp2 = 0;
		 tmp1 = _real;
		 tmp2 = _image;
		 _real = ((tmp1*c._real)-(tmp2*c._image));//注意在赋值的时候吧实部改变了，定义一个变量先保存
		 _image = ((tmp1*c._image)+(tmp2*c._real));
		 return Complex (_real,_image);
	 }
	 Complex operator /=(Complex &c)
	 {
		 _real = _real/((c._real*c._real)+(c._image*c._image));
		 _image = _image/((c._real*c._real)+(c._image*c._image));
		 return Complex(_real,_image);
	 }


	 bool operator >(const Complex &c)
	{
		if (_real > c._real)
			return true;
		else return false;
		
		
	}
	
	 bool operator <(const Complex &c)
	{
		if (_real >= c._real)
			return false;
		else return true;

	}
	 bool operator ==(const Complex &c)
	{
		if (_real == c._real)
			return true;
		else return false;

	}
	 bool operator !=(const Complex &c)
	{
		if (_real != c._real)
			return true;
		else return false;

	}


private:
	double _real;
	double _image;
	
};