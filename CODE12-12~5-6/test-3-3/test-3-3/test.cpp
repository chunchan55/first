#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;//使用命名空间std

void fun (int a,int b = 3)
{
	printf ("a = %d\n",a);
	printf ("b = %d\n",b);
}
int main ()
{
	fun(1);
	return 0;
}

//using namespace std;//使用命名空间std
//class Student
//{
//private:
//	int num;
//	int score;
//public:
//	void setdata()
//	{
//		cin>>num;
//		cin>>score;
//	}
//	void display()
//	{
//		cout<<"num = "<<num<<endl;
//		cout<<"score = "<<score<<endl;
//	};
//};
//Student stud1,stud2;
//int main()
//{
//	stud1.setdata();
//	stud2.setdata();
//	stud1.display();
//	stud2.display();
//	return 0;
//}
//int main ()
//{
//	int a = 0;
//	int b = 0;
//	int sum = 0;
//	cin>>a>>b;
//	sum = a+b;
//	cout<<"a+b = "<<sum<<endl;
//	return 0;
//
//}
