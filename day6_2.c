#include <stdio.h>
//int main ()
//{
//	int arr[10] = { 0 };
//	printf ("%p\n", arr+1);//arr-首元素地址
//	printf ("%p\n", &arr[0]+1);//第一个元素的地址(首地址)
//	printf ("%p\n", &arr+1);//取整个地址 地址的首地址是第一个元素的地址
//	//&arr 取出的是整个数组的地址
//	//sizeof(arr) 取是整个数组
//}


//int main ()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	//数组可以通过指针访问
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf ("%p ==%p\n", p + i, &arr[i]);
//		printf ("%d\n", *(p + i));
//	}
//	return 0;
//}


//int main ()
//{
//	int a = 10;
//	int* pa = &a; //一级指针
//	int** ppa = &pa;//二级指针
//	//int*****...
//	return 0;
//}

//指针数组 - 数组 - 存放指针的数组
//数组指针 - 指针

//int main ()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* p[] = { &a,&b,&c }; //指针数组
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf ( "%d ", * (p[i]) );
//	}
//	return 0;
//}

