#include <stdio.h>


/*
 * 1)
 * PROGRAM TO WRITE THE ADDRESS IN HEX
 * ~The hexadecimal address of the first line’s first character
*/



//Byte data type
typedef unsigned char byte_t;



//Prototypes
void printByteHex1(byte_t);
void printByteHex2(byte_t);
void printAddressHex(void *);




int main()
{
	char	str[] = "Hello";

	printf("%p\n", str);
	
	printAddressHex((void *)str);
}






void	printAddressHex(void *s)
{
	//Key point 👀. Super attention here.
	byte_t		*ptrByte;

	//&s is a pointer to a pointer
	ptrByte = (byte_t *)&s;


	//I start from 7 cause LITTLE ENDIAN
	for (int i=7; i>=0; --i)
	{
		printf("Byte %d-> ", i);
		
		//Routine print byteByByte in Hex
		printByteHex2(*(ptrByte+i));

		printf("\n");
	}
}







//Easier implementation
//Here i need typedef->byte abstrasction
//Cause i work with VALUES
void	printByteHex1(byte_t Byte)
{
	if ((Byte / 16) < 10)
		printf("%c", (48 + (Byte / 16)));
	else
		printf("%c", (87 + (Byte / 16)));
	if ((Byte % 16) < 10)
		printf("%c", (48 + (Byte % 16)));
	else
		printf("%c", (87 + (Byte % 16)));
}








//Bitwise implementation
//Here i don't necessary need typedef->byte
//Cause i work with bits...
void	printByteHex2(byte_t Byte)
{
	int		_4_Upper_bits;
	int		_4_Lower_bits;
	
	//Most significant 4 bits, shift operator-> /16.
	_4_Upper_bits = (Byte & 0b11110000) >> 4;

	if (_4_Upper_bits < 10)
		printf("%c", (48 + _4_Upper_bits));
	else
		printf("%c", (87 + _4_Upper_bits));

	//Least significant 4 bits
	_4_Lower_bits = Byte & 0b00001111;

	if (_4_Lower_bits < 10)
		printf("%c", (48 + _4_Lower_bits));
	else
		printf("%c", (87 + _4_Lower_bits));
}

