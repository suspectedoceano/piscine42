#include <stdio.h>
#include <limits.h>

typedef unsigned char byte;


int main()
{	
	int nb = INT_MIN;
	//long nbLong = nb;
	byte	*ptrByte;	

	ptrByte = (byte *)&nb;
	//nbLong = -nbLong;

	for (int i=7; i >= 0; --i)
	{
		for (int j=7; j >=0 ; --j)
			printf("%d",  (*(ptrByte + i) >> j) & 0b00000001);		
		printf("\n");
	}
	printf("%d\n", nb);

}
