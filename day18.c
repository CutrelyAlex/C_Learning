/*
�ļ��������д
*/
#include<stdlib.h>
#include<stdio.h>


//fseek(FILE*stream,long offset,int origin)
//���ļ�ָ���ʼλ��origin�ƶ�pf�ļ�ָ����ƫ����offset
//originѡ��
//SEEK_CUR��ǰλ��
//SEEK_END�ļ�ĩβ
//SEEK_SET�ļ���ʼλ��
//#include<stdlib.h>
//#include<stdio.h>
//int main ()
//{
//	FILE* pf = fopen ( "test.txt", "r" );
//	if (pf == NULL) return 0;
//	fseek ( pf,2, SEEK_END);
//	int ch = fgetc ( pf );
//	printf ( "%c\n", ch );
//	fclose ( pf );
//	pf = NULL;
//	return 0;
//}

//ftell
//�����ļ�ָ�������ʼλ��ƫ����
//rewind
//���ļ�ָ��ص��ļ���ʼλ��
//int main ()
//{
//	FILE* pf = fopen ( "test.txt", "r" );
//	if (pf == NULL) return 0;
//	fseek ( pf, 2, SEEK_CUR );
//	int pos = ftell ( pf );
//	printf ( "%d\n", pos );
//	fclose ( pf );
//	pf = NULL;
//	return 0;
//}

//feof() �ж��Ƕ�ȡʧ�ܽ������������ļ�β����
//���ܽ�feof()�����ж��ļ��Ƿ����
//��Ӧ�������·�ʽ
//�ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF��NULL
//�������ļ������ж�,�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
//int main ()
//{
//	int c;
//	FILE* pf = fopen ( "test.txt", "r");
//	if (pf == NULL)
//	{
//		perror ( "OPEN FILE test.txt" );//perror
//		return EXIT_FAILURE; //-1
//	}
//	while ((c = fgetc ( pf )) != EOF)
//	{
//		putchar ( c );
//	}
//	if (ferror ( pf ))
//		puts ( "\nIO error when reading" );
//	else if (feof ( pf ))
//		puts ("\n--End of file reached successfully--");
//	fclose ( pf );
//	pf = NULL;
//	return 0;
//}
enum
{
	SIZE = 5
};
int main ()
{
	double a[SIZE] = { 1.0,2.0,3.0,4.0,5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen ( "test.bin", "wb" );
	fwrite ( a, sizeof ( *a ), SIZE, fp );
	fclose ( fp );
	fp = fopen ( "test.bin", "rb" );
	while ((ret_code = fread ( &b, sizeof ( double ), 1, fp )) >= 1)
	{
		printf ( "%lf\n",b );
	}
	if (feof ( fp ))
	{
		;//
	}
	else if (ferror ( fp ))
	{
		;//
	}
	return 0;
}



