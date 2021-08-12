/*
字符串函数
*/
#include <stdio.h>
#include<string.h>
#include<assert.h>

/*
strlen()
计算字符串长度
遇到\0停止,返回'\0'前出现字符的数字

*/
size_t my_strlen ( const char* str );
size_t my_strlen2 ( const char* str );
void test ();
int main ()
{
	//错误:
	//char arr[] = {'a','b','c'};
	//int len = strlen ( arr );
	int len = strlen ( "abcdef" );
	printf ( "%d\n", len );
	test ();
	return 0;
}

//模拟strlen:计数器法
size_t my_strlen ( const char* str )
{
	int count = 0;
	assert ( str != NULL );//断言，防止空指针传入
	while (*str != '\0')//等价while(*str)
	{
		count++;
		str++;
	}
	return count;
}

//模拟strlen:指针
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

//模拟strlen:递归(略)


//size_t 等价 unsighed int 
//输出hehe 因为返回无符号数size_t
//如果强转int则输出haha.
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
//将arr2拷贝到arr1,包括'\0'
//模拟:
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
//注意:源字符串要包含'\0'，否则可能出现越界访问
//目标空间要足够大，能存放源字符串
//目标空间可更改 错误示范:char *dest = "abcedef"
void test2 ()
{
	char arr1[] = "abcdef";
	char arr2[] = "bit";
	strcpy ( arr1, arr2 );
}


//strcat()
//在目标字符串的'\0'追加源字符串
void test3 ()
{
	//错误:目标空间不够大,越界访问
	//char dest[] = "hello";
	//char src[] = "world";
	//strcat(arr1,arr2);
	char dest[30] = "hello";
	char src[] = "world";
	strcat ( dest, src );
}

//模拟strcat():
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
//比较每对字符的ASCII值
//存在不相等就返回非0
//都相等就返回0
int main ()
{
	char* p1 = "abcdef";
	char* p2 = "sqwer";
	int ret = strcmp ( p1, p2 );
	printf ( "%d\n", ret );
}

