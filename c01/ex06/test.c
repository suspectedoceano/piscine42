#include<stdio.h>
#include<string.h>
:#include<stdlib.h>

int		ft_strlen(char *);
void	fill_matrix(char **v, int);

int		main()
{
	//2D vector (aka matrix) of 10 pointers to char
	char	*v[10];

	//Fill the vector with random strings
	fill_matrix(v, sizeof(v)/sizeof(v[1]));
	
	//Print the strings and the relative len
	for (int i=0; i<10; i++)
	{
		printf("%s->My functionlen-> %d\n", v[i], ft_strlen(v[i]));	
		printf("%s->from library-> %lu\n\n", v[i], strlen(v[i]));
	}

}


//This function will fill a 2D matrix in the HEAP with random lower_chars
void	fill_matrix(char **v, int size)
{	
	char	*p;
	int		k;	

	for (int i=0; i<size; i++)
	{
		k = 0;
		//for every iteration, p gets a new pointer to char in the heap
		p = (char *)malloc(300);
		v[i] = p;
				//In every slot put a random char, tricky code here	
		while ( (v[i][k++]=rand()%28+97) )
		{
			//123 is my random "sentinel" value to stop the loop
			if (v[i][k-1]==123) 
			{	
				v[i][k-1] = '\0';
				break;
			}
		}
	}
}

int		ft_strlen(char *s)
{
	int		counter;

	counter = 0;
		   //s[counter] is the same thing, with different notation
	while (*(s+counter))++counter;
	return counter;
}

