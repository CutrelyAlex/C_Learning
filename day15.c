/*��̬�ڴ����*/
/*
��ϰ:
�ֲ����������β�-ջ��
ȫ�ֱ���,��̬����-��̬��
��̬�ڴ� -����
*/
#include <stdlib.h>
#include<errno.h>
#include<string.h>
#include<stdio.h>
#include<assert.h>
//malloc��free
//void* malloc(size_t size);
//size ���ٵ��ֽڸ���
//������ʼ��ַ
//size = 0 ʱ��δ�����
//free�е�p������Ƕ�̬���ٵģ����δ����
//freeһ��NULL��ôʲô��������
//int main ()
//{
//	//����10�����εĿռ�,������ʼ��ַ��int* p
//	int* p = (int*) malloc (10*sizeof(int));
//	//�������ʧ��(�ڴ治��),�ͷ���NULL
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
//	//��̬�������,
//	free (p);
//	//��p��ֵΪNULL,��ֹʹp���Ұָ��
//	p = NULL;
//	return 0;
//}

//calloc����һ�����飬���Ұ���ֵ�ĳ�0
//void* calloc(num,size)
//num��Ԫ�ظ���
//size��Ԫ�ش�С
//realloc ������̬�����ڴ�Ĵ�С
//void* realloc(void* ���ٺõĿռ�,size_t size)
//int main ()
//{
//	//�������ʧ��(�ڴ治��),�ͷ���NULL
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
//	//������̬���ٵ��ڴ� �������¿��ٺõ�ָ��
//	//�������ռ��㹻׷�� ��ֱ��׷��
//	//�������ռ䲻��׷�� ����ֿ����µ�����������ڴ����򣬲��������ͷ�ԭ�����ڴ�
//	//���Է��صĵ�ַ��һ����ԭ���ĵ�ַ
//	//�п��ܿ���ʧ�ܣ��᷵�ؿ�ָ��
//	//���صĵ�ַ��Ҫֱ�Ӹ���ԭָ��
//realloc(NULL,40)��malloc(40)�ȼ�
//	int* ptr =(int*) realloc ( p, 4000 );
//	if (ptr != NULL)
//	{
//		//���ptr���ǿ�ָ��Ű�ptr��ֵ��p
//		p = ptr;
//	}
//	//�ͷ��ڴ�
//	free ( p );
//	//�ÿ�
//	p = NULL;
//	ptr = NULL;
//	return 0;
//}

/*��������*/
//1.û���ж�ָ��ΪNULL���Ͷ�NULL���н�����
//2.�Զ�̬�����ڴ�Խ�����
//3.�ԷǶ�̬���ٵ��ڴ�free
//4.free�ͷŶ�̬�����ڴ��һ����
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
//	free ( p );//p������ԭ����ʼ
//	p = NULL;
//	return 0;
//}

//5.��ͬһ�鶯̬�ڴ����ͷ�
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

//6.�����ͷŶ�̬�ڴ�(�ڴ�й¶)

