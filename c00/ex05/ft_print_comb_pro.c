#include <unistd.h>
#include <stdio.h>

//NEW APPROACH

void	pc()
{
	char	v[] = {'0','1','2'};
	char	v1[] = {'7','8','9'};
	int 	limit = 2;
	int		sentinelPosition;
	int		copy_sentinel;

	while (v[0] <= v1[0])
	{	
		for(int i=0;i<3;++i)printf("%c",v[i]);
		if (v[0] == '7' && v[1] == '8' && v[2] == '9')
			printf(".\n");
		else 
			printf(", ");

		sentinelPosition = limit;
		//Find the value to increase
		while(v[sentinelPosition] == v1[sentinelPosition] )
			sentinelPosition--;

		copy_sentinel = ++(v[sentinelPosition]);
		while( sentinelPosition<=limit )
			v[++sentinelPosition] = ++copy_sentinel;
	}
}

int main()
{
	pc();
}
