#include <unistd.h>

/*
    • Create a function that displays the memory area onscreen.

	youtube explanation-> https://youtu.be/2vk6E0Q79-E
								//
	BIG BOY PROGRAM HERE, 💡DIVIDE AND CONQUER APPROACH💡

	• The display of this memory area should be split into three "columns" separated by a space :
	1)	◦ The hexadecimal address of the first line’s first character followed by a ’:’.
	2)	◦ The content in hexadecimal with a space each 2 characters and should be padded with spaces if needed.
	3)	◦ The content in printable characters.

	CONSTRAINTS
	• If a character is non-printable, it’ll be replaced by a dot.
	
	• Each line should handle sixteen characters.
		◦Should i truncate if more? 
	
	• If size equals to 0, nothing should be displayed
		◦Empty string has size 1!--> \0 char
*/



//Wait but..a byte is just an unsigned char...💡
typedef unsigned char byte_t;



//Prototypes, only data type needed 👀
void	printAddressHex(void *);
void	byteInHex(byte_t);
void	printContentHex(void *, unsigned int);
void	printContentDot(void *, unsigned int);
void	*ft_print_memory(void *, unsigned int);
void 	ft_putchar(char c);



int 	main()
{
	//This string has size 1 and len 0 🤷
	//If size equals to 0, nothing should be displayed
	char	empty[] = "";
	
//	char	longStr[] = "This string contains more than 16 chars";

	char	str[] = "Bonjour les amin----";
	char	str1[] = "ches\t\n\tc  est fo----";
	char	str2[] = "u\ttout\tce qu on ----";
	char	str3[] = "peut faire avec\t----";
	char	str4[] = "\n\tprint_memory\n\n----";
	char 	str5[] = "\n\tlol.lol\n \0";

//	printf("Main->%p\n", empty);
	ft_print_memory((void *)empty, sizeof(empty));

//	printf("Main->%p\n", longStr);
//	ft_print_memory((void *)longStr, sizeof(longStr));

//	printf("\n\n%p<-Main\n", str);
//	printf("%p<-Return\n\n\n",ft_print_memory((void *)str, sizeof(str)));
	ft_print_memory((void *)str, sizeof(str));

//	printf("Main->%p\n", str1);
	ft_print_memory((void *)str1, sizeof(str1));

//	printf("Main->%p\n", str2);
	ft_print_memory((void *)str2, sizeof(str2));

//	printf("Main->%p\n", str3);
	ft_print_memory((void *)str3, sizeof(str3));

//	printf("Main->%p\n", str4);
	ft_print_memory((void *)str4, sizeof(str4));

//	printf("Main->%p\n", str5);
	ft_print_memory((void *)str5, sizeof(str5));
}



void	ft_putchar(char c)
{
	write(1, &c, 1);
}





void	*ft_print_memory(void *addr, unsigned int size)
{
	//If size equals to 0, nothing should be displayed
	//I assume they talk bout an empty string "", of size 1
	if (size == 1)
		return (addr);

	//DIVIDE AND CONQUER
	//1) Print the address in hexadecimal
	printAddressHex(addr); //Ok
						  
	//2) Print the content in hexadecimal
	printContentHex(addr, size); //Ok

	//3) Print the string, dots if NonPrintable
	printContentDot(addr, size); //Ok

	return (addr);
}






//Piece of code able to print in hex 
//a byte. 2 different implementations 
//of the same function

void	byteInHex(byte_t Byte)
{
///*
	int		_4_Upper_bits;
	int		_4_Lower_bits;

	_4_Upper_bits = (Byte & 0b11110000) >> 4;
	if (_4_Upper_bits > 9)
		ft_putchar(_4_Upper_bits + 87);
	else 
		ft_putchar(_4_Upper_bits + 48);
	_4_Lower_bits = Byte & 0b00001111;
	if (_4_Lower_bits > 9)
		ft_putchar(_4_Lower_bits + 87);
	else 
		ft_putchar(_4_Lower_bits + 48);				
//*/

//Second implementation
/*	
	if ((Byte / 16) < 10)
		ft_putchar(48 + (Byte / 16));
	else
		ft_putchar(87 + (Byte / 16));
	if ((Byte % 16) < 10)
		ft_putchar(48 + (Byte % 16));
	else
		ft_putchar(87 + (Byte % 16));	
*/
}




// 1) Print the address in Hex
void	printAddressHex(void *addr)
{
	byte_t	*ptrByte;
	int 	littleEndian;
		
	littleEndian = 7;
	//🚨 Super attention here 🚨
	ptrByte = (byte_t *) &addr;
	while (littleEndian >= 0)
	{
		byteInHex(*(ptrByte + littleEndian));
		--littleEndian;
	}
	ft_putchar(':');
}



// 2) Print the content in hex
void	 printContentHex(void *str, unsigned int size)
{
	int		i;
	short	limit;

	//Each line should handle sixteen characters
	limit = 16;
	i = 0;
	while (--size && limit--)
	{
		//Toggle effect, interleaved space
		if (!(i % 2))	
			write(1, " ", 1);
					//Attention 👀
		byteInHex(*((byte_t *)str));
		++str;
		++i;
	}	
	//padding with spaces
	if (i % 2)
		write(1, "  ", 2);
	else 
		write(1, " ", 1);
}




// 3) Print the string itself with dots for NonPrintable
void	printContentDot(void *str, unsigned int size)
{
	//Each line should handle sixteen characters
	short	limit;

	limit = 16;
	while (--size && limit--)
	{	
		//Is char printable???
		if (*(char *)str >= 32 && *(char *)str < 127)
			write(1, str, 1);
		else 
			write(1, ".", 1);
		++str;
	}	
	write(1, "\n", 1);
}


