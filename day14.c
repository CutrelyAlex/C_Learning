//
///*结构体传参*/
////#include <stdio.h>
////struct S
////{
////	char c;
////	int a;
////	double d;
////};
//////操作结构体时需传址
////void Init ( struct S* tmp )
////{
////	tmp->a = 100;
////	tmp->c = 'w';
////	tmp->d = 3.14
////}
//////穿值--不建议,传结构体压栈开销大
//////如果不需要更改也传地址---加const
////void Print1 ( struct S tmp )
////{
////	//
////}
////int main ()
////{
////	struct S s = {0};
////	Init (&s);
////	return 0;
////}
//
//
//
///*位段*/
///*
//结构体实现
//位段成员必须是整形
//一般是int,unsigned int,signed int
//位段成员名后有一对冒号和数字
//*/
///*
//位:二进制位
//*/
//#include <stdio.h>
//struct A
//{
//	int _a : 2; //给予2个二进制位,即可表达2^2种状态
//	int _b : 5; //5个二进制位,表达2^5...
//	int _c : 10;//
//	int _d : 30;//
//};
///*
//位段内存分配
//按照4字节或1字节开辟空间的
//注:跨平台应避免使用位段
//结构体先给出32个比特位(4个字节)
//先给出2,5,10个比特位
//已经占17个比特位，剩余不够给出30个比特位
//所以新开辟4个字节
//放入30个比特位
//故一开辟了8个字节
//*/
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main ()
//{
//	struct A s;
//	printf ( "%d", sizeof ( s ) );//输出8
//	struct S s = { 0 };
//	s._a = 10;
//	s._b = 20;
//	s._c = 3;
//	s._d = 4;
//}
///*位段应用场景*/
///*
//例子:
//网络数据传输
//[			封装(版本号,总长度,标识符,原ip,,,,,,,之后学)]"信息
//*/
//
//

/*枚举*/
//枚举类型定义
#include <stdio.h>
//enum Gender
//{
//	MALE, //0
//	FEMALE, //1
//	SECRET, //2
//};
//enum Color
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4,
//};
//int main ()
//{
//	enum Gender stu = MALE;
//	enum Gender c = 2;
//	printf ( "%d\n", sizeof ( stu ) );
//	printf ( "%d", sizeof ( MALE ) );
//}


//为什么使用枚举而不是#define
/*
可读性,可维护性高
有类型，更加严谨
防止命名污染(冲突)
便于调试
一次可定义多种常量
*/



/*联合体(共用体)*/
//一种自定义类型
//联合体成员共用空间
//#include <stdio.h>
//
//union Un
//{
//	char c;
//	int i;
//};
//union Unt
//{
//	int a;
//	char arr[5];
//};
//int main ()
//{
//	union Un u;
//	union Unt u2;
//	printf ( "%d\n", sizeof ( u ) );//联合变量的大小至少是最大成员的大小
//	printf ( "%d\n", sizeof ( u2 ) );
//	//注意:当最大成员大小不是最大对齐数的整数倍时候, 就对齐到最大对齐数的整数倍
//	printf ( "%p\n", &(u.c) );  //地址
//	printf ( "%p\n", &(u.i) );  //和上面一样
//	u.i = 0x11223344;
//	u.c = 0x55;
//	printf ( "%x\n", u.i );
//}


//使用联合体来判断大小端字节序
//int check_sys ()
//{
//	union Un
//	{
//		char c; int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}






