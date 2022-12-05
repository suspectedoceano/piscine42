#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main()
{

	//Buffered output concept
	printf("Print");
	for (int i=0; i<5; ++i) ft_putchar('h');
	write(1, "write", 5);
	sleep(5);

}
