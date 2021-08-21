/*文件操作*/
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
fopen打开文件(文件相对路径,模式)  返回文件指针
fclose 关闭文件
*/
//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main ()
//{
//	//打开文件(当前路径,模式)
//	//..当前路径的上级路径
//	//.表示当前路径
//	FILE *pf = fopen ( "test.txt", "w" );
//	if (pf == NULL)
//	{
//		printf ( "%s\n", strerror (errno) );
//		return 0;
//	}
//	fclose ( pf );
//
//}

//写文件fputc
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


//读文件并fgetc
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


//标准输出/输入流
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
//	fgets ( p, 1024, pf ); //读pf 一行 长度为1024 到buf
//	fputs(  p ,stdout);
//	fgets ( p, 1024, pf );
//	fputs ( p,stdout );
//	fclose ( pf );
//	free ( p );
//	pf = NULL;
//	p = NULL;
//	return 0;
//}

//fputs写文件
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

////fgets fputs从键盘读取一行文本信息
//int main ()
//{
//	char *p = malloc ( sizeof ( char ) * 1024 );
//	fgets ( p, 1024, stdin );
//	fputs ( p, stdout );
//	//等价于gets() puts()
//	free ( p );
//	p = NULL;
//	return 0;
//}

//格式化输出输入
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
//	//写
//	//fprintf ( pf, "%d %f %s", s.n, s.score, s.arr );
//	//fclose ( pf );
//	//pf = NULL;
//	//读
//	FILE* pw = fopen ( "test.txt", "r" );
//	fscanf ( pw, "%d %f %s",&(s.n),&(s.score),&(s.arr)  );
//	printf ( "%d %f %s", s.n, s.score, s.arr );
//	fclose ( pw );
//	return 0;
//}



/*
对比
scanf/printf 针对标准IO流的格式化IO语句
fscanf/fprintf 针对所有IO流的格式化IO语句
sscanf/sprintf 字符串读写
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
//	//写
//	sprintf ( buff, "%d %f %s", s.n, s.score, s.arr );
//	printf ( "%s\n", buff );
//	//读
//	sscanf ( buff, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr) );
//	printf ( "%d %f %s\n", tmp.n, tmp.score, tmp.arr );
//	return 0;
//}

//二进制读写
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
//	//写
//	//fwrite ( &s, sizeof ( struct S ), 1 );
//	//fclose ( fp );
//	//读
//	fread ( &tmp, sizeof ( struct S ), 1,fp );
//	fclose ( fp );
//	fp = NULL;
//	return 0;
//}

