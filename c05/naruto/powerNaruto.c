#include <stdio.h>


int		narutoPower(int base, int pow)
{
	if (pow == 0)
		
			return 1;

	else if (pow == 1)
		
			return base;

	else

			return narutoPower(base, pow - 1) * base;


}



int main()
{
	for (int i=0; i<32; ++i)printf("%d\n",narutoPower(2, i));
}
