#include <ctype.h>
#include <stdio.h>

int main()
{
	//All the alpha chars
	for (int i=0; i<128; ++i)
		printf("%d %c-> %s\n\n",
				i, i , isalpha(i) ? "This is an alpha char" : "Not alpha char");
}
