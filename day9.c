/*һ.ģ��strcpy*/
#include<string.h>
#include <stdio.h>
#include <assert.h>

//δ�Ż�
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

//�Ż�1
//void my_strcpy ( char* dest, char* src )
//{
//	if (dest != NULL & src != NULL) //��ܿ�ָ��
//	{
//		while (*dest++ = *src++)  //��*src++ = '\0' ʱwhileΪfalseֹͣѭ��
//		{
//			;
//		}
//	}
//}

//�Ż�2
//void my_strcpy ( char* dest, char* src )
//{
//	assert ( dest != NULL );//����
//	assert ( src != NULL );//����
//		while (*dest++ = *src++)  //��*src++ = '\0' ʱwhileΪfalseֹͣѭ��
//		{
//			;
//		}
//}

//�����Ż���
// char* my_strcpy ( char* dest, const char* src )//��*src��Ϊ������
//{
//	 char* ret = dest;
//	assert ( dest != NULL );//����
//	assert ( src != NULL );//����
//	//��srcָ����ַ���������destָ��Ŀռ�,����'\0'
//	//��*src++ = '\0' ʱwhileΪfalseֹͣѭ��
//	while (*dest++ = *src++){;}  
//	return ret;//����dest-��ʽ����
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

/*��.Strlenģ��*/
//int my_strlen ( const char* str )
//{
//	int count = 0;
//	assert ( str != NULL );//��ָ֤����Ч��
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