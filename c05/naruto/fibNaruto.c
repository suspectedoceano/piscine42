#include<stdio.h>

int 	tribNaruto(int n)
{
	if (n == 1 || n == 2)
	
			return 1;

	else if (n == 3)

			return 2;
	
	else
	
	return tribNaruto(n-3)+tribNaruto(n-2)+tribNaruto(n-1);
	

}


int main()
{
	for(int i=1; i<10; i++) printf("%d\n", tribNaruto(i));
}
