/*字符串函数2
*/
#include <string.h>
#include<stdio.h>
#include<assert.h>
//strncpy
//char* strncpy(char*dest,const char*src,size_t num)
//从src拷贝num个字符到dest
//如果src长度小于num,则在dest后追加0,直到num个

//strncat(dest,src,num)
//从src追加num个字符到dest

//int main ()
//{
//	const char *p1 = "abcd";
//	const char *p2 = "abcqwer";
//	int ret = strncmp ( p1, p2 ,3);
//	printf ( "%d\n", ret );//返回0 说明源字符串和目标前3个字符时相等
//}


//strstr()
//查找字符串
//char *strstr(const char* string,const char* strCharset)
//string:字符串
//strcharset:要查的字符串
//模拟实现（可读性较差,仅供语法理解,实际实现需增强可读性）：
//char *my_strstr ( const char *p1, const char *p2 )
//{
//	assert ( p1&& p2);
//	char *s1 ,*s2 ;
//	if (!*p2) return (char*)p1;
//	while (*(++p1))
//	{
//		s1 = (char*)p1;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && !((*(++s1)) - *(++s2)));
//		if (!*s2) return (char*)p1;
//	}
//	return NULL;
//}
//
//int main ()
//{
//	const char *p1 = "aabbbccddd";
//	const char *p2 = "bbbcf";
//	char* ret = my_strstr ( p1, p2 );
//	if (ret == NULL)
//	{
//		printf ( "字符串不存在" );
//	}
//	else
//	{
//		printf ( "%s\n", ret );
//	}
//	return 0;
//}


//strtok()
//char * strtok ( char *str, const char* sep )
//sep中存储标记
//找到str中的下一个标记,并将其用\0结尾,返回一个指向这个标记的指针
//第一个参数不为NULL,则找到并保存标记在字符串种的位置
//第一个参数为NULL,则从同一字符串被保存位置开始,查找下一个标记
//例如
//有字符串"192.168.31.121"或"zpw@bi.tec"
//可处理为"192 168 31 121","zpw bit tec"

//int main ()
//{
//	char arr[] = "zpw@gm.com";
//	const char *p = "@.";
//	char buf[1024] = { 0 };
//	strcpy ( buf, arr );
//	char* ret = NULL;
//	for (ret = strtok ( arr, p ); ret != NULL;ret=strtok(NULL,p))
//	{
//		printf ( "%s ", ret );
//	}
//	return 0;
//}

//#include<errno.h>
////strerror
////返回错误码
////char* strerror(int)
//int main ()
//{
//	char *str = strerror ( 0 );
//	printf ( "%s\n", str );
//	printf ( "%s\n", strerror ( 1 ) );
//	printf ( "%s\n", strerror (35) );
//	//errno 全局错误码变量
//	//当C语言库函数执行种发生错误就会把错误码赋值到errno种
//	char *str = strerror ( errno );
//
//	//例用途
//	FILE *pf = fopen ( "test.txt", "r" );
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno))
//	}
//	else
//	{
//		;
//	}
//}

#include <ctype.h>
/*字符分类函数*/
//iscntrl 任何控制字符
//isspace 任何空白字符
//isdigit 十进制数字
//isxdigit 十六进制数字
//islower 小写字母a-z
//isupper 大写字母A~Z
//isalpha a-z和A-Z
//isalnum a-z和A-Z和0-9
//ispunct 任何不属于数字或字母的圆形字符
//isgraph 任何圆形字符
//isprint 任何可打印字符（包括圆形字符和空白字符）
//int main ()
//{
//	isgraph ( 'w' );
//}


//int main ()
//{
//	char ch = 'w';
//	int ret = islower ( ch );
//	printf ( "%d\n", ret );
//	return 0;
//}



//字符转换函数
//int tolower(int c) 转小写
//int toupper(int c) 转大写
//char ch = toupper('q');
//(ch变为'Q')



