/*
��̬�ڴ����
��������
(C99)
*/
//#include<stdio.h>
//#include<memory.h>
//#include<stdlib.h>
//struct S
//{
//	int n;
//	int barr[0];//δ֪��С-���������Ա,�����С�ǿɵ���
//};
//int main ()
//{
//	struct S s;
//	printf ( "%d", sizeof ( s ) );
//	struct S *ps = malloc ( sizeof ( struct S ) + 5 * sizeof ( int ) );
//	//����5*����5������
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->barr[i] = i;
//	}
//	struct S * ptr = realloc ( ps, 44 );
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->barr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf ( "%d", ps->barr[i] );
//	}
//	free ( ps );
//	ps = NULL;
//	return 0;
//}
//
//


//�������
//#include<stdlib.h>
//#include<stdio.h>
//struct S
//{
//	int n;
//	int* arr;
//};
//int main ()
//{
//	struct S *ps = (struct S*)malloc ( sizeof ( struct S ) );
//	ps->arr = malloc ( 5 * sizeof ( int ) );
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf ( "%d", ps->arr[i] );
//	}
//	int *ptr = realloc ( ps->arr, 10 * sizeof ( int ) );
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	//...
//	free ( ps->arr );
//	ps = NULL;
//	free ( ptr );
//	ptr = NULL;
//}




//�������������������ʲô����?
/*
���ַ������ܵ��������С
�����������malloc���ζ�Ӧ����free,�������ͷ��Ⱥ������
�������鷽��ֻʹ��һ��malloc,����ȫ

��������������������������ڴ���Ƭ���ڴ�������û�����������

����������ڴ��������ģ�����Ч�ʸ���(�ڼĴ���������)
*/
