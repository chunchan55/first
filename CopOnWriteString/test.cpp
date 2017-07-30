 #include "string.h"
 #include "cowstring.h"
 int main()
 {
 
 	StringTest1();
 	//StringTest2();
 	//StringTest3();
 	//StringTest4();
 	//COWstringTest1();
	 //CTest();
 	return 0;
 }
//#include<iostream>
//using namespace std;
//
// class String 
//  { 
//  private: 
//  	char* _str; 
//  public:
//  	String(char* str = "")
//  		:_str(new char [strlen(str)+1])
//  	{
//  		strcpy(_str,str);
//  		cout<<"String(char*)"<<endl;
//  
//  	}
//  	String(const String&str)
//  		:_str(str._str)
//  	{
//  		cout<<"String(const &)"<<endl;
//  
//  	}
//  	
//  	~String()
//  	{
//  		if(_str!=NULL)
//  		delete []_str;
//  		_str = NULL;
//  		cout<<"~String"<<endl;
//  
//  	}
//  }; 
//int main()
//{
//	String s1("qwer");
//	String s2(s1);
//	String s3(s2);
//
//	return 0;
//}