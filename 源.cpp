//иоб╔лщ
#include<stdio.h>
#include<stdlib.h>
int dpSeq(int n)
{
	int* seq = (int*)malloc(sizeof(int) * n);
	seq[0] = 1;
	seq[1] = 2;
	for (int i = 2; i < n; i++)
		seq[i] = seq[i - 1] + seq[i - 2];
	int mid = seq[n - 1];
	free(seq);
	return mid;
}
int stackSeq(int n)
{
	if (1 == n)
		return 1;
	if (2 == n)
		return 2;
	return stackSeq(n - 1) + stackSeq(n - 2);
}
int main(int argc, char const* argv[])
{
	printf("stack:%d\n", stackSeq(20));
	printf("%DP:%d\n", dpSeq(20));
	return 0;
}