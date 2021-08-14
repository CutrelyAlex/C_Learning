/*
自定义类型-
结构体
结构是一些值的集合，每个成员可以是不同类型的变量
*/

//struct Student
//{
//	//成员变量
//	char name[20];
//	char tale[12];
//	char sex[10];
//	char id[20];
//}stu4,a[20],*p;//全局结构体变量
//
//
////匿名结构体类型
////不要出现2个类型完全一致的匿名结构体
//struct
//{
//	int a;
//}x;//需要在变量列表创建变量
//
//
////全局结构体变量
//struct Student stu3;
//
//int main ()
//{
//	//局部结构体变量
//	struct Student stu1;
//	struct Student stu2;
//}

/*结构体自引用*/

/*数据结构:数据在内存种存储的结构*/
/*链表数据结构*/
//一个结点1
//可以找到结点1->结点2->...
//
//struct Node
//{
//	int data;
//	//struct Node n;//注意结构体不能包含自身结构体来存放下一个结点,原因:无法知道开辟多大内存
//	struct Node* next; //正确,存放下一个结点的地址
//};

////typedef运用
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;

//#include<stdio.h>
/*结构体变量的定义和初始化*/
//struct Stu
//{
//	char name[20];
//	double money;
//	int id;
//};
//int main ()
//{
//	//初始化
//	struct Stu s1 = { "Alex",3.14,1001 };
//	//使用
//	printf ( "%s %lf %d", s1.name, s1.money, s1.id );
//	return 0;
//}


#include<stdio.h>
/*结构体内存对齐*/
//重点.

//struct St
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct Sd
//{
//	char c1;
//	char c2;
//	int a;
//};
/*
原因:
创建s1变量时,设从内存p开始存放
则第一个成员变量char存放在(偏移量为0)p+0处
占1个字节
其他成员变量对齐到某个对齐数的整数倍的地址处
(对齐数为 编译器默认的一个对齐数 与 该成员变量大小  的较小值)
VS的默认对齐数为8
gcc-没有默认对齐数，即成员大小就是对齐数
int a; a占4个字节 4和8:4较小，对齐数为4
所以成员a存放在p+4处,大小为4个字节(到p+8)

char c2: c2占1个字节  1和8:1较小,对齐数为1
所以c2存放在(p+8)+1处,大小为1个字节

(结构的总大小为最大对齐数的整数倍)
最大对齐数为4,(目前占内存)9不是4的倍数
9一直加直到为4的倍数(即12)

所以结构体一共占12个字节
*/
//int main()
//{
//	int a = 0;
//	struct St s1 = { 0 };
//	printf ("%d\n",sizeof(s1));
//	struct Sd s2 = { 0 };
//	printf ( "%d\n", sizeof ( s2 ) );
//	//打印结果是12 8
//	return 0;
//}
/*
嵌套结构体
对齐到自己结构体里的最大整数倍处
*/
//例:
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct s4
//{
//	char c1;
//	struct S3 s3;
//	double dd;
//};
/*
首先偏移量为0,放下第一个数据c1,占1个字节
S3中最大对齐数为8(double d)
所以现在s3要对齐到对齐数为8的位置
1加到8（1+7）时候为8的整数倍
所以空出7个字节，偏移量为8
然后再放入16字节结构体数据(已知结构体S3占16字节)
目前偏移量为8+16=24
24恰好为double类型8的倍数
所以直接放入8个字节double dd的数据
目前一共24+8=32字节
而结构体S4中的最大对齐数是8
32恰好是8的倍数
所以偏移0字节
最终，结构体大小为32字节
*/


/*为什么要内存对齐?*/
/*
平台原因:某些硬件平台智能在某些地址取某些特定类型数据
性能:数据结构(尤其是栈)应该在自然边界上对齐
未对齐的内存需要作2次内存访问，对齐的内存只需要1次

总体来说:内存对齐是拿空间换取时间
*/

//设置默认对齐位为4
//#pragma pack(4)
//
//struct S
//{
//	char c1;//1
//	//7
//	double d;//8
//	//8
//};
//
////取消设置
//#pragma pack()

#include<stddef.h>
/*
offsetof宏
结构体成员相对于结构体的偏移量
*/
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//int main ()
//{
//	printf ( "%d", offsetof ( struct S, c ) );
//	printf ( "%d", offsetof ( struct S, i ) );
//	printf ( "%d", offsetof ( struct S, d ) );
//	return 0;
//}