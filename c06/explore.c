#include<stdio.h>
#include<unistd.h>

int main()
{

	char explorer = '@';
	char *ptrExplorer = &explorer;

	while (1)
	{
		if (*ptrExplorer == '\0')
			write(1, "\n", 1);
		write(1, ptrExplorer++, 1);

	}

}
