#include <stdio.h>
#include <math.h>

int counter = 0;

void	helper(char *s, char *v)
{

	if (!*v)
	{
		//						 ⬇︎
		// | ? | ? | ? | ? | ? | \0 |
		counter++;
		printf("\t\t\t| %d -> %s |\n",counter, v-5);

		if (counter == pow(5, 5)) printf("\n5 ^ 5-> %.0f is the number of possible permutations. "
				"This program doesn't take into account double letters\n", pow(5, 5));
	}
	else 
	{
		/*
		 * What are the choices?
		 * ~All the chars in s.
		 *
		 *
		 *					⬇︎
		 * | j | a | l | a | l | \0 |
		*/
		for (int i = 0; i < 5; ++i)
		{
			char c = *(s + i);
			*v = c;
			helper(s, v + 1); //Print 
		}

	}

}



void perm(char *s)
{
	char 	v[6] = {v[5] = 0};
	for (int i=0; i<5; i++)v[i] = '?';
	helper(s, v);
}




int main()
{
	perm("hello");
}
