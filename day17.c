/*�ļ�����*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//
//#include <stdio.h>
//int main ()
//{
//	int a = 10000;
//	FILE* pf = fopen ( "text.txt", "wb" );
//	fwrite ( &a, 4, 1, pf );
//	fclose ( pf );
//	pf = NULL;
//	return 0;
//}

/*
fopen���ļ�(�ļ����·��,ģʽ)  �����ļ�ָ��
fclose �ر��ļ�
*/
//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main ()
//{
//	//���ļ�(��ǰ·��,ģʽ)
//	//..��ǰ·�����ϼ�·��
//	//.��ʾ��ǰ·��
//	FILE *pf = fopen ( "test.txt", "w" );
//	if (pf == NULL)
//	{
//		printf ( "%s\n", strerror (errno) );
//		return 0;
//	}
//	fclose ( pf );
//
//}

//д�ļ�fputc
//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
//int main ()
//{
//	FILE* pfWrite = fopen ( "test.txt", "w" );
//	if (pfWrite == NULL)
//	{
//		printf ( "%s", strerror ( errno ) );
//		return 0;
//	}
//	fputc ( 'H', pfWrite );
//	fputc ( 'e', pfWrite );
//	fputc ( 'l', pfWrite );
//	fputc ( 'l', pfWrite );
//	fputc ( 'o', pfWrite );
//	fclose ( pfWrite );
//	pfWrite = NULL;
//	return 0;
//}


//���ļ���fgetc
//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
//int main ()
//{
//	FILE* pfRead = fopen ( "test.txt", "r" );
//	if (pfRead == NULL)
//	{
//		printf ( "%s", strerror ( errno ) );
//		return 0;
//	}
//	printf ( "%c", fgetc ( pfRead ) );
//	fclose ( pfRead );
//	pfRead = NULL;
//	return 0;
//}


//��׼���/������
//int main ()
//{
//	int ch = fgetc ( stdin );
//	fputc ( ch,stdout );
//	return 0;
//}
//

//fgets fputs
//int main ()
//{
//	char* p = malloc ( 1024 * sizeof ( char ) );
//	FILE* pf = fopen ( "test.txt", "r" );
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fgets ( p, 1024, pf ); //��pf һ�� ����Ϊ1024 ��buf
//	fputs(  p ,stdout);
//	fgets ( p, 1024, pf );
//	fputs ( p,stdout );
//	fclose ( pf );
//	free ( p );
//	pf = NULL;
//	p = NULL;
//	return 0;
//}

//fputsд�ļ�
//int main ()
//{
//	FILE* pf = fopen ( "test.txt", "w" );
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fputs ( "this\n", pf );
//	fputs ( "is\n", pf );
//	fclose ( pf );
//	pf = NULL;
//	return 0;
//}

////fgets fputs�Ӽ��̶�ȡһ���ı���Ϣ
//int main ()
//{
//	char *p = malloc ( sizeof ( char ) * 1024 );
//	fgets ( p, 1024, stdin );
//	fputs ( p, stdout );
//	//�ȼ���gets() puts()
//	free ( p );
//	p = NULL;
//	return 0;
//}

//��ʽ���������
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main ()
//{
//	struct S s = { 100,3.14f,"bit" };
//	//FILE* pf = fopen ( "test.txt", "w" );
//	//if (pf == NULL)
//	//{
//	//	return 0;
//	//}
//	//д
//	//fprintf ( pf, "%d %f %s", s.n, s.score, s.arr );
//	//fclose ( pf );
//	//pf = NULL;
//	//��
//	FILE* pw = fopen ( "test.txt", "r" );
//	fscanf ( pw, "%d %f %s",&(s.n),&(s.score),&(s.arr)  );
//	printf ( "%d %f %s", s.n, s.score, s.arr );
//	fclose ( pw );
//	return 0;
//}



/*
�Ա�
scanf/printf ��Ա�׼IO���ĸ�ʽ��IO���
fscanf/fprintf �������IO���ĸ�ʽ��IO���
sscanf/sprintf �ַ�����д
*/

//sscanf/sprintf
//struct S
//{
//	int n;
//	float score;
//	char arr[11];
//};
//int main ()
//{
//	struct S s = { 1024,3.14,"helloworld" };
//	struct S tmp = { 0 };
//	char buff[1024] = { 0 };
//	//д
//	sprintf ( buff, "%d %f %s", s.n, s.score, s.arr );
//	printf ( "%s\n", buff );
//	//��
//	sscanf ( buff, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr) );
//	printf ( "%d %f %s\n", tmp.n, tmp.score, tmp.arr );
//	return 0;
//}

//�����ƶ�д
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main ()
//{
//	//struct S s = { "Alex",200,10 };
//	struct S tmp = { 0 };
//	FILE* fp = fopen ( "test.txt", "rb" );
//	if (fp == NULL)
//	{
//		return 0;
//	}
//	//д
//	//fwrite ( &s, sizeof ( struct S ), 1 );
//	//fclose ( fp );
//	//��
//	fread ( &tmp, sizeof ( struct S ), 1,fp );
//	fclose ( fp );
//	fp = NULL;
//	return 0;
//}

