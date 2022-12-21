#include <stdio.h>

int counter = 0;

void	diceRoll(int dices, char *v, int sum)
{
	if (!dices)
	{
		int total = 0;

		for (int i=0; i<2; i++)
			total += (*((v-2)+i) - 48);


		if (total == sum)counter++, printf("%d-> %s\n",counter, v-2);

		total = 0;
	}
	else
	{
		for (int i=1; i<=6; i++)
		{
			*v = i+48;
		   	diceRoll(dices - 1, v+1, sum);
		}


	}	


}



int main()
{
	char		v[6] = {0};
	diceRoll(2, v, 7);

}
