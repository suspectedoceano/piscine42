#include <stdio.h>
#include <unistd.h>

int main()
{
///*
	//This is a READ ONLY string
	char	*s = "U cannot change me, loser ;(";
	
	puts(s);
	//Illegal
	//s[1] = '!';
	printf("%p\n\n", s);	
	sleep(10);

//*/
	
	//This i can change
	char	v[] = "Damn OS, why u don't protect me... :(";		
	
	puts(v);
	//Legal
	v[1] = '!';
	puts(v);

}	
