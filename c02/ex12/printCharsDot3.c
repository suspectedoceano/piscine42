#include <unistd.h>
#include <string.h>


/*
	The content in printable characters.
	If a character is non-printable, it’ll be replaced by a dot.
*/


int main()
{
	char	str[] = "Bonjour\nles amis\t\a\b\v\n, comment ca va oujourdui?";
	short 	size;
	short	i;

	i = 0;
	size = sizeof(str);
	while (size--)
	{	
		if (*(str+i) < 32 || *(str+i) == 127)
			write(1, ".", 1);
		else
			write(1, str+i, 1);
		++i;
	}
}
	


