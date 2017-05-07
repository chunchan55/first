#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Student
{
public:
	void InitStudent(char*name,char*gender,int age)
	{
		strcpy(this->_name,name);
		strcpy(this->_gender,gender);
		this->_age = age;
	}
	void FunTest(... )
	{

	}
private:
	char _name[20];
	char _gender[5];
	int _age ;
};
int main()
{
	Student s1,s2;
	s1.FunTest();
	s1.InitStudent("chan","nv",18);
	s2.InitStudent("xin","nan",21);
	cout<<&s1<<endl;
	return 0;
}