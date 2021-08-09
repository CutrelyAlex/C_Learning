/*
指针进阶.
*/

/*
快速回顾
指针是个变量,存放地址
指针固定大小(4/8字节)
指针是有类型,指针类型决定指针步长，解引用时的权限.
void test ( int arr[] )
{
	int sz = sizeof ( arr ) / sizeof ( arr[0] );
	printf ( "%d\n", sz );
}
int main ()
{
	int arr[10] = { 0 };
	test ( arr );
	return 0;
}

*/

#include <stdio.h>
/*一,字符指针*/

//int main ()
//{
//	char arr[] = "abced";
//	char* pc = arr;
//	printf ( "%s\n", arr );
//	printf ( "%s\n", pc );//打印结果相同(arr,pc都是首元素地址)
//	char* p = "abcdef";//"abcdef"是一个常量字符串 意思是把a的地址赋值给p
//	printf ( "%c\n", *p );
//	printf ( "%s\n", p );
//
//	//char* ps = "abcdef";
//	//*ps = 'W';
//	//printf ( "%s\n", ps );  错误写法
//
//	const char* pw = "abcdef" //正确写法;
//}

//int main ()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	if (p1 == p2)
//	{
//		;//1
//	}
//	else
//	{
//		;//2
//	}
//	//执行语句块1,原因:abcdef是常量字符串
//	//p1,p2指向常量字符串不可修改
//}


/*指针数组*/
//数组,存放指针
//
//int* parr[4]; //存放整形指针的数组
//char*  pch[5];//存放字符指针的数组
//int main ()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int * parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf ( "%d ", *(parr[i] + j) );
//		}
//		printf ( "\n" );
//	}
//	return 0;
//}

/*数组指针*/
//指针 指向数组
//
//int main ()
//{
//	int arr[10] = { 0 };
//	//arr -首元素地址
//	//&arr - 数组的地址
//	//&arr[0] -首元素的地址
//	int ( *p )[10] = &arr;
//	return 0;
//}

//int main ()
//{
//	char* arr[5];
//	char *(*pa)[5] = &arr;
//}

//void print1 ( int ( *p )[3], int x, int y )
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ",*(*(p + i)+j));
//			printf("%d ", p[i][j]);
//			printf ( "%d ", *((*(p + i))+j) );
//			printf ( "%d ", (*(p + i))[j] );
//		}
//	}
//}
//int main ()
//{
//	int arr[2][3] = { {1,2,3},{7,8,9} };
//	print1 (arr,2,3);
//}

/*数组参数 指针参数*/
//一维数组
//void test{int arr[]}  --ok
//void test{int arr[10]} --ok
//void test(int *arr) --ok
//---
//void test2(int *arr[20]) --ok
//void test2(int **arr)  --ok

//二维数组
//void test(int arr[3][5])  --ok
//void test(int arr[][5])  --ok
//void test(int arr[3][])  --NO,第二个下标不可省略

//void test(int *arr) --NO,二维数组的首元素地址是一维数组地址
//void test(int **arr) --NO,数组地址不能存放在二级指针
//void test(int (*arr)[5])--ok

//指针传参
//void test(int *p)
//test 能传int类型的地址，一级指针，一维数组

//二级指针传参
//void test(int** ptr)
//test 能传一级指针的地址 二级指针 指针数组

//-------------
/*函数指针*/
//指向函数的指针
//int test (int x,int y)
//{
//	return x + y;
//}
//int main ()
//{
//	test ( 2, 3 );
//	printf ( "%p\n", &test );
//	printf ( "%p\n", test );
//	//&函数名,和函数名都是函数的地址
//	//
//	int ( *pa )(int, int) = test;
//	printf ( "%d\n", (*pa)(2, 3) );
//	return 0;
//}
//
//
//void Print ( char* str )
//{
//	printf ( "%s\n", str );
//}
//int main ()
//{
//	void ( *p )(char*) = Print;
//	(*p)("Hello world");
//------p("Hello");
//	return 0;
//}
//

//char* my_string ( char* dest, const char* src )
//{
//
//}
//int main()
//{
////写一个函数指针,指向my_string
//char* (*pms)(char*, const char*) = my_string;
////写一个函数指针数组,存放4个my_string
//char* (*pfArr[4])(char*, const char*);
//}

//
//案例:计算器-----转移表
//int Add ( int x, int y )
//{
//	return x + y;
//}
//int Sub ( int x, int y )
//{
//	return x - y;
//}
//int main ()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ( *pfArr[3] )(int, int) = { 0,Add,Sub };
//	do
//	{
//		scanf ( "%d", &input );
//		printf ( "\n" );
//		if (input >= 1 && input <= 2)
//		{
//			scanf ( "%d%d", &x, &y );
//			int ret = pfArr[input] ( x, y );
//			printf ( "%d", ret );
//		}
//		else
//		{
//			break;
//		}
//			
//	} while (input);
//}
//

/*指向函数指针数组的指针*/
//int Add ( int x, int y )
//{
//	return 0;
//}
//int main ()
//{
//	int arr[10] = { 0 };
//	int ( *p )[10] = &arr;
//	int ( *pfArr[4] )(int, int);
//	int ( *(*ppfArr[4]) )(int, int) = &pfArr;
//	//ppfArr是一个数组指针,指针指向数组有4个元素
//	//指向的数组的每个元素类型是指针
//	//指针指向一个函数 函数返回类型是int,参数是(int,int)
//	return 0;
//}
//



