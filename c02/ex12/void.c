#include<stdio.h>

int main()
{	
	void	*p;
	
	char	c = 'c';
	p = &c;
	//cannot dereference a generic void *
	printf("%p\n", *p);
}
