#include<stdio.h>
#include<string.h>

int main()
{
	char	buf[10] = {0};

	strcpy(buf, "this will overflow\n");
}
