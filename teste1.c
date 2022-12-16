#include <stdio.h>
int	fun(int i)
{
	static int l;
	l += i;
	return l;
}

int main()
{
	int a = 4;
	int b =6;
	printf("%d ", fun(a));
	printf("%d ", fun(b));
	return 0;
}
