#include <stdio.h>

/*
 * 2)
 * The content in hexadecimal with a space each 2 characters
 * and should be padded with spaces if needed
*/

typedef unsigned char byte_t;


void	printByteHex(byte_t Byte)
{
/*	if ((Byte / 16) < 10)
		printf("%c", (48 + (Byte / 16)));
	else
		printf("%c", (87 + (Byte / 16)));
	if ((Byte % 16) < 10)
		printf("%c", (48 + (Byte % 16)));
	else
		printf("%c", (87 + (Byte % 16)));
*/

	//Butwise implementation
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


void	printStrHex(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		//Toggle effect
		if ( ! (i % 2))
			printf(" ");

		//byte_t non necessary here.
		//Just for consistency
		printByteHex(*( (byte_t *)str + i) );
		++i;
	}	

}


int main()
{
	char	*str = "Hello world how are you";

	printStrHex(str);
}
