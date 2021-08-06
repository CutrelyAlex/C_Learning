#include <stdio.h>
#include <stdlib.h>
/*
调试
C语言初学
By D菌
*/

/*
最终编译的程序:

Debug（调试）版本的可执行程序:
可以调式的，文件中包含了调试信息
并且不作任何优化。

Release（发布）版本的可执行程序:
不含调试信息，但经过运行速度和代码优化，以便于用户使用。

*/



//Release版本会对代码进行优化

//int main ()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	for (i = 0; i < 12; i++)
//	{
//		printf ( "hi\n" );
//		arr[i] = 0;
//	}
//	system ( "pause" );
//	return 0;
//}


/*
F5 -- 启动调试-执行到断点处，跳到执行逻辑的下一个断点。
F9 -- 切换断点
F5和F9配合使用
断点:代码执行停在断点处
F10:逐过程
F11:逐语句
*/

//int main ()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		printf ( "%d\n", i );
//	}
//	for (i = 0; i < 100; i++)
//	{
//		printf ( "%d\n", 10 - i );
//	}
//	system ( "pause" );
//	return 0;
//}
//F10:一个过程是一次函数调用 或者一条语句.
//F11:每次执行一条语句,可以使执行逻辑进入函数内部.
//int Add ( int* x, int* y )
//{
//	return *x + *y;
//}
//int main ()
//{
//	int a = 20;
//	int b = 10;
//	int ans = Add ( &a, &b );
//	printf ( "%d", ans );
//	return 0;
//}


/*
调试-窗口
调用堆栈

*/