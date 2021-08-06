/*一.模拟strcpy*/
#include<string.h>
#include <stdio.h>
#include <assert.h>

//未优化
//void my_strcpy ( char* dest, char* src )
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}

//优化1
//void my_strcpy ( char* dest, char* src )
//{
//	if (dest != NULL & src != NULL) //规避空指针
//	{
//		while (*dest++ = *src++)  //当*src++ = '\0' 时while为false停止循环
//		{
//			;
//		}
//	}
//}

//优化2
//void my_strcpy ( char* dest, char* src )
//{
//	assert ( dest != NULL );//断言
//	assert ( src != NULL );//断言
//		while (*dest++ = *src++)  //当*src++ = '\0' 时while为false停止循环
//		{
//			;
//		}
//}

//最终优化版
// char* my_strcpy ( char* dest, const char* src )//将*src变为常变量
//{
//	 char* ret = dest;
//	assert ( dest != NULL );//断言
//	assert ( src != NULL );//断言
//	//把src指向的字符串拷贝到dest指向的空间,包含'\0'
//	//当*src++ = '\0' 时while为false停止循环
//	while (*dest++ = *src++){;}  
//	return ret;//返回dest-链式访问
//}
//
//int main ()
//{
//	char arr1[] = "#############";
//	char arr2[] = "HelloWorld";
//	my_strcpy ( arr1, arr2);
//	printf ( "%s\n", arr1 );
//	return 0;
//}

/*二.Strlen模拟*/
//int my_strlen ( const char* str )
//{
//	int count = 0;
//	assert ( str != NULL );//保证指针有效性
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main ()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen ( arr );
//	return 0;
//}