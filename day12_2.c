/*内存函数*/
#include <stdio.h>
#include<memory.h>
#include<assert.h>
//void* memcpy(void* dest,const void* src ,size_t num)
//内存拷贝函数
//从src拷贝num个字节的数据到dest
//遇到Nul不会停止
//整形数组，结构体数组等都可以拷贝
//void* my_memcpy ( void *dest, const void *src, size_t num );
////int main ()
////{
////	int arr[] = { 1,2,3,4,5 };
////	int arr2[5] = { 0 };
////	my_memcpy ( arr2, arr, sizeof(arr));
////}
//////模拟实现:
//void* my_memcpy (void *dest,const void *src,size_t num)
//{
//	assert ( dest != NULL && src != NULL );
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//}
//
//int main ()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	memcpy ( arr + 2, arr, 20 );
//	//源头和目的地空间重叠，结果可能错误
//}

//memmove
//内存移动
//int main ()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	memmove ( arr + 2, arr, 20 );
//	//源头和目的地空间重叠，使用memmove可以避免my_memcpy的现象
//	//注意:VS编译器下memcpy支持处理内存重叠现象，即memcpy等价memmove
//}
//模拟:
//void * my_memmove ( void* dest, const void* src, size_t count )
//{
//	void* ret = dest;
//	assert ( dest != NULL && src != NULL );
//	if (dest < src || dest>(char*)src+count)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			((char*)dest)++;
//			((char*)src)++;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src+count);
//		}
//	}
//	return ret;
//}

#include<stdio.h>
#include<memory.h>
//memcmp
//内存比较
//int main ()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,4,3,5 };
//	int ret = memcmp ( arr1, arr2, 8 );
//	printf ( "%d", ret );
//	return 0;
//}

//memset
//修改字节
int main ()
{
	char arr[10] = "";
	memset ( arr, '#', 10 );

	int arr[10] = { 0 };
	memset ( arr, 1, 10 );//错误(不能讲元素设置为10个1)单位为字节
	//01 01 01 01 01 01 01 01 01 01 00 00 00 .....
}