#include <stdio.h>


int counter = 0;


void 	naruto(char *s)
{

//	  8 7 6 5 4 3 2 1 0
//	| 0 0 0 0 0 0 0 0 0 |
//		  . . . .
//		  . . . .
//	| 1 1 1 1 1 1 1 1 \0|

	if (!*s)
	{
		//Base naruto PRINTA 256 volte
		printf("\n\n%d-> %s\n",counter++, s-8);
	}
	else 
	{

		for (int i = 0; i < 26; i++)
		{
			*s = 97 + i;
			if (*(s - 1) < *s) naruto(s + 1); //Printa
		}
	}
	
}

int main()
{
	char v[9] = {v[8] = 0};

	for(int i=0; i<8; i++)v[i] = 48;
	
	naruto(v);	

}
