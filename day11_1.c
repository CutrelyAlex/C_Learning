/*回调函数*/
//Calc(Add);
//->
//Calc ( int ( *pf )(int, int) ) 
//{
//	int x = 0, y = 0;
//	//...
//	printf("%d",pf(x,y))
//}
//

//qsort - 可以排序任意类型的数据
//qsort - 库函数 -排序
//快速排序
//void qsort(void *base,
//                  size_t num,size_t width
//                 ,int(*cmp)(const void *e1,const voide *e2)
//);
//#include <stdlib.h>
//int cmp_int ( const void *e1, const void *e2 )
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int cmp_float ( const void*e1, const void *e2 )
//{
//	return *(float*)e1 - *(float*)e2;
//}
//int mian ()
//{
//	int arr[] = { 1,3,5,6,9,2,5,7,9,0 };
//	int sz = sizeof ( arr ) / sizeof ( arr[0] );
//	qsort ( arr, sz, sizeof (arr[0]), cmp_int);
//}


//模拟qsort利用回调函数实现bubblesort
void Swap ( char* buf1, char* buf2 ,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}

}
void bubble_sort ( void* base, int sz, int width,int (*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1-i; j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				Swap ( (char*)base + j * width, (char*)base + (j + 1)*width ,width);
			}
		}
	}
}
