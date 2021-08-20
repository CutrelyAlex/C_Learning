/*
动态内存管理
柔性数组
(C99)
*/
//#include<stdio.h>
//#include<memory.h>
//#include<stdlib.h>
//struct S
//{
//	int n;
//	int barr[0];//未知大小-柔性数组成员,数组大小是可调的
//};
//int main ()
//{
//	struct S s;
//	printf ( "%d", sizeof ( s ) );
//	struct S *ps = malloc ( sizeof ( struct S ) + 5 * sizeof ( int ) );
//	//其中5*代表5个整形
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->barr[i] = i;
//	}
//	struct S * ptr = realloc ( ps, 44 );
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->barr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf ( "%d", ps->barr[i] );
//	}
//	free ( ps );
//	ps = NULL;
//	return 0;
//}
//
//


//替代方法
//#include<stdlib.h>
//#include<stdio.h>
//struct S
//{
//	int n;
//	int* arr;
//};
//int main ()
//{
//	struct S *ps = (struct S*)malloc ( sizeof ( struct S ) );
//	ps->arr = malloc ( 5 * sizeof ( int ) );
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf ( "%d", ps->arr[i] );
//	}
//	int *ptr = realloc ( ps->arr, 10 * sizeof ( int ) );
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	//...
//	free ( ps->arr );
//	ps = NULL;
//	free ( ptr );
//	ptr = NULL;
//}




//替代方法和柔性数组有什么区别?
/*
两种方案都能调整数组大小
对于替代方案malloc两次对应两次free,并且有释放先后的问题
柔性数组方案只使用一次malloc,更安全

替代方案相对柔性数组制造更多内存碎片，内存利用率没有柔性数组高

柔性数组的内存是连续的，访问效率更高(在寄存器中连续)
*/
