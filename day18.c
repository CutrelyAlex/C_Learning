/*
文件的随机读写
*/
#include<stdlib.h>
#include<stdio.h>


//fseek(FILE*stream,long offset,int origin)
//在文件指针初始位置origin移动pf文件指针以偏移量offset
//origin选择
//SEEK_CUR当前位置
//SEEK_END文件末尾
//SEEK_SET文件起始位置
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
//返回文件指针相对起始位置偏移量
//rewind
//让文件指针回到文件起始位置
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

//feof() 判断是读取失败结束还是遇到文件尾结束
//不能将feof()用于判断文件是否结束
//而应当用以下方式
//文件读取是否结束，判断返回值是否为EOF或NULL
//二进制文件结束判断,判断返回值是否小于实际要读的个数
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



