/*
�ַ�������
*/
#include <stdio.h>
#include<string.h>
#include<assert.h>

/*
strlen()
�����ַ�������
����\0ֹͣ,����'\0'ǰ�����ַ�������

*/
size_t my_strlen ( const char* str );
size_t my_strlen2 ( const char* str );
void test ();
int main ()
{
	//����:
	//char arr[] = {'a','b','c'};
	//int len = strlen ( arr );
	int len = strlen ( "abcdef" );
	printf ( "%d\n", len );
	test ();
	return 0;
}

//ģ��strlen:��������
size_t my_strlen ( const char* str )
{
	int count = 0;
	assert ( str != NULL );//���ԣ���ֹ��ָ�봫��
	while (*str != '\0')//�ȼ�while(*str)
	{
		count++;
		str++;
	}
	return count;
}

//ģ��strlen:ָ��
size_t my_strlen2 ( const char* str )
{
	const char *ret = NULL;
	assert ( str );
	ret = str;
	while (*ret != '\0')
	{
		ret++
	}
	return ret - str;
}

//ģ��strlen:�ݹ�(��)


//size_t �ȼ� unsighed int 
//���hehe ��Ϊ�����޷�����size_t
//���ǿתint�����haha.
void test1 ()
{
	if (/*(int)*/strlen ( "abc" ) - /*(int)*/strlen ( "abcdef" ) > 0)
	{
		printf ( "hehe" );
	}
	else
	{
		printf ( "haha" );
	}
}

//strcpy()
//��arr2������arr1,����'\0'
//ģ��:
char* my_strcpy ( char *dest, const char *src )
{
	assert ( dest != NULL );
	assert ( src != NULL );
	char *ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
//ע��:Դ�ַ���Ҫ����'\0'��������ܳ���Խ�����
//Ŀ��ռ�Ҫ�㹻���ܴ��Դ�ַ���
//Ŀ��ռ�ɸ��� ����ʾ��:char *dest = "abcedef"
void test2 ()
{
	char arr1[] = "abcdef";
	char arr2[] = "bit";
	strcpy ( arr1, arr2 );
}


//strcat()
//��Ŀ���ַ�����'\0'׷��Դ�ַ���
void test3 ()
{
	//����:Ŀ��ռ䲻����,Խ�����
	//char dest[] = "hello";
	//char src[] = "world";
	//strcat(arr1,arr2);
	char dest[30] = "hello";
	char src[] = "world";
	strcat ( dest, src );
}

//ģ��strcat():
char* my_strcat ( char*dest, const char*src )
{
	char* ret = dest;
	assert ( dest != NULL && src != NULL );
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//strcmp()
//�Ƚ�ÿ���ַ���ASCIIֵ
//���ڲ���Ⱦͷ��ط�0
//����Ⱦͷ���0
int main ()
{
	char* p1 = "abcdef";
	char* p2 = "sqwer";
	int ret = strcmp ( p1, p2 );
	printf ( "%d\n", ret );
}

