//ц╟ещеепР
#include<stdio.h>
void main()
{
	int i, j, k=0;
	int a[10];
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	for(i=0;i<10;i++)
		for (j = 0; j < 10 - i; j++)
		{
			if (a[i] > a[i + 1])
			{
				k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
			}
		}
	for (i = 0; i < 10; i++)
		printf("%d\t", a[i]);
}