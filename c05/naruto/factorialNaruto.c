#include<stdio.h>


unsigned long long		narutoFact(int n)
{
	if (n == 0)

			return 1;

	else

			return narutoFact(n-1) * n;
	
}


int main()
{
	for (int i=0; i<21; ++i) printf("Factorial %d->%llu\n",i, narutoFact(i));
}
