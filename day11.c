/*
ָ�����.
*/

/*
���ٻع�
ָ���Ǹ�����,��ŵ�ַ
ָ��̶���С(4/8�ֽ�)
ָ����������,ָ�����;���ָ�벽����������ʱ��Ȩ��.
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
/*һ,�ַ�ָ��*/

//int main ()
//{
//	char arr[] = "abced";
//	char* pc = arr;
//	printf ( "%s\n", arr );
//	printf ( "%s\n", pc );//��ӡ�����ͬ(arr,pc������Ԫ�ص�ַ)
//	char* p = "abcdef";//"abcdef"��һ�������ַ��� ��˼�ǰ�a�ĵ�ַ��ֵ��p
//	printf ( "%c\n", *p );
//	printf ( "%s\n", p );
//
//	//char* ps = "abcdef";
//	//*ps = 'W';
//	//printf ( "%s\n", ps );  ����д��
//
//	const char* pw = "abcdef" //��ȷд��;
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
//	//ִ������1,ԭ��:abcdef�ǳ����ַ���
//	//p1,p2ָ�����ַ��������޸�
//}


/*ָ������*/
//����,���ָ��
//
//int* parr[4]; //�������ָ�������
//char*  pch[5];//����ַ�ָ�������
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

/*����ָ��*/
//ָ�� ָ������
//
//int main ()
//{
//	int arr[10] = { 0 };
//	//arr -��Ԫ�ص�ַ
//	//&arr - ����ĵ�ַ
//	//&arr[0] -��Ԫ�صĵ�ַ
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

/*������� ָ�����*/
//һά����
//void test{int arr[]}  --ok
//void test{int arr[10]} --ok
//void test(int *arr) --ok
//---
//void test2(int *arr[20]) --ok
//void test2(int **arr)  --ok

//��ά����
//void test(int arr[3][5])  --ok
//void test(int arr[][5])  --ok
//void test(int arr[3][])  --NO,�ڶ����±겻��ʡ��

//void test(int *arr) --NO,��ά�������Ԫ�ص�ַ��һά�����ַ
//void test(int **arr) --NO,�����ַ���ܴ���ڶ���ָ��
//void test(int (*arr)[5])--ok

//ָ�봫��
//void test(int *p)
//test �ܴ�int���͵ĵ�ַ��һ��ָ�룬һά����

//����ָ�봫��
//void test(int** ptr)
//test �ܴ�һ��ָ��ĵ�ַ ����ָ�� ָ������

//-------------
/*����ָ��*/
//ָ������ָ��
//int test (int x,int y)
//{
//	return x + y;
//}
//int main ()
//{
//	test ( 2, 3 );
//	printf ( "%p\n", &test );
//	printf ( "%p\n", test );
//	//&������,�ͺ��������Ǻ����ĵ�ַ
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
////дһ������ָ��,ָ��my_string
//char* (*pms)(char*, const char*) = my_string;
////дһ������ָ������,���4��my_string
//char* (*pfArr[4])(char*, const char*);
//}

//
//����:������-----ת�Ʊ�
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

/*ָ����ָ�������ָ��*/
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
//	//ppfArr��һ������ָ��,ָ��ָ��������4��Ԫ��
//	//ָ��������ÿ��Ԫ��������ָ��
//	//ָ��ָ��һ������ ��������������int,������(int,int)
//	return 0;
//}
//



