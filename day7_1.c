/*
C���Գ�ѧ
�ṹ��
By	 D��
*/
#include <stdio.h>

//struct �ṹ��ؼ���
//Stu-- �ṹ���ǩ
//typedef struct Stu 
//{
////��Ա����
//	char name[20];
//	short age;
//	char tel[12];
//	char gender[5];
//}Stu; //s1,s2��ȫ�ֽṹ�����
//
//
//int main ()
//{
//	//Stu s1 = {"����",.....};//student1�Ǿֲ��ṹ�����
//}

//�ṹ��Ƕ��
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
	Print1 ( &s );//��ô���ַ
	//Print2(s)  ���ṹ��ʱ ����Ҫѹջ ���ܿ�����
	return 0;
}
