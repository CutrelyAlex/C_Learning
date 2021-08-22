/*宏参数*/
//带有副作用的宏参数
#include<stdio.h>
#include<stdlib.h>
//
//#define MAX(X,Y)   ((X)>(Y)?(X):(Y))
//int main ()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX ( a++, b++ );
//	printf ( "%d\n", max );//12
//	printf ( "%d\n", a );//11
//	printf ( "%d\n", b );//13
//	return 0;
//}

//运用宏方便之处
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//#define FREENULL(p) free(p);p = NULL;
//int main ()
//{
//	int* p =MALLOC ( 10, int );
//	FREENULL ( p );
//}



/*习惯 宏名全大写，函数不用全大写*/

//#undef NAME 移除宏定义
//#undef MAX


/*命令行定义*/

//#include <stdio.h>
//int main ()
//{
//	int arr[SZ] = { 0 };
//	int i = 0;
//	for (i = 0; i < SZ; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < SZ; i++)
//	{
//		printf ( "%d", arr[i] );
//	}
//	return 0;
//}
//Linux中 gcc test.c -D SZ=100







