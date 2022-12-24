#include <stdio.h>

// GOLDEN RULE
//"the name of the array is (decays into) a pointer
// to the first element in the array"




void	foo(char *bar[])
{
	//Here i can!
	//When i pass an array to a function
	//there is a decay
	//*bar[] is **bar
	bar++;
}


int main(int argc, char *argv[])
{
	// type      |<char **>|
	char	**p;


	//type 		|char *(*)[10]|
	//<(*)> 	           pointer to
	//<char *[10]>    10 pointers to char
	char	*p1[10];


	//		MATRIX
	//type char |(*)[10][10]|
	//<(*)>                     pointer to
	//[10][10]      an array of 10 arrays of 10 chars each.
	char 	p2[10][10];


	//cannot increment value of type 'char *[10]'
	//Cannot change the value of array name!
	//	p1++;
	
	foo(p1);

}
