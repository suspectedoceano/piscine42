#include <stdio.h>

//Print the address of smtg byteByByte

//What a byte really is 👀
typedef unsigned char byte;

int main()
{
	char	*str = "Hello";

	printf("%p\n", str);

	//All the theory in these 2 lines
	//I create a pointer to byte
	//And i assign to it &str
	byte 	*pByte;

	pByte = (byte *)&str;

	for (int i=7; i>=0; --i) printf("%02x", *(pByte+i));

}	
