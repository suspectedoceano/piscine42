
#include <stdio.h>


//gcc ftPro.c -Wno-incompatible-pointer-types && ./a.out
//Some deep down level stuff

void	print_bytes(int *p)
{
	printf("\nThe address INSIDE my variable pointer, namely the address of the variable n from ft_ft:\n"
			"\n\t\t0x%016lx\n\n", (unsigned long)p);
	unsigned char	*byte;

	byte = &p;
	printf("The full address in binary...good luck to read it...\n");
	for (int i=0; i<8; ++i)
	{
		for (int j=7; j>=4; --j)
			printf("%d", *(byte + i) >> j & 1);	
		for (int j=3; j>=0; --j)
			printf("%d", *(byte + i) >> j & 1);	
	}
	printf("\n\nLITTLE ENDIAN\n\n");
	for (int i=0; i<8; ++i)
	{
		printf("%d Byte-> ", i);
		for (int j=7; j>=4; --j)
			printf("%d", *(byte + i) >> j & 1);	
		printf("  ");
		for (int j=3; j>=0; --j)
			printf("%d", *(byte + i) >> j & 1);	
		printf("\n");
	}
	printf("\n");
		int 	bias;

	bias = 7;
	printf("\n\nBIG ENDIAN\n");
	for (int i=7; i>=0; --i)
	{
		printf("%d Byte-> ", bias-i);
		for (int j=7; j>=4; --j)
			printf("%d", *(byte + i) >> j & 1);	
		printf("  ");
		for (int j=3; j>=0; --j)
			printf("%d", *(byte + i) >> j & 1);	
		printf("\n");
	}
}


void	ft_ft(int *nbr)
{
	print_bytes(nbr);
	*nbr = 42;
	printf("\nThe value of n %d\n", *nbr);
}


int	main()
{
	int	n;

	printf("\nThe address of n from main\n\n\t\t0x%016lx\n\n", (unsigned long)&n);
	printf("The size of this dude is %lu bytes.\n", sizeof(&n));
	ft_ft(&n);
}
