/*�ڴ溯��*/
#include <stdio.h>
#include<memory.h>
#include<assert.h>
//void* memcpy(void* dest,const void* src ,size_t num)
//�ڴ濽������
//��src����num���ֽڵ����ݵ�dest
//����Nul����ֹͣ
//�������飬�ṹ������ȶ����Կ���
//void* my_memcpy ( void *dest, const void *src, size_t num );
////int main ()
////{
////	int arr[] = { 1,2,3,4,5 };
////	int arr2[5] = { 0 };
////	my_memcpy ( arr2, arr, sizeof(arr));
////}
//////ģ��ʵ��:
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
//	//Դͷ��Ŀ�ĵؿռ��ص���������ܴ���
//}

//memmove
//�ڴ��ƶ�
//int main ()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	memmove ( arr + 2, arr, 20 );
//	//Դͷ��Ŀ�ĵؿռ��ص���ʹ��memmove���Ա���my_memcpy������
//	//ע��:VS��������memcpy֧�ִ����ڴ��ص����󣬼�memcpy�ȼ�memmove
//}
//ģ��:
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
//�ڴ�Ƚ�
//int main ()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,4,3,5 };
//	int ret = memcmp ( arr1, arr2, 8 );
//	printf ( "%d", ret );
//	return 0;
//}

//memset
//�޸��ֽ�
int main ()
{
	char arr[10] = "";
	memset ( arr, '#', 10 );

	int arr[10] = { 0 };
	memset ( arr, 1, 10 );//����(���ܽ�Ԫ������Ϊ10��1)��λΪ�ֽ�
	//01 01 01 01 01 01 01 01 01 01 00 00 00 .....
}