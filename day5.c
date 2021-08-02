#include <stdio.h>
#include <string.h>
//void sp_print (int x)
//{
//	if (x > 9)
//	{
//		sp_print (x / 10);
//	}
//	printf ("%d ", x%10);
//}
//int main ()
//{
//	unsigned int n = 0;
//	scanf ("%d", &n);
//	sp_print(n);
//	return 0;
//}
//int my_strlen (char* str)
//{
//	int cou = 0;
//	if (*str != '\0')
//	{
//		cou++;
//		str++;
//	}
//	return count;
//}
//int my_strlen (const char* str)
//{
//	if (*str != '\0')
//		return	1 + my_strlen (str + 1);
//	else
//		return 0;
//}
//int main ()
//{
//	char word[50];
//	scanf ("%s", &word);
//	int len = my_strlen (&word);
//	printf ("%d", len);
//	return 0;
//}
//int Facl (int n)
//{
//	if (n > 1)
//		n =	n*Facl (n - 1);
//	else
//		return n;
//}
//int main ()
//{
//	int n = 0;
//	scanf ("%d",&n);
//	int ret = Facl (n);
//	printf ("%d", ret);
//	return 0;
//}

void sort (int *arr, int sz)
{
	int i,j,tmp;
	j = 0;
	for (i = 0; i < sz-1; i++)
	{
		int flag = 1;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag=0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int main ()
{
	int arr[40] = { 0 };
	int n = 0;
	scanf ("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &arr[i]);
	}
	sort (arr, n);
	for (i = 0; i < 5; i++)
	{
		printf ("%d ", arr[i]);
	}
	return 0;
}

