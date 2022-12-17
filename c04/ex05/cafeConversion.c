#include<stdio.h>

int		ft_pow(int base, int pow)
{
/*	int		counter;

	counter = 1;
	while (pow--)
		counter *= base;
	return counter;	
*/	
	
	//  RECURSIVE POWER
	  if (0 == pow)
	      return 1;
	  return ft_pow(base, pow - 1) * base;
	  		
	
}



int	 	realValue(char *nbr, char *symbols, int baseValue, int digitPosition, int sign) 
{
	//E.G.
	//nbr-> "cafe"
	//symbols-> "0123456789abcdef"
	//BaseValue-> 16
	//			                	  3 | 2 | 1 | 0	
	//digitPosition->   We start at-> c | a | f | e   


	//i will be the value of the symbol in position 0
	int 	i;

	i = 0;


	//🎩 Recursion magic 🎩
	//							   ⬇︎⬇︎
	//					3 | 2 | 1 | 0 
	//BASE CASE returns c | a | f | e  
   	if (digitPosition == 0)
	{
		//Search for your symbol value 
		while (*nbr != *(symbols + i))
			++i;
		return i * sign;
	}

	//RECURSIVE CASE
	else 
	{
		while (*nbr != *(symbols + i))														//  Base powers
			++i;																			// 4096	256	16	1
																							//          ⬇︎⬇︎
		//😅👀🎩 WTF crazy Recursion here_____________________________________	 ___   i	     3 | 2 | 1 | 0________________
		//	  |			BASE CASE return value->  14						  |+| symbolValue *  c | a | f | e     *  +|-|    |	       
		return realValue(nbr + 1, symbols, baseValue, digitPosition - 1, sign) + (i * ft_pow(baseValue, digitPosition) * sign);
		//	  |_______________________________________________________________| |_____________________________________________|	
	}
}


 // gcc cafeConversion.c && ./a.out "10" "01"
 

int main(int argc, char **argv)
{
	char	*nbr = argv[1];
	char 	*base = argv[2]; 
	int		len = 0;
	int 	baseValue = 0;
	int 	sign = 1;


	//Skip all + | -, keep track of -
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		++nbr;
	}

	//Magnitude of the number
	while (*(nbr + len))
		++len;

	//Get the baseValue 
	while (*(base + baseValue))			//		| 3| 2| 1| 0|
		baseValue++;					//		  c  a  f  e	
										//		   len-1	
										//Position of most significant digit
	printf("%d\n", realValue(nbr, base, baseValue, len-1, sign));	
}
