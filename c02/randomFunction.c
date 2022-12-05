#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	//Seed rand, this is gonna make the rand function change outputs at every program launch
	srand(time(NULL));
	for (int i=0; i<100; ++i)
		printf("%d ", rand()%101);
}
