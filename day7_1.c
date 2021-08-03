/*
C语言初学
结构体
By	 D菌
*/
#include <stdio.h>

//struct 结构体关键字
//Stu-- 结构体标签
//typedef struct Stu 
//{
////成员变量
//	char name[20];
//	short age;
//	char tel[12];
//	char gender[5];
//}Stu; //s1,s2是全局结构体变量
//
//
//int main ()
//{
//	//Stu s1 = {"张三",.....};//student1是局部结构体变量
//}

//结构体嵌套
//struct S
//{
//	int a;
//	char c;
//};
//struct T
//{
//	char ch[10];
//	struct S s;
//	char *pc;
//};
//int main ()
//{
//	char arr[] = "helloworld\n";
//	struct T t = { "hha",{2,'A'},arr };
//}

typedef struct Stu
{
	char name[10];
	int age;
}Stu;
void Print1 ( Stu* pStu )
{
	printf ( "%s ", pStu->name );
	printf ( "%d", pStu->age );
}
int main ()
{
	Stu s = { "ABC" ,20};
	Print1 ( &s );//最好传地址
	//Print2(s)  传结构体时 参数要压栈 性能开销大
	return 0;
}
