/*动态内存分配*/
/*
复习:
局部变量函数形参-栈区
全局变量,静态变量-静态区
动态内存 -堆区
*/
#include <stdlib.h>
#include<errno.h>
#include<string.h>
#include<stdio.h>
#include<assert.h>
//malloc和free
//void* malloc(size_t size);
//size 开辟的字节个数
//返回起始地址
//size = 0 时是未定义的
//free中的p如果不是动态开辟的，结果未定义
//free一个NULL那么什么都不会做
//int main ()
//{
//	//申请10个整形的空间,返回起始地址给int* p
//	int* p = (int*) malloc (10*sizeof(int));
//	//如果开辟失败(内存不足),就返回NULL
//	if (p == NULL)
//	{
//		printf ( "%s\n", strerror ( errno ) );
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf ( "%d ",*(p + i) = i );
//		}
//	}
//	//动态申请结束,
//	free (p);
//	//将p赋值为NULL,防止使p变成野指针
//	p = NULL;
//	return 0;
//}

//calloc开辟一个数组，并且把数值改成0
//void* calloc(num,size)
//num是元素个数
//size是元素大小
//realloc 调整动态开辟内存的大小
//void* realloc(void* 开辟好的空间,size_t size)
//int main ()
//{
//	//如果开辟失败(内存不足),就返回NULL
//	int * p = (int*)calloc ( 10, sizeof ( int ) );
//	if (p == NULL)
//	{
//		printf ( "%s\n", strerror ( errno ) );
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf ( "%d ", *(p + i));
//		}
//	}
//	//调整动态开辟的内存 返回重新开辟好的指针
//	//如果后面空间足够追加 则直接追加
//	//如果后面空间不够追加 则出现开辟新的满足需求的内存区域，并拷贝，释放原来的内存
//	//所以返回的地址不一定是原来的地址
//	//有可能开辟失败，会返回空指针
//	//返回的地址不要直接赋给原指针
//realloc(NULL,40)和malloc(40)等价
//	int* ptr =(int*) realloc ( p, 4000 );
//	if (ptr != NULL)
//	{
//		//如果ptr不是空指针才把ptr赋值给p
//		p = ptr;
//	}
//	//释放内存
//	free ( p );
//	//置空
//	p = NULL;
//	ptr = NULL;
//	return 0;
//}

/*常见错误*/
//1.没有判断指针为NULL，就对NULL进行解引用
//2.对动态开辟内存越界访问
//3.对非动态开辟的内存free
//4.free释放动态开辟内存的一部分
//4::

//int main ()
//{
//	int*p = (int*)malloc ( 40 );
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;
//	}
//	free ( p );//p不再是原来开始
//	p = NULL;
//	return 0;
//}

//5.对同一块动态内存多次释放
int main ()
{
	int*p = (int*)malloc ( 40 );
	if (p = NULL)
	{
		return 0;
	}
	free ( p );
	//...
	free ( p );
	return 0;
}

//6.忘记释放动态内存(内存泄露)

