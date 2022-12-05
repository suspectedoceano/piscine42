#include <stdio.h>


int main()
{
	int				n;
	unsigned long	pn;
	int				*ptrn;


	n = 42;
	pn = &n;
	ptrn = &n;

	printf("%lx \n%lx \n", pn, ptrn);


}
