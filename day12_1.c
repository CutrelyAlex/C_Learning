/*�ַ�������2
*/
#include <string.h>
#include<stdio.h>
#include<assert.h>
//strncpy
//char* strncpy(char*dest,const char*src,size_t num)
//��src����num���ַ���dest
//���src����С��num,����dest��׷��0,ֱ��num��

//strncat(dest,src,num)
//��src׷��num���ַ���dest

//int main ()
//{
//	const char *p1 = "abcd";
//	const char *p2 = "abcqwer";
//	int ret = strncmp ( p1, p2 ,3);
//	printf ( "%d\n", ret );//����0 ˵��Դ�ַ�����Ŀ��ǰ3���ַ�ʱ���
//}


//strstr()
//�����ַ���
//char *strstr(const char* string,const char* strCharset)
//string:�ַ���
//strcharset:Ҫ����ַ���
//ģ��ʵ�֣��ɶ��Խϲ�,�����﷨���,ʵ��ʵ������ǿ�ɶ��ԣ���
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
//		printf ( "�ַ���������" );
//	}
//	else
//	{
//		printf ( "%s\n", ret );
//	}
//	return 0;
//}


//strtok()
//char * strtok ( char *str, const char* sep )
//sep�д洢���
//�ҵ�str�е���һ�����,��������\0��β,����һ��ָ�������ǵ�ָ��
//��һ��������ΪNULL,���ҵ������������ַ����ֵ�λ��
//��һ������ΪNULL,���ͬһ�ַ���������λ�ÿ�ʼ,������һ�����
//����
//���ַ���"192.168.31.121"��"zpw@bi.tec"
//�ɴ���Ϊ"192 168 31 121","zpw bit tec"

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
////���ش�����
////char* strerror(int)
//int main ()
//{
//	char *str = strerror ( 0 );
//	printf ( "%s\n", str );
//	printf ( "%s\n", strerror ( 1 ) );
//	printf ( "%s\n", strerror (35) );
//	//errno ȫ�ִ��������
//	//��C���Կ⺯��ִ���ַ�������ͻ�Ѵ����븳ֵ��errno��
//	char *str = strerror ( errno );
//
//	//����;
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
/*�ַ����ຯ��*/
//iscntrl �κο����ַ�
//isspace �κοհ��ַ�
//isdigit ʮ��������
//isxdigit ʮ����������
//islower Сд��ĸa-z
//isupper ��д��ĸA~Z
//isalpha a-z��A-Z
//isalnum a-z��A-Z��0-9
//ispunct �κβ��������ֻ���ĸ��Բ���ַ�
//isgraph �κ�Բ���ַ�
//isprint �κοɴ�ӡ�ַ�������Բ���ַ��Ϳհ��ַ���
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



//�ַ�ת������
//int tolower(int c) תСд
//int toupper(int c) ת��д
//char ch = toupper('q');
//(ch��Ϊ'Q')



